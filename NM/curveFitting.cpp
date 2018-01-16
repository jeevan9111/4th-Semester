//
// Created by jeevan on 5/29/17.
//

#include <iostream>
#include <cmath>

using namespace std;
int n;
double *global_array;

double sum(double *a, double *b = global_array) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

int main() {
    cout << "Enter the no of Data you want to type :\t";
    cin >> n;

    double *x = new double[n];
    double *y = new double[n];
    double *Y = new double[n];
    global_array = new double[n];

    cout << "Enter your data:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x\t=\t";
        cin >> x[i];
        cout << "y\t=\t";
        cin >> y[i];
        Y[i] = log(y[i]);
        global_array[i] =1;
    }

    double a = 1 / (sum(x) * sum(x) - n * sum(x, x)) * (sum(x) * sum(y) - n * sum(x, y));
    double b = 1 / (sum(x) * sum(x) - n * sum(x, x)) * (-sum(x, x) * sum(y) + sum(x) * sum(x, y));

    double d = 1 / (sum(x) * sum(x) - n * sum(x, x)) * (sum(x) * sum(Y) - n * sum(x, Y));
    double c = exp(1 / (sum(x) * sum(x) - n * sum(x, x)) * (-sum(x, x) * sum(Y) + sum(x) * sum(x, Y)));

    cout << " y = " << a << " x + " << b << endl;
    cout << " y = " << c << " e ^ ( " << d << "x )";

    delete[] x;
    delete[] y;
    delete[] Y;
    delete[] global_array;
    return 0;
}