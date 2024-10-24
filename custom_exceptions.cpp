//let's write our own custome exception
//we will call it InvalidAgeException

#include <iostream>
// #include <stdexcept> //this is the header file for runtime_error
//runtime error is subclass of exception
#include <exception>
//we could have included exception instead of runtime_error
#include <string> //this is the header file for string

using namespace std;

//let's define our custom exception by inheriting from exception
class InvalidAgeException : public exception {
    private: // in classes private is default, but we will write it for clarity
        string message; //custom message for the exception
    public:
    //constructor
    //we do not modify the message, so we use const reference
    //this constructor will initialize our private message variable with the msg
        InvalidAgeException(const string& msg) : message(msg) {}

    //we also need to override the what function
    //what is a member function of exception
    //what returns a c string
    //what returns a c string that describes the exception
    const char* what() const noexcept override {
        //we could do more things here but it should not be done in what
        //what is for returning the message

        //  we could just prepare the message to be slightly friendlier
        return message.c_str(); //we return the c string of our message
    }
};

int main(int argc, char* argv[]) {
    int age = 20; //some default value
    if (argc > 1) {
        //lets use std::stoi instead of atoi because stoi throws an exception
        // age = atoi(argv[1]); //if atoi fails, it returns 0 because atoi is from C and does not throw exceptions
        try {
            age = stoi(argv[1]); //if stoi fails, it throws an exception
            //we know age is good here
        } catch (invalid_argument& e) {
            //this is the catch block that will catch the exception
            //we can do whatever else we would like to do here when the argument is invalid
            //e is the exception that was thrown
            cout << "Exception caught: " << e.what() << endl;
            //we cant do anything with age here
            //so lets return
            return EXIT_FAILURE;
        } catch (out_of_range& e) {
            //this is the catch block that will catch the exception
            //we can do whatever else we would like to do here when the argument is out of range
            //e is the exception that was thrown
            cout << "Exception caught: " << e.what() << endl;
            //again nothing we can do with age
            //so lets return
            return EXIT_FAILURE;
        }
    }


    try {
        if (age <= 0 || age > 150) { //we assume that babies have positive age
            //we throw our custom exception
            //we pass the message
            throw InvalidAgeException("Invalid age: " + to_string(age));
        }
        //here age is good
        cout << "SUCCESS Age is: " << age << endl;
    } catch (InvalidAgeException& e) {
        //we catch our custom exception
        //we can do whatever we want here
        //we can log the exception
        //we can send an email to the developer
        //we can send an email to the user
        //we can launch a missile
        //or we can just print the message
        cout << "Exception caught: " << e.what() << endl;
    }

    return EXIT_SUCCESS;
}