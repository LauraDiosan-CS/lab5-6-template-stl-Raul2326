#include "Service.h"

Service::Service() {
}

Service::Service(RepoFileP& P, RepoFileM& M)
{
	this->P = P;
	this->M = M;
}

Service::~Service() {
}

void Service::setRepo(RepoFileP& P, RepoFileM& M)
{
	this->P = P;
	this->M = M;
}

int Service::Add(int code, char* name, int price, int amount) {
	if (price < 0) {
		return -1;
	}
	if (amount < 1) {
		return -1;
	}
	Product e(code, name, price, amount);
	P.Add(e);
	return 0;
}

int Service::AddM(int sum) {
	if (sum != 1 && sum != 5 && sum != 10) {
		return -1;
	}
	M.Add(Bill(sum));
	return 0;
}

int Service::Delete(int code, char* name, int price, int amount) {
	Product p(code, name, price, amount);
	int poz = P.getPoz(p);
	if (poz < 0 || poz > P.getSize()) {
		return -1;
	}
	P.Delete(poz, p);
	return 0;
}

int Service::DeleteM(int sum) {
	Bill b(sum);
	int poz = M.getPoz(b);
	if (poz < 0 || poz > M.getSize()) {
		return -1;
	}
	M.Delete(poz, b);
	return 0;
}

int Service::Update(int poz, int code, char* name, int price, int amount) {
	if (price < 0) {
		return -1;
	}
	Product p1(code, name, price, amount);
	P.Update(poz, p1);
	return 0;
}

int Service::UpdateM(int poz, int sum) {
	if (sum != 1 && sum != 5 && sum != 10 && sum != 50 && sum != 100 && sum != 200 && sum != 500) {
		return -1;
	}
	Bill b1(sum);
	M.Update(poz, b1);
	return 0;
}

//------------------------------------------------------------

int Service::getSize() {
	return P.getSize();
}

vector<Product> Service::getAll() {
	return P.getAll();
}

vector<Bill> Service::getAllM() {
	return M.getAll();
}

//------------------------------------------------------------

vector<pair<int, int>> Service::getMoney() {
	vector<Bill> money = getAllM();
	vector<pair<int, int>> all;
	vector<int> s;
	s.push_back(1);
	s.push_back(5);
	s.push_back(10);
	for (int i : s) {
		all.push_back(make_pair(i, count(money.begin(), money.end(), i)));
	}
	return all;
}

int Service::FindProduct(Product p) {
	return P.getPoz(p);
}

int Service::GetPrice(int code) {
	for (Product p : getAll()) {
		if (p.getCode() == code) {
			return p.getPrice();
		}
	}
	return -1;
}

int Service::ValidCode(int code) {
	vector<Product> products = getAll();
	vector<pair<int, int>> codes_amount;
	for (Product p : products) {
		codes_amount.push_back(make_pair(p.getCode(), p.getAmount()));
	}
	for (pair<int, int> p : codes_amount) {
		if (p.first == code && p.second >= 1) {
			return GetPrice(code);
		}
	}
	return -1;
}

void Service::BuyExact(int code, vector<int> money) {
	vector<Product> products = getAll();
	for (Product p : products) {
		if (p.getCode() == code) {
			int poz = FindProduct(p);
			char* name = p.getName();
			int price = p.getPrice();
			int a = p.getAmount() - 1;
			Update(poz, code, name, price, a);
		}
	}
	for (int sum : money) {
		AddM(sum);
	}
}

int Service::CountBill(int sum) {
	vector<Bill> all = getAllM();
	for (Bill b : all) {
		if (b.getSum() == sum) {
			return count(all.begin(), all.end(), sum);
		}
	}
	return -1;
}

vector<int> Service::BuyRest(int code, vector<int> money) {
	int one = CountBill(1);
	int five = CountBill(5);
	int ten = CountBill(10);
	vector<Product> products = getAll();
	vector<int> r;
	int price = 0;
	for (Product p : products) {
		if (p.getCode() == code) {
			price = p.getPrice();
		}
	}
	vector<Bill> bills = getAllM();
	int rest = accumulate(money.begin(), money.end(), 0) - price;
	if (rest < 5 && one >= rest) {
		while (rest != 0) {
			DeleteM(1);
			r.push_back(1);
			rest--;
		}
		BuyExact(code, money);
		return r;
	}
	if (rest == 5 && (five >= 1 || one >= 5)) {
		int ok = 0;
		if (CountBill(5) >= 1) {
			ok = -1;
			DeleteM(5);
			r.push_back(5);
			BuyExact(code, money);
			return r;
		}
		if (ok == 0) {
			while (rest != 0) {
				DeleteM(1);
				r.push_back(1);
				rest--;
			}
			BuyExact(code, money);
			return r;
		}
	}
	if ((5 < rest) && (rest < 10) && ((five >= 1 && one >= rest - 5) || (one == rest))) {
		int ok = 0;
		if (five >= 1 && one >= rest - 5) {
			ok = -1;
			DeleteM(5);
			r.push_back(5);
			rest -= 5;
			while (rest != 0) {
				DeleteM(1);
				r.push_back(1);
				rest--;
			}
			BuyExact(code, money);
			return r;
		}
		if (ok == 0) {
			while (rest != 0) {
				DeleteM(1);
				r.push_back(1);
				rest--;
			}
			BuyExact(code, money);
			return r;
		}
	}
	if (rest == 10 && ((ten >= 1) || (five >= 2) || (five == 1 && one >= 5) || (one >= 10))) {
		int ok = 0;
		if (ten >= 1) {
			ok = -1;
			DeleteM(10);
			r.push_back(10);
			BuyExact(code, money);
			return r;
		}
		if (ok == 0 && (five >= 2)) {
			ok = -1;
			DeleteM(5);
			DeleteM(5);
			r.push_back(5);
			r.push_back(5);
			BuyExact(code, money);
			return r;
		}
		if (ok == 0 && (five == 1 && one >= 5)) {
			ok = -1;
			DeleteM(5);
			r.push_back(5);
			rest -= 5;
			while (rest != 0) {
				DeleteM(1);
				r.push_back(1);
				rest--;
			}
			BuyExact(code, money);
			return r;
		}
		if (ok == -1 && one >= 10) {
			while (rest != 0) {
				DeleteM(1);
				r.push_back(1);
				rest--;
			}
			BuyExact(code, money);
			return r;
		}
	}
	return r;
}

int Service::CountMoney() {
	int money = 0;
	vector<Bill> all = getAllM();
	for (Bill b : all) {
		money += b.getSum();
	}
	return money;
}