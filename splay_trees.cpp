//let's do a splay tree implementation in c++
//we will use a struct to represent a node in the tree
//we will have a root node
//we will have a function to insert a node into the tree
//we will have a function to search for a node in the tree
//we will have a function to delete a node from the tree
//we will have a function to print the tree
//we might have a height function to get the height of the tree

#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <climits>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

//let's make a struct to represent a node in the tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

//let's make a struct to represent a splay tree
struct SplayTree {
    Node* root;
    SplayTree() {
        this->root = nullptr;
    }

    //let's make a function to insert a node into the tree
    void insert(int data) {
        //if the tree is empty - the easy case
        if (this->root == nullptr) {
            this->root = new Node(data);
            return;
        }
        //if the tree is not empty
        //we will insert the node as a leaf node in appropriate position
        //we will splay the node to the root
        Node* current = this->root;
        Node* parent = nullptr; //we have to keep track of the parent
        //we find the right position to insert the new node
        while (current != nullptr) {
            parent = current;
            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        //now parent is the parent of the new node
        //let's insert the new node
        if (data < parent->data) {
            parent->left = new Node(data);
        } else {
            parent->right = new Node(data);
        }
        cout << "Inserted " << data << endl;
        //now let's splay the new node to the root
        this->splay(data);
    }

    //let's make a function to search for a node in the tree
    bool search(int data) {
        //if the tree is empty
        if (this->root == nullptr) {
            return false;
        }
        //if the tree is not empty
        //we will search for the node
        //we will splay the node to the root
        Node* current = this->root;
        while (current != nullptr) {
            if (data == current->data) {
                //we found the node
                this->splay(data);
                return true;
            } else if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        //if we reach here the node is not in the tree
        return false;
    }

    //let's make a function to delete a node from the tree
    void remove(int data) {
        //if the tree is empty
        if (this->root == nullptr) {
            return;
        }
        //if the tree is not empty
        //we will search for the node
        //we will splay the node to the root
        //we will remove the node

        //find the node - will also move the node to the root
        if (!this->search(data)) {
            return;
        }
        //now the node is at the root
        //if the node has no children
        if (this->root->left == nullptr && this->root->right == nullptr) {
            delete this->root;
            this->root = nullptr;
            return;
        }
        //if the node has one child
        if (this->root->left == nullptr) {
            Node* temp = this->root;
            this->root = this->root->right;
            delete temp;
            return;
        }
        if (this->root->right == nullptr) {
            Node* temp = this->root;
            this->root = this->root->left;
            delete temp;
            return;
        }
        //if the node has two children
        //we will find the maximum node in the left subtree
        //we will splay the maximum node to the root
        //we will remove the maximum node
        //we will make the maximum node the root

        //find the maximum node in the left subtree
        Node* current = this->root->left;
        while (current->right != nullptr) {
            current = current->right;
        }
        //now current is the maximum node in the left subtree
        //splay the maximum node to the root
        this->splay(current->data);
        //remove the maximum node
        this->root->right = current->right;
        delete current;
    }

    //let's make a function to splay a node to the root - this is the hard part
    void splay(int data) {
        //if the tree is empty - easy base case
        if (this->root == nullptr) {
            return;
        }
        cout << "Splaying " << data << endl;
        //if the tree is not empty
        //we will splay the node to the root
        //we will use zig-zig and zig-zag rotations
        //we will use a dummy node as the root of the tree
        Node* dummy = new Node(INT_MIN);
        dummy->right = this->root;
        Node* leftTreeMax = dummy;
        Node* rightTreeMin = nullptr;
        Node* current = this->root;
        while (current != nullptr) {
            if (data < current->data) {
                if (current->left == nullptr) {
                    break;
                }
                if (data < current->left->data) {
                    //zig-zig rotation
                    Node* temp = current->left;
                    current->left = temp->right;
                    temp->right = current;
                    current = temp;
                    if (current->left == nullptr) {
                        break;
                    }
                }
                //link right
                rightTreeMin = current;
                current = current->left;
                rightTreeMin->left = current->right;
                current->right = rightTreeMin;
            } else if (data > current->data) {
                if (current->right == nullptr) {
                    break;
                }
                if (data > current->right->data) {
                    //zig-zig rotation
                    Node* temp = current->right;
                    current->right = temp->left;
                    temp->left = current;
                    current = temp;
                    if (current->right == nullptr) {
                        break;
                    }
                }
                //link left
                leftTreeMax = current;
                current = current->right;
                leftTreeMax->right = current->left;
                current->left = leftTreeMax;
            } else {
                break;
            }
        }
        cout << "Will assemble now" << endl;
        //assemble //FIXME: this is not working
        //TODO extra credit for fixing this ... 
        //possibly the order of the links is wrong
        dummy->right = current;
        leftTreeMax->right = current->left;
        rightTreeMin->left = current->right;
        current->left = dummy->right->left;
        current->right = dummy->right->right;
        this->root = current;
        cout << "About to delete dummy" << endl;
        delete dummy;
    }

    //let's make a function to print the tree
    void print() {
        //non recursive level order traversal
        //if the tree is empty
        if (this->root == nullptr) {
            return;
        }
        //if the tree is not empty
        //we will print the tree in level order
        queue<Node*> q;
        q.push(this->root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        cout << endl;
    }

    //let's also implement pre-order print
    void preOrder(Node* current) {
        if (current == nullptr) {
            return;
        }
        cout << current->data << " ";
        preOrder(current->left);
        preOrder(current->right);
    }

    //let's also implement in-order print - should be same as print function
    void inOrder(Node* current) {
        if (current == nullptr) {
            return;
        }
        inOrder(current->left);
        cout << current->data << " ";
        inOrder(current->right);
    }

    //let's also implement post-order print
    void postOrder(Node* current) {
        if (current == nullptr) {
            return;
        }
        postOrder(current->left);
        postOrder(current->right);
        cout << current->data << " ";
    }

    //finally let's implement a height function
    int height(Node* current) {
        if (current == nullptr) {
            return 0;
        }
        int leftHeight = height(current->left);
        int rightHeight = height(current->right);
        return 1 + max(leftHeight, rightHeight);
    }

    //let's implement a function to get the height of the tree
    int height() {
        return this->height(this->root);
    }

    //lets also do bfs traversal of the tree
    void bfs() {
        //if the tree is empty
        if (this->root == nullptr) {
            return;
        }
        //if the tree is not empty
        //we will do a bfs traversal of the tree
        queue<Node*> q;
        q.push(this->root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
};

//We are ready to test this implementation

int main() {

    SplayTree st;
    // st.insert(100);
    // st.insert(50);
    // st.insert(200);
    // st.insert(25);
    // st.insert(75);
    // st.insert(150);
    // st.insert(250);
    // st.insert(60);
    // st.insert(90);
    // st.insert(300);
    //let's insert numbers from 10 to 70 in steps of 10
    cout << "Inserting numbers from 10 to 70 in steps of 10" << endl;
    for (int i = 10; i <= 70; i += 10) {
        cout << "Inserting " << i << endl;
        st.insert(i);
    }
    st.print();
    cout << st.height() << endl;
    st.bfs();
    st.preOrder(st.root);
    cout << endl;
    st.inOrder(st.root);
    cout << endl;
    st.postOrder(st.root);
    cout << endl;

    return 0;
}
