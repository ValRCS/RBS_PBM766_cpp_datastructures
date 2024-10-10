//let's explore use of dynamic memory allocation
//we use new and delete keywords

#include <iostream>
//for strcpy we need
#include <string.h>

using namespace std;

//lets declare a student struct with some attributes
struct Student {
    int id; //so looks like this is actually 4 bytes (depends on the system)
    char name[20]; //c type string usually we would use std::string so space for 19 characters and null terminator
    // float percentage; //and we know float is 4 bytes //we should be really using double for percentage
    double percentage; //and we know double is 8 bytes //we should be really using double for percentage
    char grade; //so 1 byte
};

int main() {
    //first let's allocate dynamically some single integer
    int *p = new int; //so we are allocating memory for a single integer
    //so we have memory address but nothing specific in it - whatever was there before
    //lets output this memory address
    cout << "Memory address: " << p << endl;
    //we can assign a value to it
    *p = 5; //so we say the value at the memory address is 5
    //we can print it
    cout << "Value at memory address: " << *p << endl;
    //we can delete it
    delete p; //so we are freeing the memory - it is not needed anymore
    //we should not use p anymore at this point
    //we should always delete memory that we allocate dynamically !! 
    //even though it will be deleted when the program ends

    //let's allocate memory for a single student
    Student *pStudent = new Student; //so we are allocating memory for a single student on heap not stack
    //so we have memory address but nothing specific in it - whatever was there before
    //lets output this memory address
    cout << "Memory address of student: " << pStudent << endl;

    //let's assign some values to the student
    pStudent->id = 1;
    //we can use strcpy to copy the string
    strcpy(pStudent->name, "Alice Brown"); //again in production use std::string instead
    pStudent->percentage = 99.9;
    pStudent->grade = 'A';

    //let's print the student
    cout << "Student id: " << pStudent->id << endl;
    cout << "Student name: " << pStudent->name << endl;
    cout << "Student percentage: " << pStudent->percentage << endl;
    cout << "Student grade: " << pStudent->grade << endl;

    //we can delete the student
    delete pStudent; //so we are freeing the memory - it is not needed anymore

    //so for single values we do not need to use new and delete usually no need , stack is fine

    //we usually use new and delete for arrays of data
    //meaning we want mega bytes of memory or even giga bytes, possibly tera bytes on some huge servers

    //let's allocate memory for an array of 10 integers
    int *pArray = new int[10]; //so we are allocating memory for 10 integers
    //again we just have the memory address of first element we do not know what is in it
    //also we do not know how many elements are in the array
    //we need to keep track of this ourselves
    //let's assign some values to first 7
    for (int i = 0; i < 7; i++) {
        pArray[i] = i * 10;
    }
    //let's print 15 elements //we do not actually have 15! we have 10 out of which 7 are initialized
    //so we are accessing memory that we do not own!!! This is very bad!
    //even worse would be changing the values of uninitialized memory or memory that we do not own!!
    //that would lead to catastrophic failure of the program even the whole system
    for (int i = 0; i < 15; i++) {
        cout << "Element " << i << ": " << pArray[i] << endl;
        //actuually array pArray[i] syntactic sugar for *(pArray + i)
        cout << "Element " << i << ": " << *(pArray + i) << endl;
        //pArray + i is pointer arithmethic
        //print address of the element using pointer arithmetic
        //pointer arithmetic is done in bytes so it is pArray + i * sizeof(int) in this particular case
        cout << "Address of element " << i << ": " << pArray + i << endl;
    }

    //print size of integer on this system
    cout << "Size of integer: " << sizeof(int) << endl;

    //so you need to keep track of how many elements you have allocated
    //so you should have used some constant like const int ARR_SIZE = 10; to keep track of the size

    //again let's free the memory
    delete[] pArray; //so we are freeing the memory - it is not needed anymore

}