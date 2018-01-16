#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y, double z) {
    return cos(x) - x * sin(x);
}

int main() {
    double x0 = 0, y0 = 0, z0 = 0, xn = 1, h = 0.1;
    while (x0 <= xn) {
        double m1, m2, m3, m4, n1, n2, n3, n4;
        m1 = f(x0, y0, n1 = z0);
        m2 = f(x0 + h / 2, y0 + n1 * h / 2, n2 = z0 + m1 * h / 2);
        m3 = f(x0 + h / 2, y0 + n2 * h / 2, n3 = z0 + m2 * h / 2);
        m4 = f(x0 + h, y0 + n3 * h, n4 = z0 +m3 * h);
        cout << x0 << "\t\t" << y0 << "\t\t" << z0 << endl;
        x0 += h;
        z0 += (m1 + 2 * m2 + 2 * m3 + m4) / 6 * h;
        y0 += (n1 + 2 * n2 + 2 * n3 + n4) / 6 * h;
    }
    return 0;
}

