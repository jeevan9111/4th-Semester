//
// Created by jeevan on 5/29/17.
//
#include <iostream>
#include <cmath>

using namespace std;

double function(double x) {
    return exp(x) - 1;
}

int main() {
    double a, b, c;
    cout << "Enter the intervals a and b :\t";
    cin >> a >> b;
    if (function(a) * function(b) > 0) {
        cout << "The interval does not contain any roots inside";
        return 0;
    }

    while (abs(function(c = (a + b) / 2)) > 0.00005 && abs(c - a) > 0.00005)
        (function(c) * function(b) < 0) ? a = c : b = c;

    cout << "The root is :" << c;
    return 0;
}
