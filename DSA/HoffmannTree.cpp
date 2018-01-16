//
// Created by jeevan on 7/19/17.
//

#include <iostream>

using namespace std;

class node {
public:
    int Key;
    char Char;
    node *parent;
    node *left;
    node *right;

    node(int key = 0, char Char = 0, node *left = nullptr, node *right = nullptr, node *parent = nullptr) : Key(key),
                                                                                                            Char(Char),
                                                                                                            left(left),
                                                                                                            right(right),
                                                                                                            parent(parent) {}
};

class HoffmannTree {
private:
    node *root;
    int NumberOfData;
    struct data {
        char Character;
        int frequency;
    } *Data;

public:
    HoffmannTree() : root(nullptr) {
        cout << "Enter no of Characters\t: ";
        cin >> NumberOfData;
        Data = new data[NumberOfData];
        cout << "Enter the Characters and frequencies:" << endl;
        for (int i = 0; i < NumberOfData; i++)
            cin >> Data[i].Character >> Data[i].frequency;

        for (int i = 0; i < NumberOfData - 1; i++) {
            for (int j = i + 1; j < NumberOfData; j++) {
                if (Data[i].frequency > Data[j].frequency) {
                    data temp = Data[i];
                    Data[i] = Data[j];
                    Data[j] = temp;
                }
            }
        }
    }

    void makeTree() {
        for (int i = 0; i < NumberOfData; i++) {
            node *right = new node(Data[i].Character);
            node *left = new node(Data[++i].Character);
        }
    }


    virtual ~HoffmannTree() {
    }
};

int main() {
    HoffmannTree a;

}