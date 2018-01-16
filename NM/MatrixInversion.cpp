//
// Created by jeevan on 6/16/17.
//
#include <iostream>

using namespace std;

int main() {
    int num;
    cout << "Enter the number of variables in the equations : ";
    cin >> num;

    double **a = new double *[num], *c = new double[num], *x = new double[num];
    cout << "Enter the coefficients of the variables  and constants :" << endl;
    for (int i = 0; i < num; i++) {
        a[i] = new double[2 * num];
        for (int j = 0; j < num; j++) {
            cin >> a[i][j];
            a[i][j + num] = (i == j) ? 1 : 0;
        }
        cin >> c[i];
    }

    for (int i = 0; i < num; i++) {
        for (int i_ = 0; i_ < num; i_++) {
            if (i_ == i) {
                double denominator = a[i][i];
                for (int j = 0; j < 2 * num; j++)
                    a[i_][j]  /= denominator;
                continue;
            }
            double numerator = a[i_][i];
            for (int j = 0; j < 2 * num; j++)
                a[i_][j]  -= a[i][j] * numerator / a[i][i];
        }
    }

    for (int i = 0; i < num; i++) {
        x[i] = 0;
        for (int j = 0; j < num; j++)
            x[i] += a[i][j + num] * c[j];
        cout << "x" << i << "\t=\t" << x[i] << endl;
    }
    delete[]a[][], x[], c[];
}