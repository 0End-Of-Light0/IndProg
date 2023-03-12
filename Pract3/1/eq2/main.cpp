#include "eq2.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cout << "Bedite argument dlya 1 yravnenya: " << "\n";
	cin >> a >> b >> c;
	eq2 a1(a, b, c);
	eq2 a2(-3, 2, 1);
	eq2 a3;

	a3 = a1 + a2;

	cout << "Reshenye 1 yravnenya -> " << a1.find_X() << "\n";
	cout << "Reshenye 2 yravnenya  -> " << a2.find_X() << "\n";
	cout << "Reshenye 3 yravnenya -> " << a3.find_X() << "\n";

	double ARG = 10;

	cout << "Znach 1 yravnenya pri  X = " << ARG << " -> " << a1.find_Y(ARG) << "\n";
	cout << "Znach 2 yravnenya pri  X = " << ARG << " -> " << a2.find_Y(ARG) << "\n";
	cout << "Znach 3 yravnenya pri X = " << ARG << " -> " << a3.find_Y(ARG) << "\n";

	return 0;
}