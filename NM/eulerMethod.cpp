#include <iostream>
#include <cmath>

using namespace std;

double slope(double x, double y) {
    return x;
}

int main() {
    double x0 = 0, y0 = 0, xn = 1, h = 0.5;
    while (x0 <= xn) {
        cout << x0 << '\t' << y0 << endl;
        y0 += h * slope(x0, y0);
        x0 += h;
    }
    return 0;
}