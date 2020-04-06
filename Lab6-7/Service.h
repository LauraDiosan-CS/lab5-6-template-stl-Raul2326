#pragma once
#include <string>
#include <numeric>
#include "Product.h"
#include "Repo.h"
#include "RepoMoney.h"
using namespace std;

class Service {
private:
	Repo R;
	RepoMoney M;
public:
	Service();
	~Service();
	Service(Repo& R, RepoMoney& M);
	void setRepo(Repo R, RepoMoney M);

	int Add(int code, char* name, int price, int amonut);
	int AddM(int sum);
	int Delete(int code, char* name, int price, int amount);
	int DeleteM(int sum);
	int Update(int poz, int code, char* name, int price, int amount);
	int UpdateM(int poz, int sum);
	int getSize();
	vector<Product> getAll();
	vector<Bill> getAllM();

	int FindProduct(Product p);
	vector<pair<int, int>> getMoney();
	int GetPrice(int code);
	int ValidCode(int code);
	void BuyExact(int code, vector<int> money);
	vector<int> BuyRest(int code, vector<int> money);
	int CountBill(int sum);
	int CountMoney();
};
