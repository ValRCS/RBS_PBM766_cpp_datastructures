//let's make a binary search tree class
//we will also use a struct for the node that holds int data and two pointers to left and right child

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

//our basic building block
struct Node {
    int data;
    //so pointers to left and right children of same type
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

//lets make a binary search tree class
class BST {
    public:
        Node* root;
        //our constructor
        BST() {
            root = nullptr;
        }

        //function to insert a node in proper position
        //in binary search tree the left child is always less than the parent and right child is always greater
        void insert(int val) {
            Node* newNode = new Node(val);
            if(root == nullptr) {
                root = newNode;
                return;
            }
            Node* temp = root;
            Node* parent = nullptr;
            while(temp != nullptr) {
                parent = temp;
                if(val < temp->data) {
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
            if(val < parent->data) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }

        //function to search for a node in the tree
        Node* search(int val) {
            if(root == nullptr) {
                cout << "Tree is empty" << endl;
                return nullptr;
            }
            queue<Node*> q;
            q.push(root);
            while(!q.empty()) {
                Node* temp = q.front();
                q.pop();
                if(temp->data == val) {
                    return temp;
                }
                if(temp->left != nullptr) {
                    q.push(temp->left);
                }
                if(temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
            return nullptr;
        }

        //to properly delete a node from the tree
        //we have four cases
        //1. node is a leaf node - then just delete it
        //2. node has one child - then replace it with the child
        //3. node has two children - then replace it with the inorder successor

        //function to delete a node
        void deleteNode(int val) {
            if(root == nullptr) {
                cout << "Tree is empty" << endl;
                return;
            }
            Node* keyNode = search(val);
            if(keyNode == nullptr) {
                cout << "Node not found" << endl;
                return;
            }
            //we need to find the parent of the keyNode
            Node* temp = root;
            Node* parent = nullptr;
            while(temp != keyNode) {
                parent = temp;
                if(val < temp->data) {
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
            //case 1: keyNode is a leaf node
            if(keyNode->left == nullptr && keyNode->right == nullptr) {
                if(keyNode != root) {
                    if(parent->left == keyNode) {
                        parent->left = nullptr;
                    } else {
                        parent->right = nullptr;
                    }
                } else {
                    root = nullptr;
                }
                delete(keyNode);
                return;
            }
            //case 2: keyNode has one child
            if(keyNode->left == nullptr || keyNode->right == nullptr) {
                Node* child = keyNode->left ? keyNode->left : keyNode->right;
                if(keyNode != root) {
                    if(parent->left == keyNode) {
                        parent->left = child;
                    } else {
                        parent->right = child;
                    }
                } else {
                    root = child;
                }
                delete(keyNode);
                return;
            }
            //case 3: keyNode has two children
            Node* inorderSuccessor = keyNode->right;
            while(inorderSuccessor->left != nullptr) {
                inorderSuccessor = inorderSuccessor->left;
            }
            int x = inorderSuccessor->data;
            deleteNode(inorderSuccessor->data);
            keyNode->data = x;

        }

        //now let's have a level order traversal - BFS - breadth first traversal
        void levelOrderTraversal() {
            if(root == nullptr) {
                cout << "Tree is empty" << endl;
                return;
            }
            queue<Node*> q;
            q.push(root);
            while(!q.empty()) {
                Node* temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if(temp->left != nullptr) {
                    q.push(temp->left);
                }
                if(temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
            cout << endl;
        }
};

//now let's test our BST class
int main() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    //print level order traversal
    tree.levelOrderTraversal();
    //now delete 15
    tree.deleteNode(15);
    tree.levelOrderTraversal();
    //let's remove 10 our root
    tree.deleteNode(10);
    tree.levelOrderTraversal();
    return 0;
}