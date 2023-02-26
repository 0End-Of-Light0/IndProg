#include "circle.h"

#include <iostream>

using namespace std;

int main()
{
    circle circles[3]{
        circle(0, 0, 0),
        circle(0, 0, 0),
        circle(0, 0, 0)
    };

    float r, x, y;

    for (int i = 0; i < 3; i++) {
        cout << "Enter radius of the circle #" << i + 1 << " and coords of its center (X Y) separated by space: ";

        cin >> r >> x >> y;

        circles[i].set_circle(r, x, y);
    }

    for (int i = 0; i < 3; i++) {
        cout << "Square of circle #" << i+1 << ": " << circles[i].square() << ";" << endl;
        
        float a, b, c;

        cout << "Enter sides for triangle which could be in or out of circle #" << i + 1 << " separated by space: ";
        
        cin >> a >> b >> c;

        cout << "Can given triangle be in: " << circles[i].triangle_in(a, b, c) << "or out: " << circles[i].triangle_around(a, b, c) << ";" << endl;

        float r1, x1, y1;

        cout << "Enter the pos for circle, which could be intersected with current circle: ";

        cin >> r1 >> x1 >> y1;

        cout << "Is given circle intersected with current: " << circles[i].check_circle(r1, x1, y1) << ";" << endl;
    }
}