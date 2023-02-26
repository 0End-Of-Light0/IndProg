#include <iostream>

#include "figure.h"

using namespace std;

int main()
{
    Figure figures[3]{
        Figure(0, 0, 0, 0, 0, 0, 0, 0),
        Figure(0, 0, 0, 0, 0, 0, 0, 0),
        Figure(0, 0, 0, 0, 0, 0, 0, 0)
    };

    float x1_c, x2_c, x3_c, x4_c;
    float y1_c, y2_c, y3_c, y4_c;

    for (int i = 0; i < 3; i++) {
        cout << "Type cords in format (x1  y1), (x2  y2), (x3  y3), (x4  y4) for figure #" << i + 1 << " separated by space: " << endl;
        cin >> x1_c >> y1_c >> x2_c >> y2_c >> x3_c >> y3_c >> x4_c >> y4_c;

        figures[i] = Figure(x1_c, x2_c, x3_c, x4_c, y1_c, y2_c, y3_c, y4_c);
    }

    for (int i = 0; i < 3; i++) {
        figures[i].show();

        cout << "Is prug: " << figures[i].is_prug() << ", "  << ", " << "Is square: " << figures[i].is_square() << "Is romb: " << figures[i].is_romb() << endl;
        cout << "Is in circle:" << figures[i].is_in_circle() << ", " << "Is out circle:" << figures[i].is_out_circle() << endl;
    }
}