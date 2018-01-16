//
// Created by jeevan on 6/10/17.
//
#include <iostream>

using namespace std;

class node {

public:
    int info;
    node *next;

    node(int b = 0, node *c = nullptr) : info(b), next(c) {}
};


class List {
protected:
    node *list;
public:
    List() : list(nullptr) {}

    void insertAtBeginning(int value) {
        node *newNode = new node(value, list);
        list = newNode;
    }

    void insertAtEnd(int value) {
        if (list == nullptr)
            insertAtBeginning(value);
        else
            insertAtEnd(list, value);
    }

    node *insertAtEnd(node *a, int value) {
        if (a->next == nullptr)
            a->next = new node(value, nullptr);
        else
            a->next = insertAtEnd(a->next, value);
        return a;
    }

    void insertAt(int position, int value) {
        node *target = list;
        node *preTarget = nullptr;
        for (int i = 0; i++ < position && target != nullptr; target = (preTarget = target)->next);
        if (target == nullptr)
            insertAtEnd(value);
        else if (preTarget == nullptr)
            insertAtBeginning(value);
        else
            preTarget->next = new node(value, target);
    }

    int deleteAtBeginning() {
        if (list != nullptr) {
            node *beginning = list;
            int data = beginning->info;
            list = list->next;
            delete[] beginning;
            return data;
        }
    }

    int deleteAtEnd() {
        if (list == nullptr)
            deleteAtBeginning();
        else
            deleteAtEnd(list);
    }

    node *deleteAtEnd(node *target) {
        if (target->next == nullptr) {
            delete[]target;
            return nullptr;
        }
        else
            target->next = deleteAtEnd(target->next);
        return target;
    }

    int deleteAt(int position) {
        if (position != 0) {
            node *target = list;
            node *preTarget = nullptr;
            for (int i = 0; i++ < position && target != nullptr; target = (preTarget = target)->next);
            if (target != nullptr) {
                int data = target->info;
                preTarget->next = target->next;
                delete[] target;
                return data;
            }
        } else
            deleteAtBeginning();
    }

    void peek() {
        node *peeker = list;
        cout << "List = [";
        while (peeker != nullptr) {
            cout << peeker->info << ", ";
            peeker = peeker->next;
        }
        (list != nullptr) ? cout << "\b\b]" << endl : cout << "]" << endl;
    }

    virtual ~List() {
        while (list != nullptr)
            deleteAtBeginning();
    }
};
