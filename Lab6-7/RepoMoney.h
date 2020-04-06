#pragma once
#include<vector>
#include<fstream>
#include"Bill.h"

class RepoMoney {
private:
	vector<Bill> money;
	char* fileNameIn;
	char* fileNameOut;
public:
	RepoMoney();
	RepoMoney(const char* fileNameIn, const char* fileNameOut);
	~RepoMoney();

	void setFileNameIn(const char* fileNameIn);
	void setFileNameOut(const char* fileNameIOut);
	void loadFromFile();
	void saveToFile();

	void Add(Bill p);
	void Delete(int poz, Bill b);
	void Update(int poz, Bill b1);

	int getSize();
	vector<Bill> getAll();

	int FindBill(Bill b);
};