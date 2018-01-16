//
// Created by jeevan on 6/21/17.
//

#include <iostream>

using namespace std;

int main() {
    int no;
    cout << "Enter the number of data you want to enter : ";
    cin >> no;
    cout << "Enter the data given " << endl;

    double *x = new double[no], *y = new double[no], X, Y = 0;

    for (int i = 0; i < no; i++)
        cin >> x[i] >> y[i];

    cout << "Enter the point to calculate the value : ";
    cin >> X;

    for (int i = 0; i < no; i++) {
        double Y_ = 1;
        for (int j = 0; j < no; j++) {
            if (i != j)
                Y_ = Y_ * ((X - x[j]) / (x[i] - x[j]));
        }
        Y = Y + Y_ * y[i];
    }
    cout << Y;

    delete[]x;
    delete[]y;
    return 0;
}