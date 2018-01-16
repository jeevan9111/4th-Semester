//
// Created by jeevan on 6/3/17.
//
#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x*x;
}

double f_(double x) {
    return 2*x;
}

class ZeroDivisionError{}error;
int main() {
    double x0 = 1;
    try{
        while (abs(f(x0)) > 0.00005) {
            if (f_(x0) < 0.0000005) {
                throw (error);
            }

            x0 -= f(x0) / f_(x0);
        }
    }
    catch(ZeroDivisionError &Error)
    {
        cout << "Zero Division";
        return 0;
    }
    cout << x0;
}
