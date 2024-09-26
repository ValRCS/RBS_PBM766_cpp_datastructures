// c strings are primitive arrays of characters that are null terminated
// thus the last element of the array is '\0'

// c strings are used to store text data
// if possible use new c++ strings instead of c strings

// c strings are arrays of characters

#include <iostream>

using namespace std;

//we will use main to demonstrate c strings

int main() {
    char name[] = "Valdis"; //this is a c string

    //let's get the size of this c string
    //we will use sizeof operator
    //sizeof operator will give us the size of the array in bytes
    size_t single_char = sizeof(name[0]);
    size_t size_of_name = sizeof(name);
    size_t number_of_chars = size_of_name/single_char;
    cout << "Size of a single character is: " << single_char << " bytes" << endl;
    cout << "Size of the c string is: " << size_of_name << " bytes" << endl;
    cout << "Number of characters in the c string is: " << number_of_chars << endl;

    //so we could change the name
    name[0] = 'W'; //changing the first character to W
    cout << "Changed name is: " << name << endl;

    //operations with c-strings are quite primitive and painful and prone to errors
    //Advice use std::string instead of c-strings !!
}