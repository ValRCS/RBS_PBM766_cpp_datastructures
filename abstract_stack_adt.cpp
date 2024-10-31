//let's create a defintion for abstract stack ADT class
//we want the following functions in the derived classes
//push, pop, top, isEmpty, isFull
//we want this class to be generic as well
//we will use templates
#include <iostream>
#include <vector>

using namespace std;


template <class T>
class Stack {
public:
    virtual void push(T value) = 0;
    virtual void pop() = 0;
    //top should return a reference to the top element
    virtual T& top() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};

//let's create a concrete class for Stack using Vector

template <class T>
class VectorStack : public Stack<T> {
private:
    //so private is the implementation details while public is the interface
    vector<T> v;
    size_t size;
    size_t capacity;
public:
//now we implement the interface
    VectorStack(size_t capacity) {
        this->capacity = capacity;
        this->size = 0;
    };
    void push(T value) {
        if (size < capacity) {
            v.push_back(value);
            size++;
        }
        //since it is void full stack will not return anything and will not do anything
        //could raise an exception if stack is full
    };
    //now we need to return a reference to the top element
    T& top() {
        //what about if the stack is empty?
        //we could raise an exception
        //we could return a reference to a dummy value
        //let's return a dummy value as null_ptr cast to T
        if (size == 0) {
            return *(T*)nullptr;
        }
        return v[size - 1];
    };

    //so pop does not return anything
    void pop() {
        if (size > 0) {
            v.pop_back();
            size--;
        }
    };
    bool isEmpty() {
        return size == 0;
    };
    bool isFull() {
        return size == capacity;
    };
};

//now let's see our stack in action
int main() {
    VectorStack<int> stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.push(7);
    stack.push(8);
//now let's print until empty
    while (!stack.isEmpty()) {
        cout << stack.top() << endl;
        stack.pop();
    }
    return 0;
}