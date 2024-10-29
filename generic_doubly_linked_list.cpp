//we will implement a generic doubly linked list

#include <iostream>
#include <string>
using namespace std;

//our Node struct will store data of type T and pointers to the next and previous nodes
template <typename T>
struct Node {
    T data; //so any type of data can be stored in our linked list
    Node* next;
    Node* prev;

    //let's make a constructor to initialize the node
    //we will use the new C++11 way of initializing the data member
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

//now let's define our DoublyLinkedList class
template <typename T>
class DoublyLinkedList {
    private:
        Node<T>* head; //pointer to the first node in the list
        Node<T>* tail; //pointer to the last node in the list
        //we also want size
        size_t size; //typically for length we use size_t, which is an unsigned integer type
    public:
        //let's start with Constructor to initialize the head and tail to nullptr
        //let's use the new syntax for initializing the member variables
        DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

        //also we will want to use the destructor to free the memory it will utilize clearAll method
        ~DoublyLinkedList() {
            clearAll(); //TODO remember to define this method
        }

        //method insertAtTail to add a node to the end of the list
        void insertAtTail(T value) {
            Node<T>* newNode = new Node<T>(value); //create a new node by allocating memory for it
            //set the next pointer of the new node to nullptr
            newNode->next = nullptr;
            //set the previous pointer of the new node to the current tail
            newNode->prev = tail;

            //if the list is empty, set the head to the new node
            if (head == nullptr) {
                head = newNode;
            } else {
                //if the list is not empty, set the next pointer of the current tail to the new node
                tail->next = newNode;
            }
            //we always set the tail to the new node
            tail = newNode;
            //increment the size of the list
            size++;
        }

        //let's do popAtTail method to remove the last node from the list
        //we also return the data of the node we are removing
        void popAtTail() {
            //if the list is empty, return
            if (head == nullptr) {
                return;
            }

            //get the data of the current tail
            T value = tail->data;

            //if the list has only one node
            if (head == tail) {
                delete tail;
                head = nullptr;
                tail = nullptr;
            } else {
                //if the list has more than one node
                //set the tail to the previous node
                tail = tail->prev;
                //delete the last node
                delete tail->next; //since our new tail has reference to our old tail
                //set the next pointer of the new tail to nullptr
                tail->next = nullptr;
            }
            //decrement the size of the list
            size--;
            // return value; //FIXME make it so we can return value
            return;
        }

        //lets do insertAtHead method to add a node to the beginning of the list
        void insertAtHead(T value) {
            Node<T>* newNode = new Node<T>(value); //create a new node by allocating memory for it
            //set the next pointer of the new node to the current head
            newNode->next = head;
            //set the previous pointer of the new node to nullptr
            newNode->prev = nullptr; // we know head points to nullptr //TODO check if necessary

            //if the list is empty, set the tail to the new node
            if (tail == nullptr) {
                tail = newNode;
            } else {
                //if the list is not empty, set the previous pointer of the current head to the new node
                head->prev = newNode;
            }
            //we always set the head to the new node
            head = newNode;
            //increment the size of the list
            size++;
        }

        //let's popAtHead method to remove the first node from the list
        //for now we are returning nothing
        void popAtHead() {
            //if the list is empty, return
            if (head == nullptr) {
                return;
            }

            //if the list has only one node
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                //if the list has more than one node
                //set the head to the next node
                head = head->next;
                //delete the first node
                delete head->prev; //since our new head has reference to our old head
                //set the previous pointer of the new head to nullptr
                head->prev = nullptr;
            }
            //decrement the size of the list
            size--; //this works because we have early return if head == nullptr
            return;
        }

        //now we can write a method to clear all nodes from the list using popAtTail
        void clearAll() {
            while (head != nullptr) {
                popAtTail();
            }
        }

        //let's do a printList method to print the list
        void printList() {
            //print size
            cout << "Size: " << size << endl;
            Node<T>* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        //let's do a findNode method to find a node in the list by its data
        //this will be linear by default, O(n)
        Node<T>* findNode(T value) {
            Node<T>* current = head;
            while (current != nullptr && current->data != value) {
                current = current->next;
            }
            return current;
        }

};

//let's see this doubly linked list in action
//we will store Person objects in our list
struct Person {
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}

    //lets have a friend function to overload the << operator
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << p.name << " (" << p.age << ")";
        return os;
    }
    //we need to overload the == operator to compare Person objects
    bool operator==(const Person& p) {
        return name == p.name && age == p.age;
    }
    //same goes for inequality operator
    bool operator!=(const Person& p) {
        return name != p.name || age != p.age;
    }
};

int main() {
    DoublyLinkedList<Person> list;

    //add some nodes to the list
    list.insertAtTail(Person("Alice", 25));
    list.insertAtTail(Person("Bob", 30));
    list.insertAtTail(Person("Charlie", 35));

    //print the list
    list.printList();

    //remove the last node
    list.popAtTail();

    //print the list
    list.printList();

    //now let's find Alice
    Node<Person>* node = list.findNode(Person("Alice", 25));
    //if the node was found, print it
    if (node != nullptr) {
        cout << "Node found: " << node->data << endl;
    } else {
        cout << "Node not found" << endl;
    }

    return 0;
}