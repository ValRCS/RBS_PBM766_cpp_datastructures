//let's show an example of handling user input with exceptions
//we want to get an integer from the user
//if the user enters a non-integer, we want to throw an exception
//we want to continue asking the user for an integer until they give us one


#include <iostream>
#include <stdexcept> //this is the header file for runtime_error

using namespace std;

int main() {
    int num = 0; //some default value
    while (true) {
        cout << "Enter an integer: ";
        string input;
        cin >> input; //note that cin will not throw an exception if the input is not an integer
        //input will be a string or whatever the user entered until they hit enter
        try {
            cout << "Attempting to convert " << input << " to an integer" << endl;
            num = stoi(input); //if stoi fails, it throws an exception
            //we know num is good here
            break; //we break out of the INPUT loop if we have a valid integer
        } catch (invalid_argument& e) {
            //this is the catch block that will catch the exception
            //we can do whatever else we would like to do here when the argument is invalid
            //e is the exception that was thrown
            cout << "INVALID ARGUMENT Exception caught: " << e.what() << endl;
            //we continue the loop if we have an invalid integer
        } catch (out_of_range& e) {
            //this is the catch block that will catch the exception
            //we can do whatever else we would like to do here when the argument is out of range
            //e is the exception that was thrown
            cout << "OUT OF RANGE Exception caught: " << e.what() << endl;
            //we continue the loop if we have an out of range integer
        }
    }
    cout << "You entered: " << num << endl;
    //do whatever you want with num here
    return 0;
}