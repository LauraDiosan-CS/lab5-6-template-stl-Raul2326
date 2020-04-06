#include<iostream>
#include "RepoMoney.h"

RepoMoney::RepoMoney() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

RepoMoney::RepoMoney(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	this->loadFromFile();
}

RepoMoney::~RepoMoney() {
	this->money.clear();
}

//---------------------------------------------------

void RepoMoney::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

void RepoMoney::setFileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[]this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

void RepoMoney::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		this->money.clear();
		ifstream f(this->fileNameIn);
		int sum;
		while (!f.eof())
		{
			f >> sum;
			if (sum > 0)
			{
				this->Add(Bill(sum));
			}
		}
		f.close();
	}
}

void RepoMoney::saveToFile()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);
		for (int i = 0; i < this->money.size(); i++)
		{
			f << this->money[i] << endl;
		}
		f.close();
	}
}

//---------------------------------------------------

void RepoMoney::Add(Bill b) {
	this->money.push_back(b);
	this->saveToFile();
}

void RepoMoney::Delete(int poz, Bill b) {
	vector<Bill>::iterator it;
	it = find(this->money.begin(), this->money.end(), b);
	if (!(it == this->money.end()))
	{
		this->money.erase(it);
	}
	this->saveToFile();
}

void RepoMoney::Update(int poz, Bill b1) {
	money[poz] = b1;
	this->saveToFile();
}

//---------------------------------------------------

int RepoMoney::getSize() {
	return this->money.size();
}

vector<Bill> RepoMoney::getAll() {
	return this->money;
}

//---------------------------------------------------

int RepoMoney::FindBill(Bill f) {
	for (int i = 0; i < money.size(); i++) {
		if (money[i] == f) {
			return i;
		}
	}
	return -1;
}