#include <iostream>
#include "BinaryTrees.cpp"

using namespace std;

class AVLtree : public BinarySearchTree {
public:
    node *RotateLeft(node *target) {
        node *a = target;
        target = target->right;
        node *b = target->left;
        target->left = a;
        target->left->right = b;
        return target;
    }
    node *RotateRight(node *target) {
        node *a = target;
        target = target->left;
        node *b = target->right;
        target->right = a;
        target->right->left = b;
        return target;
    }

    node *insert(int value, node *target) {
        if (target == NULL)
            return new node(value);
        if (value < target->key)
            target->left = insert(value, target->left);
        else
            target->right = insert(value, target->right);

        int leftHeight = findHeight(target->left);
        int rightHeight = findHeight(target->right);

        if (abs(leftHeight - rightHeight) > 1) {
            node *sonTarget = nullptr;
            node *grandsonTarget = nullptr;
            sonTarget = (value < target->key) ? target->left : target->right;
            grandsonTarget = (value < sonTarget->key) ? sonTarget->left : sonTarget->right;

            if (sonTarget == nullptr && grandsonTarget == nullptr)
                return target;

            if (target->left == sonTarget && sonTarget->left == grandsonTarget)
                target = RotateLeft(target);

            if (target->left == sonTarget && sonTarget->right == grandsonTarget) {
                target->left = RotateLeft(target->left);
                target = RotateRight(target);
            }
            if (target->right == sonTarget && sonTarget->left == grandsonTarget) {
                target->right = RotateRight(target->right);
                target = RotateLeft(target);
            }
            if (target->right == sonTarget && sonTarget->right == grandsonTarget)
                target = RotateRight(target);
        }
        return target;
    }

    node *insert(int value) {
        root = insert(value, root);
    }
};

int main() {
    AVLtree a;
    a.insert(10);
    a.insert(100);
    a.insert(20);

    a.traverse();
}

