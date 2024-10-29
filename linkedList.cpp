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
        //tail would be helpful to add to the end of the list in O(1) time
        Node* tail; //pointer to the last node in the list
    public:
    //default constructor to initialize the head to nullptr meaning our LinkedList is empty
        LinkedList() {
            head = nullptr; //initialize head to nullptr
            tail = nullptr; //initialize tail to nullptr
        }

        //let's add method to add to the beginning of the list
        //this will be O(1) operation - what we want!
        void addNodeAtBeginning(int data) {
            Node* newNode = new Node(); //create a new node by allocating memory for it
            newNode->data = data; //set the data of the new node to the data passed in
            //at this moment newNode is dangling, it's not connected to the list
            newNode->next = head; //set the next pointer of the new node to the current head

            head = newNode; //set the head to the new node
            //if we did not set head to newNode, we would not know how to find the new node
            //we might also need to set tail to newNode if the list was empty

            //if the list was empty, set the tail to the new node
            if (tail == nullptr) {
                tail = newNode;
            }
        }

        //method to add a node to the end of the list
        void addNode(int data) {
            Node* newNode = new Node(); //create a new node by allocating memory for it
            newNode->data = data; //set the data of the new node to the data passed in
            newNode->next = nullptr; //set the next pointer of the new node to nullptr

            //again O(1) operation to add to the end of the list
            //if the list is empty, set the head to the new node
            if (head == nullptr) {
                head = newNode;
            } else {
                //if the list is not empty, set the next pointer of the current tail to the new node
                tail->next = newNode;
                //set the tail to the new node
            }
            //we always set the tail to the new node
            tail = newNode;          
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
            while (current != nullptr && current->data != data) {
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

    //add at the beginning of the list
    list.addNodeAtBeginning(100); //O(1) operation
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