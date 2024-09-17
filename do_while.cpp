//do while loop is similar to while loop but the condition is checked at the end
// i call this loop "Shoot first, ask questions later"
//in other words the postcondition is checked at the end
//we guarantee at least ONE execution of the loop

//some uses of do while loop:
//1. getting input from the user
//2. menu driven programs
//3. reading a file

#include <iostream>
#include <limits>

using namespace std;

//lets write a function to get an integer from the user using do while loop
//TODO FIXME the do while is not quite correct yet
//we do not see messages when the input is invalid
int get_integer(string message) {
    //let's declare a variable to store the user's input
    int number;

    //let's start a loop
    //we will keep looping until the user enters a valid integer
    do {
        //let's output the message
        cout << message << endl; //endl will flush the buffer
        //if the input is not valid we need to clear the error flag
        //so the first run I am clearing flags even if they were not set
        cin.clear();
        //we also need to ignore the rest of the line before input is started
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //let's get the user's input
        cin >> number;

        //let's check if the input is valid
        if (cin.fail()) {


            //let's output an error message
            cout << "Invalid input. Please try again." << endl;
        }
    } while (cin.fail());

    //let's return the number
    return number;
}

//lets use this function in main
int main() {
    //let's get an integer from the user
    int number = get_integer("Please enter an integer: ");

    //let's output the number
    cout << "You entered: " << number << endl;

    //let's return 0 to indicate success
    return 0;
}