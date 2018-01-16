//
// Created by jeevan on 6/18/17.
//

//
// Created by jeevan on 6/10/17.
//
#include <iostream>

#define maximumSize 10
using namespace std;

struct Node {
    int info, next;
};

class queue {
private:
    Node node[maximumSize];
    int avail;
    int rear, front;
public:
    queue(int n = 0) {
        avail = 0;
        rear = 0;
        front = -1;
    }

    int getnode() {
        int p = avail;
        avail = node[avail].next;
        return p;
    }

    void freenode(int p){
        node[p].next =avail;
        avail = p;
    }
    void insert(int x) {
        int p;
        p = getnode();
        node[p].info = x;
        node[p].next = -1;
        if (rear == -1)
            front = p;
        else
            node[rear].next = p;
        rear = p;
    }

    int remove() {
        int p, x;
        p = front;
        x = node[p].info;
        front = node[p].next;
        if (front == -1)
            rear = -1;
        freenode(p);
        return (x);
    }
};

int main() {
}