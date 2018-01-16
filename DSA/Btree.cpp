#include <iostream>

using namespace std;

class node {
    int Degree;
    int *Key;// Minimum degree (defines the range for number of keys)
    node **ChildPointers; // An array of child pointers
    int n;     // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false
public:
    node(int _t, bool _leaf);

    void traverse();

    node *search(int k);

    friend class BTree;
};

class Btree {
private:
public:
    void Btree() {

    }

    void insert() {

    }

    int remove() {

    }

    virtual  ~Btree() {

    }
};

int main() {

    return 0;
}