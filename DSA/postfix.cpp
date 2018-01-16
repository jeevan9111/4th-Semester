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
    stack <char> Operator (strlen(a));
    string Postfix;

    for (int i=0;i <= strlen(a);i++) {
        switch (a[i]) {
            case ('/'): case( '*'): case( '+'): case('-'):
                while ((!Operator.is_empty()) && (sign_value(a[i]) <= sign_value(Operator.at_top())))
                    Postfix += Operator.pop();
                Operator.push(a[i]);
                break;
            case ('('):
                Operator.push(a[i]);
                break;
            case (')'):
                while ((!Operator.is_empty()) && (Operator.at_top() != '('))
                    Postfix += Operator.pop();
                Operator.pop();
                break;
            default:
                Postfix += a[i];
        }
    }
    while (!Operator.is_empty())
        Postfix += Operator.pop();
    cout << Postfix;
    delete[](a);
}
