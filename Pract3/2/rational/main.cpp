#include "rational.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int sz;
	cout << "Enter size of massive -> "; cin >> sz;
	cout << "\n";
	rational* arr = new rational[sz];
	int a, b;

	for (int i = 0; i < sz; i++)
	{
		cout << "Bidite chislitel i snamenatel cheres probel ras " << i + 1 << " : "; cin >> a >> b;
		(arr[i]).set(a, b);
	}
	cout << "\n";
	for (int i = 0; i < sz; i++)
	{
		cout << "\nDrob nomer " << i + 1 << " : ";
		(arr[i]).show();
	}
	cout << "\n";

	delete[] arr;

	return 0;
}