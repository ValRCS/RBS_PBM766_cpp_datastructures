#include <iostream>
#include <string>

using namespace std;

//I am declaring my function but defining it later
int get_digit(string digit);
//let's do a function that outputs n fibonacci numbers
long fibonacci(int n) {
    long a = 0;
    long b = 1;
    long c;
    for (int i = 0; i < n; i++) {
        // cout << a << endl;
        c = a + b;
        a = b;
        b = c;
    }
    //would be nice to actually return instead cout
    //printing should be handled by another function
    //why? because most likely you do not want to print everything
    return c;
}

int main(int argc, char *argv[]) {
    cout << "Hi Mom!" << endl;

    //let's have an array of strings to represent the digits
    string digits[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Bazzilion"};

    //let's output all digits
    // for (int i = 0; i < 11; i++) {
    //     cout << digits[i] << " is:"  << get_digit(digits[i]) << endl;
    // }

    //now let's check if there are at least 2 arguments
    if (argc < 2) {
        cout << "You need to provide at least 2 arguments" << endl;
        return 1; //non zero return value means error
        //there are definitions for return values
    }

    //let's get the argument with index 1
    //why index 1 because index 0 is the name of the program!
    string arg1 = argv[1];
    //we need to cast this to an integer
    int n = stoi(arg1);

    //let's call the fibonacci function
    cout << fibonacci(n) << endl;

}

//let's write a function to output digits when given a string "Zero" to "Nine"
int get_digit(string digit) {
    if (digit == "Zero") {
        return 0;
    } else if (digit == "One") {
        return 1;
    } else if (digit == "Two") {
        return 2;
    } else if (digit == "Three") {
        return 3;
    } else if (digit == "Four") {
        return 4;
    } else if (digit == "Five") {
        return 5;
    } else if (digit == "Six") {
        return 6;
    } else if (digit == "Seven") {
        return 7;
    } else if (digit == "Eight") {
        return 8;
    } else if (digit == "Nine") {
        return 9;
    } else {
        return -1;
    }
}