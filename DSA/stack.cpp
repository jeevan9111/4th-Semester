//
// Created by jeevan on 5/27/17.
//

#include <iostream>

using namespace std;

template<class T>
class stack {
private:
    T *data;
    unsigned int maxsize;
    int top;

public:
    stack() {
        top = -1;
        cout << "Set the maximum size of Stack : ";
        cin >> maxsize;
        data = new T[maxsize];
    }

    stack(int a) {
        top = -1;
        maxsize = (unsigned int) a;
        data = new T[maxsize];
    };

    void push(T a) {
        if (top == (maxsize - 1))
            cout << "The Stack is full";
        else
            data[++top] = a;
    }

    T pop() {
        if (is_empty()) {
            cout << "The Stack is empty";
            return 0;
        } else {
            return data[top--];
        }

    }

    bool is_empty() {
        return (top == -1);
    }


    T at_top() {
        return data[top];
    }

    virtual  ~stack() {
        delete data;
    }
};


