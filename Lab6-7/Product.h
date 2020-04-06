#pragma once
#include <ostream>
using namespace std;

class Product {
private:
	int code;
	char* name;
	int price;
	int amount;
public:
	Product();
	Product(int code, char* name, int price, int amount);
	Product(const Product& p);
	int getCode();
	char* getName();
	int getPrice();
	int getAmount();
	void setCode(int code);
	void setName(char* name);
	void setPrice(int price);
	void setAmount(int amount);

	Product& operator=(const Product& p);
	bool operator==(const Product& p);
	friend ostream& operator<<(ostream& os, const Product& p);
};
