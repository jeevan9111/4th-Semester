//
// Created by jeevan on 6/10/17.
//
#include <iostream>

using namespace std;

class node {
private:
    node *previous;
    int info;
    node *next;

    friend class List;

public:
    node(node *a = nullptr, int b = 0, node *c = nullptr) : previous(a), info(b), next(c) {}
};

class List {
private:
    node *head;
    node *tail;
public:
    List() : head(nullptr), tail(nullptr) {}

    void insertAtBeginning(int value) {
        node *newNode = new node(nullptr, value, head);
        (head == nullptr) ? tail = newNode : head->previous = newNode;
        head = newNode;
    }

    void insertAtEnd(int value) {
        node *newNode = new node(tail, value, nullptr);
        (tail == nullptr) ? head = newNode : tail->next = newNode;
        tail = newNode;
    }

    void insertAt(int position, int value) {
        node *target = head;
        for (int i = 0; (i++ < position) && (target != nullptr); target = target->next);
        if (target == nullptr)
            insertAtEnd(value);
        else {
            if (target->previous == nullptr)
                insertAtBeginning(value);
            else
                target->previous = (target->previous->next = new node(target->previous, value, target));
        }
    }

    int deleteAtBeginning() {
        if (head != nullptr) {
            node *first = head;
            int data = first->info;
            if ((head = head->next) == nullptr) tail = nullptr;
            head->previous = nullptr;
            delete[] first;
            return data;
        }
    }

    int deleteAtEnd() {
        if (tail != nullptr) {
            node *last = tail;
            int data = last->info;
            if ((tail = tail->previous) == nullptr) head = nullptr;
            tail->next = nullptr;
            delete[] last;
            return data;
        }
    }

    int deleteAt(int position) {
        node *target = head;
        for (int i = 0; i++ < position && target != nullptr; target = target->next);
        if (target != nullptr) {
            if (target->previous == nullptr)
                deleteAtBeginning();
            else if (target->next == nullptr)
                deleteAtEnd();
            else {
                int data = target->info;
                target->previous->next = target->next;
                target->next->previous = target->previous;
                delete[] target;
                return data;
            }
        }
    }

    void peekFromBeginning() {
        node *peeker = head;
        cout << "List = [";
        while (peeker != nullptr) {
            cout << peeker->info << ", ";
            peeker = peeker->next;
        }
        (head != nullptr) ? cout << "\b\b]" << endl : cout << "]" << endl;
    }

    void peekFromEnd() {
        node *peeker = tail;
        cout << "List = [";
        while (peeker != nullptr) {
            cout << peeker->info << ", ";
            peeker = peeker->previous;
        }
        (head != nullptr) ? cout << "\b\b]" << endl : cout << "]" << endl;
    }

    virtual ~List() {
        while (head != nullptr)
            deleteAtBeginning();
    }
};

int main() {
    List a;
    for (int i = 0; i < 10; i++)
        a.insertAt(5, i);
    a.peekFromBeginning();
}
