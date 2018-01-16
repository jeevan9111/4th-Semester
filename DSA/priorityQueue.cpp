//
// Created by jeevan on 6/2/17.
//

template<class T>
class PriorityQueue {
private:
    int *data;
    int front, rear;

public:
    PriorityQueue() {
        data = new T[10];
        front = 0;
        rear = 0;
    }

    void insert(int val) {
        data[++rear] = val;
    }

    int maximum() {

    }

    int extractMaximum() {

    }

    void increaseKey(int x, int k) {

    }


    int remove() {
        if (rear != front)
            return data[front++];
    }
};
