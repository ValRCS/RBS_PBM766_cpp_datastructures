//let's explore templates and generics in C++
//templates let you write generic functions and classes

#include <iostream>
#include <string>

using namespace std;

//let'' write a template function for max
template <typename T>
T myMax(T a, T b) {
    return a > b ? a : b; //we use ternary operator to return the max of the two arguments
}
//above function takes two arguments of type T and returns the max of the two arguments which is the same type T

//what can be type T ?
//well it can be any type that supports the > operator
//so if we had our own class, we can overload the > operator and use it with our template function

//let's make a generic class of stack
//stack is a data structure that follows LIFO (Last In First Out) principle
//we will define a class template for stack with push, pop and top operations
template <typename T>
class Stack {
    private:
        T *data; //pointer to data
        int size; //size of the stack
        int top; //index of the top element
    public:
        Stack(int size) {
            this->size = size;
            data = new T[size]; //allocate memory for the stack
            top = -1; //initialize top to -1
        }
        void push(T element) {
            if (top == size - 1) {
                cout << "Stack is full" << endl;
                return; //early return if stack is full
            }
            data[++top] = element; //increment top and add the element
            //note the use of pre-increment operator it is crucial here to increment top before using it
            //otherwise on first push top will be -1 and we will write to data[-1] which is out of bounds
            //we could have rewritten the above line as two lines
            //top++; //here it does not matter if we use pre or post increment
            //data[top] = element;
        }
        void pop() {
            if (top == -1) {
                cout << "Stack is empty" << endl;
                return;
            }
            top--; //decrement top
            //note here this pop operation does not actually remove the element from the stack
            //it just decrements the top index which is enough to remove the top element
        }
        T topElement() {
            if (top == -1) {
                cout << "Stack is empty" << endl;
                return T(); //return default value of T
            }
            return data[top]; //return the top element
        }
        //let's add a destructor to free the memory
        ~Stack() {
            delete[] data; //free the memory
        }

        //let's define a friend function that compares stacks by their sizes
        //this is a non-member function that is a friend of the Stack class
        //it can access private members of the Stack class
        //it is not a member function of the Stack class

        //note that we are using the same template type T for the stack and the friend function

        //so let's make a friend function that is passed two stacks and returns the bigger stack
        //it returns the stack with the bigger top index

        //note that we are passing the stacks by reference

        //note that we are using the same template type T for the stack and the friend function

        friend Stack<T>& biggerStack(Stack<T>& s1, Stack<T>& s2) {
            // return s1.size > s2.size ? s1 : s2; //this would compare by size
            return s1.top > s2.top ? s1 : s2;
        }

        //now let's overload  > operator for the stack class
        //this will allow us to compare two stacks using the > operator
        //we will compare the top indices of the two stacks
        //note that we are using the same template type T for the stack and the friend function
        bool operator>(Stack<T>& s) {
            return top > s.top; //i could compare by some other criteria such as size
        }
};

int main() {
    cout << "myMax(3, 7) " << myMax(3, 7) << endl; //7
    cout << "myMax(3.0, 7.0) " << myMax(3.0, 7.0) << endl; //7
    cout << "myMax('a', 'z') " << myMax('a', 'z') << endl; //z
    cout << "myMax(\"hello\", \"world\") " << myMax("hello", "world") << endl; //world //more of a C string question
    string s1 = "hello";
    string s2 = "world";
    cout << "myMax(s1, s2) " << myMax(s1, s2) << endl; //world as expected

    //let's make a stack of integers
    Stack<int> intStack(5);
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    cout << "intStack.topElement() " << intStack.topElement() << endl; //3
    intStack.pop(); //moves the top to 2
    cout << "intStack.topElement() " << intStack.topElement() << endl; //2
    intStack.pop(); //moves the top to 1
    cout << "intStack.topElement() " << intStack.topElement() << endl; //1
    intStack.pop(); //moves the top to -1
    cout << "intStack.topElement() " << intStack.topElement() << endl; //Stack is empty //default value of int is 0
    
    //let's do stack of strings - the good c++ strings
    //we do not have to rewrite the stack class, we can reuse the same class
    Stack<string> stringStack(15);
    stringStack.push("let's");
    stringStack.push("go");
    stringStack.push("grab");
    stringStack.push("lunch.");
    cout << "stringStack.topElement() " << stringStack.topElement() << endl; //lunch.
    stringStack.pop(); //moves the top to grab
    cout << "stringStack.topElement() " << stringStack.topElement() << endl; //grab
    stringStack.pop(); //moves the top to go
    cout << "stringStack.topElement() " << stringStack.topElement() << endl; //go
    stringStack.pop(); //moves the top to let's
    cout << "stringStack.topElement() " << stringStack.topElement() << endl; //let's
    stringStack.pop(); //moves the top to -1
    cout << "stringStack.topElement() " << stringStack.topElement() << endl; //Stack is empty //default value of string is empty string
    //let's add one more element
    stringStack.push("let's");
    //now stringStack has one element, its top is 0
    //intStack has no elements its top is -1
    //let's compare the two stacks, alas it is not done easily, FIXME TODO
    //instead let's creeat a new string stack and compare the two since the signatures match
    Stack<string> stringStack2(10); //top is -1 by defaul

    Stack<string>& bigger = biggerStack(stringStack, stringStack2);
    //the bigger one
    cout << "bigger.topElement() " << bigger.topElement() << endl; //let's

    //now that we have overloaded the > operator for the stack class we can compare two stacks
    cout << "stringStack > stringStack2 " << (stringStack > stringStack2) << endl; //true
    //note the use of parentheses to avoid the ambiguity of operator precedence, see overloading.cpp earlier
    return 0;
}