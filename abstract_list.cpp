//let's create an abstract List class with some basic methods

#include <iostream>

using namespace std;

//let's create an abstract List class for integers (assume we do not know about templates yet)
//this a generic ADT (abstract data type) for a list of integers
class List {
public:
    //pure virtual function - this makes the class abstract
    //we will need to implement this function in the derived classes
    virtual void insert(int value) = 0;
    virtual void remove(int value) = 0;
    virtual void print() = 0;
};
//basically we are saying that we need to have these functions in the derived classes
//we do not care how you do it, but you need to do it


//let's create a concrete class for List
//this ArrayList functions more like a stack because we are not defining methods to insert or remove at specific index
class ArrayList : public List {
private:
    int *array;
    int size;
    int capacity;
public:
    //we need to implement the pure virtual functions
    ArrayList(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->array = new int[capacity]; //so we are allocating maximum memory for the array
    };
    void insert(int value) {
        if (size < capacity) {
            array[size] = value;
            size++;
        }
    };
    void remove(int value) {
        for (int i = 0; i < size; i++) {
            if (array[i] == value) {
                for (int j = i; j < size - 1; j++) {
                    array[j] = array[j + 1];
                }
                size--;
                break;
            }
        }
    };
    void print() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    };
    ~ArrayList() {
        delete[] array; //crucial to free the memory
    };
};

//let's use our concrete List class
int main() {
    ArrayList list(10); //this allocates memory for 10 integers
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);
    list.print();
    list.remove(10);
    list.print();
    return 0;
}