//
// Created by jeevan on 6/23/17.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return cos(x);
}

int main() {
    double x0 = 0, x1 = 3.1416 / 2, result = 0;
    int no = 100;
    double h = (x1 - x0) / no;
    double x = x0;
    while (x <= x1) {
        result += 1.0 / 2 * (f(x) + f(x + h)) * h;
        x += h;
    }
    cout << "Trapezoidal \t\t:\t" << result << endl;

    int n = (no % 2) ? no + 1 : no;
    result = 0;
    x = x0;
    h = (x1 - x0) / n;
    for (int i = 0; i <= n; i++, x += h)
        result += h / 3 * f(x) * ((i == 0 || i == n) ? 1 : ((i % 2) ? 4 : 2));

    cout << "Simpson's 1/3 rule\t:\t" << result << endl;

    n = (no % 3 == 0) ? no : (no / 3) * 3;
    result = 0;
    x = x0;
    h = (x1 - x0) / n;
    for (int i = 0; i <= n; i++, x += h)
        result += 3 * h / 8 * f(x) * ((i == 0 || i == n) ? 1 : ((i % 3 == 0) ? 2 : 3));

    cout << "Simpson's 3/8 rule\t:\t" << result << endl;
}