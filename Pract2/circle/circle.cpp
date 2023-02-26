#include "circle.h";
#include "triangle.h";
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

circle::circle(float r, float x, float y){
    radius = r;
    x_center = x;
    y_center = y;
}
void circle::set_circle(float r, float x, float y){
    radius = r;
    x_center = x;
    y_center = y;
}
float circle::square(){
    return M_PI * pow(2, radius);
}
bool circle::triangle_around (float a, float b, float c){
    Triangle tr;

	tr.set(a, b, c);

	float rad = (a * b * c) / (tr.square() * 4);

    return radius == rad;
}
bool circle::triangle_in (float a, float b, float c){
    Triangle tr;

	tr.set(a, b, c);
	
    float rad = tr.square() / ((a + b + c) * 0.5);

    return radius == rad;
}
bool circle::check_circle(float r, float x_cntral, float y_cntral) {
	float cntral_dist = sqrtf(pow(x_center - x_cntral, 2) + pow(y_center - y_cntral, 2));

	return (cntral_dist < (radius + r));
}

