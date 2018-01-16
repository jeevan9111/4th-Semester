#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
    return x;
}

int main() {
    double x0 = 0, y0 = 0, xn = 1, h = 0.1, y1;
    while (x0 <= xn) {
        double m1 = f(x0, y0);
        double m2 = f(x0 + h / 2, y0 + m1 * h / 2);
        double m3 = f(x0 + h / 2, y0 + m2 * h / 2);
        double m4 = f(x0 + h, y0 + m3 * h);
        y0 += (m1 + 2 * m2 + 2 * m3 + m4) / 6 * h;
        x0 += h;
        cout << x0 << "\t" << y0 << endl;
    }
    return 0;
}