//
// Created by jeevan on 6/21/17.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int NumberOfData, DegreeOfPolynomial, OrderOfMatrix;

    cout << "Enter the degree of polynomial you want to make : ";
    cin >> DegreeOfPolynomial;
    OrderOfMatrix = DegreeOfPolynomial + 1;

    double *ContentsOfMatrix = new double[2 * OrderOfMatrix - 2], **Matrix = new double *[OrderOfMatrix], *C = new double[OrderOfMatrix];

    cout << "Enter the no of data you want to enter : ";
    cin >> NumberOfData;
    cout << "Enter the Data :" << endl;
    double *x = new double[NumberOfData], *y = new double[NumberOfData];
    for (int i = 0; i < NumberOfData; i++)
        cin >> x[i] >> y[i];

    for (int i = 0; i < (2 * OrderOfMatrix); i++) {
        ContentsOfMatrix[i] = 0;
        for (int j = 0; j < NumberOfData; j++)
            ContentsOfMatrix[i] += pow(x[j], i);
    }

    for (int i = 0; i < OrderOfMatrix; i++) {
        Matrix[i] = new double[2 * OrderOfMatrix];
        for (int j = 0; j < OrderOfMatrix; j++) {
            Matrix[i][j] = ContentsOfMatrix[i + j];
            Matrix[i][j + OrderOfMatrix] = (i == j) ? 1 : 0;
        }
        C[i] = 0;
        for (int k = 0; k < NumberOfData; k++)
            C[i] += pow(x[k], i) * y[k];
    }

    for (int i = 0; i < OrderOfMatrix; i++) {
        for (int i_ = 0; i_ < OrderOfMatrix; i_++) {
            if (i_ == i) {
                double denominator = Matrix[i][i];
                for (int j = 0; j < 2 * OrderOfMatrix; j++)
                    Matrix[i_][j] /= denominator;
                continue;
            }
            double numerator = Matrix[i_][i];
            for (int j = 0; j < 2 * OrderOfMatrix; j++)
                Matrix[i_][j] -= Matrix[i][j] * numerator / Matrix[i][i];
        }
    }

    for (int i = 0; i < OrderOfMatrix; i++) {
        x[i] = 0;
        for (int j = 0; j < OrderOfMatrix; j++)
            x[i] += Matrix[i][j + OrderOfMatrix] * C[j];
        cout << "a" << i << "\t=\t" << x[i] << endl;
    }
    delete[]x;
    delete[]y;
    delete[]ContentsOfMatrix;
    delete[]Matrix;
    delete[]C;
    return 0;
}