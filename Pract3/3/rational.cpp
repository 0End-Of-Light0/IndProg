#include "rational.h"
#include <cmath>
#include <iostream>

using namespace std;

rational::rational() {
	a = 0;
	b = 0;
}
rational::rational(int a1, int b1) {
	a = a1;
	b = b1;
	while (b == 0) {
		cout << "Can't divided by zero";
		cin >> a;
		cin >> b;
	}
	while (a > b) {
		a = a - b;
	}
	int gcd1 = gcd(abs(a), b);
	if (gcd1 != 1) {
		a = a / gcd1;
		b = b / gcd1;
	}
}
int rational::gcd(int a0, int b0) {
	while (b0 > 0) {
		int c0 = a0 % b0;
		a0 = b0;
		b0 = c0;
	}
	return a0;
}
int  rational::NOK(int a1, int b1) {
	int max; 
	max = (a1 > b1) ? a1 : b1;
	do { 
		if (max % a1 == 0 and max % b1 == 0) {
			return max; 
			break; 
		} 
		else 
			++max; 
	} while (true);

}
void rational::get(int& a1, int& b1)
{
	a1 = a;
	b1 = b;
}
void rational::set(int a1, int b1) {
	a = a1;
	b = b1;
	while (b == 0) {
		cout << "Can't divided by zero";
		cin >> a;
		cin >> b;
	}
	while (a > b) {
		a = a - b;
	}
	int gcd1 = gcd(abs(a), b);
	if (gcd1 != 1) {
		a = a / gcd1;
		b = b / gcd1;
	}
}
void rational::show() {
	cout << a << "/" << b;
}
rational operator + (rational d1, rational d2)
{
	int a1, b1, a2, b2;
	d1.get(a1, b1);
	d2.get(a2, b2);

	int ok = d1.NOK(b1, b2);
	int k1 = ok / b1;
	int k2 = ok / b2;

	int a, b;

	b = ok;

	a = a1 * k1 + a2 * k2;

	rational ans(a, b);

	return ans;

}
rational operator - (rational d1, rational d2)
{
	int a1, b1, a2, b2;
	d1.get(a1, b1);
	d2.get(a2, b2);

	int ok = d1.NOK(b1, b2);
	int k1 = ok / b1;
	int k2 = ok / b2;

	int a, b;

	b = ok;

	a = a1 * k1 - a2 * k2;

	rational ans(a, b);

	return ans;

}
rational& rational::operator ++ ()
{
	a = a + 1;
	set(a, b);

	return *this;
}
bool operator == (rational d1, rational d2)
{
	int a1, b1, a2, b2;
	d1.get(a1, b1);
	d2.get(a2, b2);

	int ok = d1.NOK(b1, b2);
	int k1 = ok / b1;
	int k2 = ok / b2;

	return (a1 * k1 == a2 * k2);

}
bool operator > (rational d1, rational d2)
{
	int a1, b1, a2, b2;
	d1.get(a1, b1);
	d2.get(a2, b2);

	int ok = d1.NOK(b1, b2);
	int k1 = ok / b1;
	int k2 = ok / b2;

	return (a1 * k1 > a2 * k2);
}
