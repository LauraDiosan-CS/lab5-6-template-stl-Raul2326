#pragma once
#include <vector>
#include <fstream>
#include "Product.h"
#include "Bill.h"
#include "Repo.h"

class RepoFileP : public Repo<Product> {
private:
	char* fileNameIn;
	char* fileNameOut;
public:
	RepoFileP();
	RepoFileP(const char* fileNameIn, const char* fileNameOut);
	~RepoFileP();

	void setFileNameIn(const char* fileNameIn);
	void setFileNameOut(const char* fileNameIOut);
	void loadFromFile();
	void saveToFile();

	void Add(Product p);
	void Delete(int poz, Product p);
	void Update(int poz, Product p);
};