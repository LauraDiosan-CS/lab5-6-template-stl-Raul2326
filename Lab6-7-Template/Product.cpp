#include "Product.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Product::Product() {
	this->code = 0;
	this->name = NULL;
	this->price = 0;
	this->amount = 0;
}

Product::Product(int code, char* name, int price, int amount)
{
	this->code = code;
	this->price = price;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
	this->amount = amount;
}

Product::Product(const Product& p) {
	this->code = p.code;
	this->price = p.price;
	this->name = new char[strlen(p.name) + 1];
	strcpy_s(this->name, 1 + strlen(p.name), p.name);
	this->amount = p.amount;
}

int Product::getCode() {
	return this->code;
}

char* Product::getName() {
	return this->name;
}

int Product::getPrice() {
	return this->price;
}

int Product::getAmount() {
	return this->amount;
}

void Product::setName(char* name)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Product::setCode(int code) {
	this->code = code;
}

void Product::setPrice(int price) {
	this->price = price;
}

void Product::setAmount(int amount) {
	this->amount = amount;
}

Product& Product::operator=(const Product& p) {
	this->setCode(p.code);
	this->setPrice(p.price);
	this->setName(p.name);
	this->setAmount(p.amount);
	return *this;
}

bool Product:: operator==(const Product& p) {
	return (this->code == p.code) && (strcmp(this->name, p.name) == 0) && (this->price == p.price) && (this->amount = p.amount);
}

ostream& operator<<(ostream& os, const Product& p)
{
	os << "Code: " << p.code << " | Name: " << p.name << " | Price: " << p.price << " | Amount: " << p.amount;
	return os;
}
