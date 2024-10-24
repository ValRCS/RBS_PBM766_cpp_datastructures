//let's look at some basic exception handling in C++

#include <iostream>

using namespace std;

//we will check for division by zero in main

int main() {
    int a = 10;
    int b = 0;

    //if b is zero, we will throw an exception
    if (b == 0) {
        throw "Division by zero";
    }

    cout << a / b << endl;

    return 0;
}