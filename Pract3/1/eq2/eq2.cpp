#include "eq2.h"
#include <cmath>
#include <iostream>

using namespace std;

eq2::eq2() {
    a = 0; b = 0; c = 0;
    D = 0;
}
eq2::eq2(double a1, double b1, double c1) {
    a = a1; b = b1; c = c1;
    D = b * b - 4 * a * c;
}
void eq2::set(double a1, double b1, double c1) {
    a = a1; b = b1; c = c1;
    D = b * b - 4 * a * c;
}
void eq2::get(double& a1, double& b1, double& c1) {
    a1 = a;
    b1 = b;
    c1 = c;
}
double eq2::find_X() {
    if (D < 0) {
        cout << "Korney net" << endl;
        return 0;
    }
    else {
        if (D == 0) {
            cout << "1 koren: " << endl;
            double x = (-b - sqrt(D)) / (2 * a);
            cout << x << endl;
            return x;
        }
        else {
            cout << "Korney 2, naibolshy: " << endl;
            double x1 = (-b - sqrt(D)) / (2 * a);
            double x2 = (-b + sqrt(D)) / (2 * a);
            if (x1 > x2) {
                cout << x1 << endl;
                return x1;
            }
            else {
                cout << x2 << endl;
                return x2;
            }
        }
    }
}
double eq2::find_Y(double x1) {
    return a * x1 * x1 + b * x1 + c;
}
eq2 operator + (eq2 u1, eq2 u2)
{
    double a1, b1, c1;
    double a2, b2, c2;
    u1.get(a1, b1, c1);
    u2.get(a2, b2, c2);
    eq2 u3(a1 + a2, b1 + b2, c1 + c2);
    return u3;
}