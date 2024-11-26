//let's build an AVL tree from scratch

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <string>

using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height;
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr; //to make it easier to delete nodes and navigate up the tree
        this->height = 1; //AVL requires height to be 1 for leaf nodes by default we have 1
    }
};

class AVL {
public:
    Node* root;
    AVL() {
        this->root = nullptr;
    }

    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* node) {
        Node* newRoot = node->left;
        Node* newRootRight = newRoot->right;

        newRoot->right = node;
        node->left = newRootRight;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

        return newRoot;
    }

    Node* leftRotate(Node* node) {
        Node* newRoot = node->right;
        Node* newRootLeft = newRoot->left;

        newRoot->left = node;
        node->right = newRootLeft;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

        return newRoot;
    }

    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        }
        else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        else {
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && data < node->left->data) {
            return rightRotate(node);
        }

        if (balance < -1 && data > node->right->data) {
            return leftRotate(node);
        }

        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && data < node -> right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        //return the node
        return node; //TODO check correctness if this is ever reached
    }

    //now delete
    Node* deleteNode(Node* node, int data) {
        if (node == nullptr) {
            return node;
        }

        if (data < node->data) {
            node->left = deleteNode(node->left, data);
        }
        else if (data > node->data) {
            node->right = deleteNode(node->right, data);
        }
        else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                }
                else {
                    *node = *temp;
                }
                delete temp;
            }
            else {
                Node* temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (node == nullptr) {
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

//traversal functions will print the tree in order
    void inOrder(Node* node) {
        if (node == nullptr) {
            return;
        }
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    //find value, return nullptr if not found
    Node* find(Node* node, int data) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->data == data) {
            return node;
        }
        if (data < node->data) {
            return find(node->left, data);
        }
        else {
            return find(node->right, data);
        }
    }
};

//now let's test the AVL tree
int main() {
    AVL tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 25);

    tree.inOrder(tree.root);
    cout << endl;

    tree.root = tree.deleteNode(tree.root, 30);
    tree.inOrder(tree.root);
    cout << endl;

    tree.root = tree.deleteNode(tree.root, 40);
    tree.inOrder(tree.root);
    cout << endl;

    tree.root = tree.deleteNode(tree.root, 25);
    tree.inOrder(tree.root);
    cout << endl;

    // tree.root = tree.deleteNode(tree.root, 50);
    // tree.inOrder(tree.root);
    // cout << endl;

    // tree.root = tree.deleteNode(tree.root, 20);
    // tree.inOrder(tree.root);
    // cout << endl;

    // tree.root = tree.deleteNode(tree.root, 10);
    // tree.inOrder(tree.root);
    // cout << endl;

    return 0;
}

//TODO add support for parent pointers in next implementation