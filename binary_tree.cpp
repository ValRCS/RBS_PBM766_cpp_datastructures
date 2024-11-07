//lets make a binary tree structure
//we will use Node struct that holds integers

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

//lets make a binary tree class
class BinaryTree {
    public:
        Node* root;
        BinaryTree() {
            root = nullptr;
        }

        //function to insert a node in next available position
        //next is defined by level order traversal
        void insert(int val) {
            Node* newNode = new Node(val);
            if(root == nullptr) {
                root = newNode;
                return;
            }
            //we will use a queue to insert the node
            queue<Node*> q;
            q.push(root);
            while(!q.empty()) {
                Node* temp = q.front();
                q.pop();
                if(temp->left == nullptr) {
                    temp->left = newNode;
                    return;
                } else {
                    //means we have one more level to go
                    q.push(temp->left);
                }
                if(temp->right == nullptr) {
                    temp->right = newNode;
                    return;
                } else {
                    //again means we have one more level to go
                    q.push(temp->right);
                }
            }
        }

        //function to delete a node
        void deleteNode(int val) {
            if(root == nullptr) {
                cout << "Tree is empty" << endl;
                return;
            }
            //we will use a queue to delete the node
            queue<Node*> q;
            q.push(root);
            Node* keyNode = nullptr;
            Node* temp = nullptr;
            while(!q.empty()) {
                temp = q.front();
                q.pop();
                if(temp->data == val) {
                    keyNode = temp;
                }
                if(temp->left != nullptr) {
                    q.push(temp->left);
                }
                if(temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
            if(keyNode != nullptr) {
                //we move the deepest node to the keyNode position
                int x = temp->data;
                deleteDeepest(temp);
                keyNode->data = x;
            }
        }

        //function to delete the deepest node
        void deleteDeepest(Node* delNode) {
            queue<Node*> q;
            q.push(root);
            Node* temp = nullptr;
            while(!q.empty()) {
                temp = q.front();
                q.pop();
                if(temp == delNode) {
                    temp = nullptr;
                    delete(delNode);
                    return;
                }
                if(temp->right != nullptr) {
                    if(temp->right == delNode) {
                        temp->right = nullptr;
                        delete(delNode);
                        return;
                    } else {
                        q.push(temp->right);
                    }
                }
                if(temp->left != nullptr) {
                    if(temp->left == delNode) {
                        temp->left = nullptr;
                        delete(delNode);
                        return;
                    } else {
                        q.push(temp->left);
                    }
                }
            }
        }

        //function to traverse the tree in level order
        //level order is also called breadth first traversal (BFS)
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

        //function to traverse the tree in pre order
        //pre order is also called depth first traversal (DFS) - one case of it
        void preOrderTraversal(Node* node) {
            //we need a base case scenario
            if(node == nullptr) {
                return;
            }
            cout << node->data << " ";
            //we make two recursive calls then
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
};

int main() {
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);
    cout << "Level order traversal (BFS - breadth first traversal): " << endl;
    bt.levelOrderTraversal();
    // bt.deleteNode(3);
    // bt.levelOrderTraversal();
    cout << "Pre order traversal: " << endl;
    bt.preOrderTraversal(bt.root);
    return 0;
}