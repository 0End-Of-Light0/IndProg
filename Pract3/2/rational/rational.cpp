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
int rational::gcd(int a0, int b0) {
	while (b0 > 0) {
		int c0 = a0 % b0;
		a0 = b0;
		b0 = c0;
	}
	return a0;
}
void rational::show() {
	cout << a << "/" << b;
}