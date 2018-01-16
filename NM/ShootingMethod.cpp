//
// Created by jeevan on 6/23/17.
//

#include <iostream>
#include <cmath>

using namespace std;


double f(double x, double y, double z) {
    return exp(x) - 6 * y + 5 * z;
}

int value(double a, double b, double c, double d) {
    double x0 = a, y0 = b, z0 = c, xn = d, h = 0.1;
    while (x0 <= xn) {
        double m1, m2, m3, m4, n1, n2, n3, n4;
        m1 = f(x0, y0, n1 = z0);
        m2 = f(x0 + h / 2, y0 + n1 * h / 2, n2 = z0 + m1 * h / 2);
        m3 = f(x0 + h / 2, y0 + n2 * h / 2, n3 = z0 + m2 * h / 2);
        m4 = f(x0 + h, y0 + n3 * h, n4 = z0 + m3 * h);
        x0 += h;
        z0 += (m1 + 2 * m2 + 2 * m3 + m4) / 6 * h;
        y0 += (n1 + 2 * n2 + 2 * n3 + n4) / 6 * h;
    }
    return y0;
}

int main() {
    double x1 = 0, y1 = 2.5, x2 = 1, y2 = 28.8337, m1 = 1, m2 = 2, b1 = 0, b2 = 1;
    int i = 0;
    while (i++ < 5) {
        b1 = value(x1, y1, m1, x2);
        b2 = value(x1, y1, m2, x2);
        m1 = m2 - (b2 - y2) / (b2 - b1) * (m2 - m1);
    }
    cout << value(x1, y1, m1, x2);
    return 0;
}