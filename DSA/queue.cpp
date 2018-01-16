#include <iostream>

template<class T>
class queue {
private:
    T *data;
    int front, rear, maxSize;

public:
    queue() {
        data = new T[10];
        front = 0;
        rear = -1;
    }

    void enQueue(T val) {
        if (rear == maxSize - 1) {
            std::cout << "Queue Overloaded";
            exit(0);
        }
        data[++rear] = val;
    }

    T deQueue() {
        if (rear >= front)
            return data[front++];
        std::cout << "Queue Underloaded";
        exit(0);
    }
};
