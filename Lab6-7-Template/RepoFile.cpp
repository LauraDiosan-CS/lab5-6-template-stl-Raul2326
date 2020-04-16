#include "RepoFile.h"

RepoFileP::RepoFileP() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

RepoFileP::RepoFileP(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	this->loadFromFile();
}

RepoFileP::~RepoFileP() {
}

//----------------------------------------------------------------------------

void RepoFileP::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

void RepoFileP::setFileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[]this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

void RepoFileP::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		this->Repo::items.clear();
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
				this->Repo::Add(Product(code, name, price, amount));
			}
		}
		delete[] name;
		f.close();
	}
}

void RepoFileP::saveToFile()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);
		for (int i = 0; i < this->Repo::items.size(); i++)
		{
			f << this->Repo::items[i] << endl;
		}
		f.close();
	}
}

void RepoFileP::Add(Product p) {
	Repo::Add(p);
	saveToFile();
}

void RepoFileP::Delete(int poz, Product p) {
	Repo::Delete(poz, p);
	saveToFile();
}

void RepoFileP::Update(int poz, Product p) {
	Repo::Update(poz, p);
	saveToFile();
}
//-------------------------------------------------------------------------------------------------------------

RepoFileM::RepoFileM() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

RepoFileM::RepoFileM(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	this->loadFromFile();
}

RepoFileM::~RepoFileM() {
}

//----------------------------------------------------------------------------

void RepoFileM::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

void RepoFileM::setFileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[]this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

void RepoFileM::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		this->Repo::items.clear();
		ifstream f(this->fileNameIn);
		int sum;
		while (!f.eof())
		{
			f >> sum;
			if (sum > 0)
			{
				this->Repo::Add(Bill(sum));
			}
		}
		f.close();
	}
}

void RepoFileM::saveToFile()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);
		for (int i = 0; i < this->Repo::items.size(); i++)
		{
			f << this->Repo::items[i] << endl;
		}
		f.close();
	}
}

void RepoFileM::Add(Bill b) {
	Repo::Add(b);
	saveToFile();
}

void RepoFileM::Delete(int poz, Bill b) {
	Repo::Delete(poz, b);
	saveToFile();
}

void RepoFileM::Update(int poz, Bill b) {
	Repo::Update(poz, b);
	saveToFile();
}
