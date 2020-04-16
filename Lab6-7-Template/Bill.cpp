#include "Bill.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Bill::Bill() {
	this->sum = 0;
}

Bill::Bill(int sum)
{
	this->sum = sum;
}

Bill::Bill(const Bill& b) {
	this->sum = b.sum;
}

int Bill::getSum() {
	return this->sum;
}

void Bill::setSum(int sum) {
	this->sum = sum;
}

Bill& Bill::operator=(const Bill& b) {
	this->setSum(b.sum);
	return *this;
}

bool Bill:: operator==(const Bill& b) {
	return (this->sum == b.sum);
}

ostream& operator<<(ostream& os, const Bill& b)
{
	os << "Sum: " << b.sum;
	return os;
}
