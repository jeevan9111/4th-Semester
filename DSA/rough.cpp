//
// Created by jeevan on 7/2/17.
//

#include <iostream>
#include "List.cpp"

using namespace std;

class ListModified : public List, public node {
private:
    char name;
public:
    ListModified(char a) : name(a) {}

    void peek() {
        node *peeker = list;
        bool AtLeastOnceDrawn = false;
        cout << name << " = [";
        while (peeker != nullptr) {
            AtLeastOnceDrawn = true;
            cout << peeker->info << ", ";
            peeker = peeker->next;
        }
        (AtLeastOnceDrawn) ? cout << "\b\b]" << endl : cout << "]" << endl;
    }
};

class TOH {
private:
    ListModified A;
    ListModified B;
    ListModified C;
public:
    TOH() : A('A'), B('B'), C('C') {
        int n;
        cout << "Enter the num of discs : ";
        cin >> n;

        for (int i = 0; i++ < n;)
            A.insertAtBeginning(i);
        peek();
        move(n, A, C, B);
    }

    void move(int n, ListModified &SourcePeg, ListModified &DestinationPeg, ListModified &AuxiliaryPeg) {
        if (n == 1) {
            int a = SourcePeg.deleteAtEnd();
            DestinationPeg.insertAtBeginning(a);
            peek();
        } else {
            move(n - 1, SourcePeg, AuxiliaryPeg, DestinationPeg);
            int a = SourcePeg.deleteAtEnd();
            DestinationPeg.insertAtBeginning(a);
            peek();
            move(n - 1, AuxiliaryPeg, DestinationPeg, SourcePeg);
        }
    }

    void peek() {
        A.peek();
        B.peek();
        C.peek();
        cout << endl;
    }

};

int main() {
    TOH a;
}