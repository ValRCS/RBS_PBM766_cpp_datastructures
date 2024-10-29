//let's implement a simple linked list
//our Node struct will store int data and a pointer to the next node
//our LinkedList class will store a pointer to the head node
//our LinkedList class will have a method to add a node to the end of the list
//our LinkedList class will have a method to print the list
//our LinkedList class will have a method to delete a node from the list
//our LinkedList class will have a method to find a node in the list by its data

#include <iostream>
using namespace std;

struct Node {
    int data; //so we will be storing integers in our linked list
    Node* next; //stores the memory address of the next node in the list, could be NULL
};

//now let's define LinkedList class

class LinkedList {
    private:
        Node* head; //pointer to the first node in the list
    public:
    //default constructor to initialize the head to nullptr meaning our LinkedList is empty
        LinkedList() {
            head = nullptr; //initialize head to nullptr
        }

        //method to add a node to the end of the list
        void addNode(int data) {
            Node* newNode = new Node(); //create a new node by allocating memory for it
            newNode->data = data; //set the data of the new node to the data passed in
            newNode->next = nullptr; //set the next pointer of the new node to nullptr

            //if the list is empty, set the head to the new node
            if (head == nullptr) {
                head = newNode;
            } else {
                //otherwise, traverse the list to the end and add the new node
                Node* current = head;
                //this is O(n) operation, not optimal
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }

        //method to print the list
        void printList() {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        //method to delete a node from the list
        //will delete the first instance of the node with the data passed in
        //linear time complexity O(n) in the worst case
        void deleteNode(int data) {
            Node* current = head;
            Node* previous = nullptr;

            //traverse the list to find the node to delete
            while (current != nullptr && current->data != data) {
                previous = current;
                current = current->next;
            }

            //if the node was found, delete it
            if (current != nullptr) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
            }
        }

        //method to find a node in the list by its data
        //this will be linear by default, O(n)
        Node* findNode(int data) {
            Node* current = head;
            while (current != NULL && current->data != data) {
                current = current->next;
            }
            return current;
        }
};

//let's see this linked list in action

int main() {
    LinkedList list;

    //add some nodes to the list
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    //print the list
    list.printList();

    //delete a node from the list
    list.deleteNode(3);

    //print the list again
    list.printList();

    //find a node in the list
    Node* node = list.findNode(2);
    if (node != nullptr) {
        cout << "Node found: " << node->data << endl;
    } else {
        cout << "Node not found" << endl;
    }

    return EXIT_SUCCESS;
}