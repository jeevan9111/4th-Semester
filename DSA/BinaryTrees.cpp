#include <iostream>

using namespace std;

class node {
public:
    int key;
    node *parent;
    node *left;
    node *right;

    node(int key = 0, node *left = nullptr, node *right = nullptr, node *parent = nullptr) : key(key), left(left),
                                                                                             right(right),
                                                                                             parent(parent) {}
};


class BinarySearchTree {
protected:
    node *root;

public:
    BinarySearchTree() : root(nullptr) {}

    node *search(int value, node *target) {
        if (target == nullptr || value == target->key)
            return target;
        else if (value < target->key)
            return search(value, target->left);
        else
            return search(value, target->right);
    }

    node *search(int value) {
        node *a = search(value, root);
        if (a == nullptr)
            cout << "No such element";
        else
            cout << a << endl;
    }

    node *insert(int value, node *target) {
        if (target == NULL)
            return new node(value);
        if (value < target->key)
            target->left = insert(value, target->left);
        else
            target->right = insert(value, target->right);
        return target;
    }

    node *insert(int value) {
        root = insert(value, root);
    }

    node *remove(int value, node *target) {
        if (target == nullptr)
            return target;
        if (value < target->key)
            target->left = remove(value, target->left);
        else if (value > target->key)
            target->right = remove(value, target->right);
        else {
            if (target->left == nullptr) {
                node *temp = target->right;
                delete target;
                return temp;
            } else if (target->right == nullptr) {
                node *temp = target->left;
                delete target;
                return temp;
            }
            node *temp = findMinimum(target->right);
            target->key = temp->key;
            target->right = remove(temp->key, target->right);
        }
        return target;
    }

    node *remove(int value) {
        remove(value, root);
    }

    void traverseInOrder(node *target) {
        if (target == nullptr)
            return;
        traverseInOrder(target->left);
        cout << target->key << " ";
        traverseInOrder(target->right);
    }

    void traversePreOrder(node *target) {
        if (target == NULL)
            return;
        cout << target->key << " ";
        traversePreOrder(target->left);
        traversePreOrder(target->right);
    }

    void traversePreOrder(node *target) {
        if (target == NULL)
            return;
        cout << target->key << " ";
        traversePreOrder(target->left);
        traversePreOrder(target->right);
    }

    void traversePostOrder(node *target) {
        if (target == NULL)
            return;
        traversePreOrder(target->left);
        traversePreOrder(target->right);
        cout << target->key << " ";
    }

    void traverse() {
        traversePreOrder(root);
        cout << endl;
    }

    node *findMinimum(node *target) {
        if (target == nullptr || target->left == nullptr)
            return target;
        findMinimum(target->left);
    }

    node *findMinimum() {
        node *a = findMinimum(root);
        if (a == nullptr)
            cout << "No data input" << endl;
        else
            cout << "Minimum value = " << a->key << endl;
    }

    node *findMaximum(node *target) {
        if (target == nullptr || target->right == nullptr)
            return target;
        findMinimum(target->right);
    }

    node *findMaximum() {
        node *a = findMaximum(root);
        if (a == nullptr)
            cout << "No data input" << endl;
        else
            cout << "Maximum value = " << a->key << endl;
    }

    int findHeight(node *tree) {
        if (tree == nullptr)
            return 1;
        int leftHeight = findHeight(tree->left);
        int rightHeight = findHeight(tree->right);
        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }

    int findHeight() {
        return findHeight(root);
    }

    virtual ~BinarySearchTree() {}
};
