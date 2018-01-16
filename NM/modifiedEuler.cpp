//
// Created by jeevan on 6/3/17.
//

#include <iostream>
#include <cmath>

using namespace std;

double slope(double x, double y) {
    return x*x;
}

int main() {
    double x0 = 0, y0 = 0, xn = 1, h = 0.5, x1, y1, m, y11;
    while (x0 <= xn) {
        y1 = y0 + h * slope(x0, y0);
        x1 = x0 + h;
        do {
            m = (slope(x0, y0) + slope(x1, y1)) / 2;
            y11 = y1;
            y1 = y0 + h * m;
        } while ((abs(y1 - y11) > 0.00005));
        cout << '\n';
        x0 += h;
        y0 = y1;
    }

    cout << y1;
    return 0;
}