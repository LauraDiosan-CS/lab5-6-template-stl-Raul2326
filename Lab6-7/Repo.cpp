#include<iostream>
#include "Repo.h"

Repo::Repo() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

Repo::Repo(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	this->loadFromFile();
}

Repo::~Repo() {
	this->products.clear();
}

//---------------------------------------------------

void Repo::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

void Repo::setFileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[]this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

void Repo::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		this->products.clear();
		ifstream f(this->fileNameIn);
		int code;
		char* name = new char[20];
		int price;
		int amount;
		while (!f.eof())
		{
			f >> code >> name >> price >> amount;
			if (strlen(name) > 0)
			{
				this->Add(Product(code, name, price, amount));
			}
		}
		delete[] name;
		f.close();
	}
}

void Repo::saveToFile()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);
		for (int i = 0; i < this->products.size(); i++)
		{
			f << this->products[i] << endl;
		}
		f.close();
	}
}

//---------------------------------------------------

void Repo::Add(Product p) {
	this->products.push_back(p);
	this->saveToFile();
}

void Repo::Delete(int poz, Product p) {
	vector<Product>::iterator it;
	it = find(this->products.begin(), this->products.end(), p);
	if (!(it == this->products.end()))
	{
		this->products.erase(it);
	}
	this->saveToFile();
}

void Repo::Update(int poz, Product p1) {
	products[poz] = p1;
	this->saveToFile();
}

//---------------------------------------------------

int Repo::getSize() {
	return this->products.size();
}

vector<Product> Repo::getAll() {
	return this->products;
}

//---------------------------------------------------

int Repo::FindProduct(Product f) {
	for (int i = 0; i < products.size(); i++){
		if (products[i] == f) {
			return i;
		}
	}
	return -1;
}