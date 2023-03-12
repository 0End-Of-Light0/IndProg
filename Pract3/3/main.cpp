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

	int i1, i2;

	cout << "\nYkachite dve drobi, dlya ix clojenia(ot 1 do bbedonoi dlini massiva): "; cin >> i1 >> i2; i1 = i1 - 1; i2 = i2 - 1;
	cout << "\n"; (arr[i1]).show(); cout << " + "; (arr[i2]).show(); cout << " = ";
	((arr[i1]) + (arr[i2])).show();
	cout << "\n";

	cout << "\nYkachite dve drobi, dlya vichitanya odnoi is drygoi(ot 1 do bbedonoi dlini massiva): "; cin >> i1 >> i2; i1 = i1 - 1; i2 = i2 - 1;
	cout << "\n"; (arr[i1]).show(); cout << " - "; (arr[i2]).show(); cout << " = ";
	((arr[i1]) - (arr[i2])).show();
	cout << "\n";

	cout << "\nYkasichi drob, dlya dobavlenia 1(ot 1 do bbedonoi dlini massiva): "; cin >> i1; i1 = i1 - 1;
	cout << "\n"; (arr[i1]).show(); cout << "++"; cout << " = ";
	rational xr = arr[i1];
	(++xr).show();
	cout << "\n";

	cout << "\nYkasichite drob, dlya sravnenia(ot 1 do bbedonoi dlini massiva): "; cin >> i1 >> i2; i1 = i1 - 1; i2 = i2 - 1;
	cout << "\n"; (arr[i1]).show(); cout << " == "; (arr[i2]).show();
	if (arr[i1] == arr[i2]) cout << "\nDrobi ravni";
	else cout << "\nDrobi ne ravni";
	cout << "\n";

	cout << "\nYkasichite drob, dlya sravnenia(ot 1 do bbedonoi dlini massiva): "; cin >> i1 >> i2; i1 = i1 - 1; i2 = i2 - 1;
	cout << "\n"; (arr[i1]).show(); cout << " > "; (arr[i2]).show();
	if (arr[i1] > arr[i2]) cout << "\n1 drob bolshe";
	else cout << "\n2 drob bolshe";
	cout << "\n";

	delete[] arr;

	return 0;
}