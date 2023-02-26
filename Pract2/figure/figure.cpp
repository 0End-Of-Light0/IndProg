#include "figure.h";

#include <iostream>
#include <cmath>

using namespace std;
Figure::Figure(float x1_c, float x2_c, float x3_c, float x4_c, float y1_c, float y2_c, float y3_c, float y4_c) {
	x1 = x1_c;
	x2 = x2_c;
	x3 = x3_c;
	x4 = x4_c;
	y1 = y1_c;
	y2 = y2_c;
	y3 = y3_c;
	y4 = y4_c;

	s1 = pow(x2 - x1, 2) + pow(y2 - y1, 2);
	s2 = pow(x3 - x2, 2) + pow(y3 - y2, 2);
	s3 = pow(x4 - x3, 2) + pow(y4 - y3, 2);
	s4 = pow(x4 - x1, 2) + pow(y4 - y1, 2);
	d1 = pow(x3 - x1, 2) + pow(y3 - y1, 2);
	d2 = pow(x4 - x2, 2) + pow(y4 - y2, 2);
	cos = ((((x3 - x1) * (x4 - x2)) + ((y3 - y1) * (y4 - y2))) / ((sqrt((pow((x1 + x3), 2)) + pow((y1 + y3), 2))) + (sqrt((pow((x2 + x4), 2)) + pow((y2 + y4), 2)))));
	sin = sqrtf(abs(1 - pow(cos, 2)));

	S = abs(d1 * d2 * sin) / 2;
	P = s1 + s2 + s3 + s4;
}
void Figure::show() {
	cout << "Sides: " << s1 << "," << s2 << "," << s3 << "," << s4 << endl;
	cout << "Square: " << S << endl;
	cout << "Perimiter: " << P << endl;

}

bool Figure::is_prug() {
	return (s1 == s3 && s2 == s4 && d1 == d2);
}

bool Figure::is_square() {
	return (s1 == s2 && is_prug());
}

bool Figure::is_romb() {
	return (s1 == s2 == s3 == s4 && !is_square());
}

bool Figure::is_in_circle() {
	float h_p = P / 2;
	float square = sqrt(h_p * (h_p - s1) * (h_p - s2) * (h_p - s3) * (h_p - s4));

	return (S == square);
}

bool Figure::is_out_circle() {
	return (s1 + s3 == s2 + s4);
}