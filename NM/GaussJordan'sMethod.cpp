#include <iostream>

using namespace std;

int main() {
    int num;
    cout << "Enter the number of variables in the equations : ";
    cin >> num;

    double **a = new double *[num];

    cout << "Enter the coefficients of the variables  and constants :" << endl;
    for (int i = 0; i < num; i++) {
        a[i] = new double[num + 1];
        for (int j = 0; j <= num; j++)
            cin >> a[i][j];
    }

    for (int i = 0; i < num; i++) {
        for (int i_ = 0; i_ < num; i_++) {
            if (i_ == i)
                continue;
            double numerator = a[i_][i];
            for (int j = 0; j <= num; j++)
                a[i_][j] = a[i_][j] - a[i][j] * numerator / a[i][i];
        }
    }
    for (int i = 0; i < num; i++)
        cout << "x" << i << "\t=\t" << a[i][num] / a[i][i] << endl;
    delete a[][];
}