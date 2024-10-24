//let's look at some basic exception handling in C++

#include <iostream>

using namespace std;

//we will check for division by zero in main

int main() {
    int a = 10;
    int b = 0;

//so if make a try block I need have at least one catch block to catch the exception
    try {
        //if b is zero, we will throw an exception
        if (b == 0) {
            throw "Division by zero"; //we throw a c string here
        }
        //this means we survived the division by zero
        //we are guaranteed that b is not zero
        cout << a / b << endl;
    } catch (const char* msg) {
        //this is the catch block that will catch the exception
        //we can do whatever else we would like to do here when b is zero
        //msg is the message that was thrown
        cout << "Exception caught: " << msg << endl;
    }
  

    return EXIT_SUCCESS;
}