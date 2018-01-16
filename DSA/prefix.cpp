#include <iostream>
#include <cstring>
#include "stack.cpp"

using namespace std;

int sign_value(char sign) {
    switch (sign) {
        case '-':
            return 0;
        case '+':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        default:
            return -1;
    }
}


int main() {
    char *a = new char[10];
    cout << "Enter the expression :\t";
    cin >> a;
    stack<char> Operator(strlen(a));
    string Prefix;

    for (int i = strlen(a) - 1; i >= 0; i--) {
        switch (a[i]) {
            case ('/'):
            case ('*'):
            case ('+'):
            case ('-'):
                while (!(Operator.is_empty() || sign_value(a[i]) > sign_value(Operator.at_top())))
                    Prefix += Operator.pop();
                Operator.push(a[i]);
                break;
            case (')'):
                Operator.push(a[i]);
                break;
            case ('('):
                while (!(Operator.is_empty()) || (Operator.at_top() != ')'))
                    Prefix += Operator.pop();
                Operator.pop();
                break;
            default:
                Prefix += a[i];
        }
    }
    while (!Operator.is_empty())
        Prefix += Operator.pop();
    for (int i = strlen(a) - 1; i >= 0; i--)
        cout << Prefix[i];
    delete[]a;
}
