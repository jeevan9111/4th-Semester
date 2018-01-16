//
// Created by jeevan on 7/15/17.
//
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
        node *target = list;
        if (list != nullptr) {
            for (; target->next != nullptr; target = target->next);
            target->next = new node(value, nullptr);
        } else
            insertAtBeginning(value);
    }

    void insertAt(int position, int value) {
        node *target = list;
        node *preTarget = nullptr;
        for (int i = 0; i < position; i++) {
            if (target == nullptr)
                break;
            target = (preTarget = target)->next;
        }
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
        if (list != nullptr) {
            node *last = list;
            node *preLast = nullptr;
            for (; last->next != nullptr; last = (preLast = last)->next);
            if (preLast != nullptr) {
                preLast->next = nullptr;
                int data = last->info;
                delete[]last;
                return data;
            }
            deleteAtBeginning();
        }
    }

    int deleteAt(int position) {
        if (position != 0) {
            node *target = list;
            node *preTarget = nullptr;
            for (int i = 0; i++ < position; target = (preTarget = target)->next)
                if (target == nullptr)
                    break;
            if (target != nullptr) {
                int data = target->info;
                preTarget->next = target->next;
                if (target->next == nullptr)
                    return data;
                delete[] target;
                return data;
            }
        } else
            deleteAtBeginning();
    }

    void peek() {
        node *peeker = list;
        bool AtLeastOnceDrawn = false;
        cout << "List = [";
        while (peeker != nullptr) {
            AtLeastOnceDrawn = true;
            cout << peeker->info << ", ";
            peeker = peeker->next;
        }
        (AtLeastOnceDrawn) ? cout << "\b\b]" << endl : cout << "]" << endl;
    }

    virtual ~List() {
        while (list != nullptr)
            deleteAtBeginning();
    }
};
