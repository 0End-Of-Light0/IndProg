#pragma once
#include <iostream>

using namespace std;

class rational
{
private:
	int a, b;
	int gcd(int a0, int b0);
	int NOK(int a1, int b1);
public:
	rational();
	rational(int a1, int b1);
	void set(int a1, int b1);
	void show();
	void get(int& a1, int& b1);

	friend rational operator - (rational d1, rational d2);
	friend rational operator + (rational d1, rational d2);
	friend bool operator == (rational d1, rational d2);
	friend bool operator > (rational d1, rational d2);
	rational& operator++();
};

