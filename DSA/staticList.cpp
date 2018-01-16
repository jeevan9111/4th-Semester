//
// Created by jeevan on 6/10/17.
//
#include <iostream>

const int maximumSize 10;
using namespace std;

struct Node {
    int info, next;
};

class staticList {
private:
    Node node[maximumSize];
    int listValue;
    int availablePosition;
public:
    staticList(int n = 0) {
        listValue = n;
        availablePosition = 0;
        int i = 0;
        while (i < maximumSize - 1) {
            node[i].next = i + 1;
            node[i].info = NULL;
            i++;
        }
        node[i].next = -1;
    }

    void insertAfter(int value, int position) {
        if (availablePosition == -1) {
            cout << "List Overflow";
            exit(1);
        }
        int insertPosition = availablePosition;
        node[insertPosition].info = value;
        node[insertPosition].next = node[position].next;
        node[position].next = insertPosition;
        availablePosition = node[availablePosition].next;
    }

    int deleteAfter(int position) {
        if (node[position].next == -1) {
            cout << "No data after the position";
            exit(0);
        }
        int deletePosition = node[position].next;
        node[position].next = node[deletePosition].next;
        node[deletePosition].next = availablePosition;
        availablePosition = deletePosition;
        return node[deletePosition].info;
    }

    void peek() {
        int position = 0, i = 0;
        while (node[position].next != -1) {
            cout << node[position].info << endl;
            position = node[position].next;
        }
    }
};

int main() {
    staticList a(0);
    for (int i = 0; i < 5; i++)
        a.insertAfter(10 * i, i);
    a.peek();
}