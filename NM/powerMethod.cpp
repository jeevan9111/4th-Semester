//
// Created by jeevan on 6/23/17.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int OrderOfMatrix;
    cout << "Enter the no of order of Matrix : ";
    cin >> OrderOfMatrix;
    cout << "Enter the Matrix"<<endl;
    double **A = new double *[OrderOfMatrix], *X = new double[OrderOfMatrix], *Y = new double[OrderOfMatrix], k;
    for (int i = 0; i < OrderOfMatrix; i++) {
        A[i] = new double[OrderOfMatrix];
        for (int j = 0; j < OrderOfMatrix; j++)
            cin >> A[i][j];
        X[i] = (i > 1) ? 0 : i;
    }
    bool done = false;
    while (!done) {
        for (int i = 0; i < OrderOfMatrix; i++) {
            for (int j = 0; j < OrderOfMatrix; j++)
                Y[i] = A[i][j] * X[j];
        }

        k = Y[0];
        for (int i = 1; i < OrderOfMatrix; i++)
            k = (abs(k) > abs(Y[i])) ? k : Y[i];

        double *temporaryX = new double[OrderOfMatrix];

        for (int i = 0; i < OrderOfMatrix; i++) {
            temporaryX[i] = X[i];
            temporaryX[i] = abs((X[i] = Y[i] / k) - temporaryX[i]);
        }

        k = temporaryX[0];
        for (int i = 1; i < OrderOfMatrix; i++)
            k = (k > Y[i]) ? k : Y[i];

        if (k < 0.00005)
            done = true;
    }

    cout << k;
    delete[]A;
    delete[]X;
    delete[]Y;
    return 0;
}
