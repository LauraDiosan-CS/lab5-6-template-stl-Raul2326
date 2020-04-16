#pragma once
#include <iostream>
using namespace std;

class Bill {
private:
	int sum;
public:
	Bill();
	Bill(int sum);
	Bill(const Bill& b);
	int getSum();
	void setSum(int sum);
	Bill& operator=(const Bill& b);
	bool operator==(const Bill& b);
	friend ostream& operator<<(ostream& os, const Bill& b);
};
