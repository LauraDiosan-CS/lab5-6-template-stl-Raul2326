#pragma once
#include<vector>
#include<fstream>
#include "Product.h"

class Repo {
private:
	vector<Product> products;
	char* fileNameIn;
	char* fileNameOut;
public:
	Repo();
	Repo(const char* fileNameIn, const char* fileNameOut);
	~Repo();

	void setFileNameIn(const char* fileNameIn);
	void setFileNameOut(const char* fileNameIOut);
	void loadFromFile();
	void saveToFile();

	void Add(Product p);
	void Delete(int poz, Product p);
	void Update(int poz, Product p1);

	int getSize();
	vector<Product> getAll();

	int FindProduct(Product f);
};