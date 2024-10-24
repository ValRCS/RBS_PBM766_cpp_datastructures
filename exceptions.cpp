//let's look at some basic exception handling in C++

#include <iostream>

using namespace std;

//we will check for division by zero in main

int main(int argc, char* argv[]) {
    int a = 100'000'000; //' is just a separator for readability
    // int b = 0;
    // int b = -50;
    // int b = -50;
    int b = 0; //default in case no argument is passed
    if (argc > 1) {
        b = atoi(argv[1]); //if atoi fails, it returns 0
    }

//so if make a try block I need have at least one catch block to catch the exception
    try {
        //lets just divide by b without throwing any exceptions
        //this will crash the program if b is zero
        // cout << a / b << endl; //in Python, this would throw a ZeroDivisionError
        //in Java, this would throw an ArithmeticException
        //in C++ we have to do the checking ourselves
        //could we handle the exception here?
        //no, we cannot handle the exception here without throwing it

        //if b is zero, we will throw an exception
        if (b == 0) {
            throw "Division by zero"; //we throw a c string here
        }
        //this means we survived the division by zero
        //we are guaranteed that b is not zero
        //we could throw more things such as say negative numbers
        if (b < 0) {
            // throw "Division by negative number"; this would be handled by same catch block as above
            //let's throw a negative number exception instead
            throw b; //we throw an int here we could have thrown any type
        }
        //we could throw a specific exception type such as runtime_error
        //lets throw runtime error on b being over 9000
        if (b > 9000) {
            throw runtime_error("It's over 9000!"); //we throw a runtime_error here
            //runtime_error is a standard exception type in C++
            //it is defined in the stdexcept header file
        }

        cout << a / b << endl;
    } catch (const char* msg) {
        //this is the catch block that will catch the exception
        //we can do whatever else we would like to do here when b is zero
        //msg is the message that was thrown
        cout << "Exception caught: " << msg << endl;
    } catch (int num) {
        //this is the catch block that will catch the exception
        //we can do whatever else we would like to do here when b is negative
        //num is the number that was thrown
        cout << "Exception caught: " << num << endl;
    } //now I will handle runtime_error
    catch (runtime_error& e) {
        //this is the catch block that will catch the exception
        //we can do whatever else we would like to do here when b is over 9000
        //e is the runtime_error object that was thrown
        cout << "Exception caught: " << e.what() << endl;
    } catch (...) {
        //this is the catch block that will catch any other exception
        //we can do whatever else we would like to do here
        //such as logging the exception
        //usually we would want to rethrow the exception here
        //we do not just want to handle an unknown exception here and move on like nothing happened
        //that would be bad practice - leads to bugs and silent failures
        cout << "Some other exception caught" << endl;
    }
  

    return EXIT_SUCCESS;
}