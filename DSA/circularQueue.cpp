#include <iostream>

class circularQueue {
private:
    int *data;
    int front, rear, maxSize;

public:
    circularQueue() : front(0), rear(0), maxSize(10) {
        data = new int[10];
    }

    void enQueue(int val) {
        if (isFull()) {
            std::cout << "Queue Overloaded";
            exit(0);
        }
        data[rear++] = val;
        rear = (rear == maxSize) ? 0 : rear;
    }

    int deQueue() {
        if (isEmpty()) {
            std::cout << "Queue Underloaded";
            exit(0);
        }
        front = (front == maxSize) ? 0 : front;
        return data[front++];
    }

    bool isFull() {
        return bool(rear - front == 9 || front - rear == 1);
    }

    bool isEmpty() {
        if (front == rear) {
            front = 0;
            rear = 0;
            return true;
        }
        return false;
    }
};

int main() {
    using namespace std;
    circularQueue a;
    for (int i = 0; i < 9; i++)
        a.enQueue(i);
    cout << a.deQueue();
}
