//
// Created by jeevan on 7/2/17.
//

#include <iostream>
#include "List.cpp"

using namespace std;


void move(int n, char SourcePeg, char DestinationPeg, char AuxiliaryPeg) {
    if (n == 1) cout << n << "\t" << SourcePeg << "\t" << DestinationPeg << endl;
    else {
        move(n - 1, SourcePeg, AuxiliaryPeg, DestinationPeg);
        cout << n << "\t" << SourcePeg << "\t" << DestinationPeg << endl;
        move(n - 1, AuxiliaryPeg, DestinationPeg, SourcePeg);
    }
}

int main() {
    move(3, 'A', 'C', 'B');
    int a;
    cin >> a;
}