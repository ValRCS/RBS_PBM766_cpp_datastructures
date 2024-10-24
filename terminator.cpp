//we can set your own terminator function using set_terminate
//https://en.cppreference.com/w/cpp/error/set_terminate

#include <iostream>
#include <exception>
#include <string>

using namespace std;

//let's just write our own terminate function we will call it t800
void t800() {
    cout << "I'll be back" << endl;
    //we could do more things here
    //we could log the error
    //we could send an email
    //we could do anything we want
    //we could even throw an exception
    //we could even call abort
    //we could even call exit
    //we could even call quick_exit
    //we could even call _Exit
    //we could even call std::quick_exit
    //we could even call std::_Exit
    //we could even call std::abort
    //we could even call std::exit
    //we could even call std::terminate
    //we could even call std::unexpected
    //we could even call std::rethrow_exception
    //we could even call std::current_exception
    //we could even call std::rethrow_if_nested
    //we could even call std::nested_exception
    //we could even call std::throw_with_nested

    //for now we will jsut abort
    abort();
}

//now let's use it main

int main() {
    //we will just set our own terminate function
    set_terminate(t800); //we are passing a function pointer here

    //we will throw an exception
    throw runtime_error("I am a runtime error"); //no catch to catch this exception

    //we will never reach here
    cout << "This will never be printed" << endl;
}
