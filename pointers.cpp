//let's explore some pointers
#include <iostream>

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
    int a = 5; //here we declare and initialize a variable
    int *p = &a; //here we declare a pointer to an integer and assign the address of a to it

    std::cout << "a (which is a integer value): " << a << std::endl;
    std::cout << "p which is memory address of (a): " << p << std::endl;
    std::cout << "*p: which is the contents of memory address appropriate for integer " << *p << std::endl;

    //lets store an integer in b
    int b = 297; //so 297-256 = 41 which is the ascii code for ')'
    //now we will create two pointers one will be int one will be char
    int *p1 = &b;
    char *p2 = (char *)&b; //so what will be value of this pointer?
    //pointer itself will be the same memory address as p1, but the contents when dereferenced will be different

    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << (void *)p2 << std::endl; //we need to cast it to void* to avoid printing the string

//let's see what is the value of the pointers
    std::cout << "Value *p1: " << *p1 << std::endl;
    std::cout << "Value *p2: " << *p2 << std::endl;
    //so if we wanted to multiply 10 by value of p1 we would do *p1 * 10 or 10 * (*p1)

    std::cout << "10 times value of *p1: " << 10 * (*p1) << std::endl;

    //let's see how many bytes each pointer takes
    std::cout << "Size of p1: " << sizeof(p1) << std::endl;
    std::cout << "Size of p2: " << sizeof(p2) << std::endl;

    //let's make a student object
    Student alice = {1, "Alice Brown", 99.9, 'A'};
    Student bob = {2, "Bob Green", 88.8, 'B'};

//it is very common to prepend p to the pointer variable name to indicate that it is a pointer
//of course modern IDEs will show you that it is a pointer
    Student *pAlice = &alice; //so pAlice is a pointer(memory address) to a student object somewhere in memory
    Student *pBob = &bob;

    //let's print both addresses for now
    std::cout << "Address of alice: " << pAlice << std::endl;
    std::cout << "Address of bob: " << pBob << std::endl;

    //now let's get some data out of alice
    //we could use pointer dereference operator * to get the value of the object
    std::cout << "Alice's id: " << (*pAlice).id << std::endl;
    //above is legal but very rarely used, instead we use the arrow operator which is a shorthand for the above
    std::cout << "Alice's id: " << pAlice->id << std::endl;

//null pointer assignment - pointer to nothing
//Tony Hoare called it his billion dollar mistake
//https://en.wikipedia.org/wiki/Tony_Hoare#Apologies_and_retractions

    int *p3 = nullptr; //this is a null pointer //idea is that it is a pointer that points to nothing
    //so what would happen if we try to dereference it?
    //std::cout << "Value of p3: " << *p3 << std::endl; //this will crash the program
    //we would need some mechanism to check if the pointer is null before dereferencing it
    if(p3 != nullptr) std::cout << "Value of p3: " << *p3 << std::endl; //this will not crash the program
    else std::cout << "p3 is a null pointer" << std::endl;
    return 0;
}