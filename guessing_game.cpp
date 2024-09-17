//let's make a random guessing game where user has to guess number betweeen 1 and 100
//if the user guesses the number we will print "You guessed it!"
//we also want to keep track of guesses

//let's import needed libraries first
#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

//let's use the standard namespace
using namespace std;

//declare helper functions, we will define them later
int get_random(int start, int end);
int get_integer(string message);

//now let's define some useful constants
const int MIN_NUM = 1;
const int MAX_NUM = 100; //capital letters are often used for constants, not required but a convention
//let's add max guesses
const int MAX_GUESSES = 7; //with perfect play you can guess 7 times (log2(100) = 6.64)

//now let's write the main function
int main() {
    //let's seed the random number generator
    //we will use the current time as the seed
    srand(time(0));

    //let's get a random number between MIN_NUM and MAX_NUM
    int number = get_random(MIN_NUM, MAX_NUM);

    //let's output the number for debugging purposes
    // cout << "Number is: " << number << endl;

    //let's output the instructions
    cout << "Welcome to the guessing game!" << endl;
    cout << "You need to guess a number between 1 and 100" << endl;
    cout << "Good luck!" << endl;

    //let's declare a variable to keep track of guesses
    int guesses = 0;

    //let's declare a variable to keep track of the user's guess
    int guess;

    //let's start a loop
    //we will keep looping until the user guesses the number
    //we will use a while loop because we do not know how many times we need to loop
    while (true) {
        //let's get the user's guess
        guess = get_integer("Please enter your numeric guess: ");

        //let's increment the number of guesses
        guesses++;
        //check if the user has run out of guesses
        if (guesses >= MAX_GUESSES) {
            cout << "You ran out of guesses!" << endl;
            cout << "You took " << guesses << " guesses" << endl;
            cout << "The number was: " << number << endl;
            break;
        }

        //let's check if the user guessed the number
        if (guess == number) {
            cout << "You guessed it!" << endl;
            cout << "It took you " << guesses << " guesses" << endl;
            break; //break exits the closest loop (innermost loop) - here we just have one loop
        } else if (guess < number) {
            cout << "Too low!" << endl;
        } else {
            cout << "Too high!" << endl;
        }
    }

    //let's output a message to the user
    cout << "Thanks for playing!" << endl;

    //let's return 0 to indicate success
    return 0;
}

//now let's write a function to get a random number between start and end
int get_random(int start, int end) {
    //we will use the rand function
    //rand() % 100 will give us a number between 0 and 99
    //we need to add start to get a number between start and end
    //next is a general formula to get a number between start and end - INCLUSIVE
    return rand() % (end - start + 1) + start;
}

//let's make a helper function that asks for an integer
int get_integer(string message) {
    //let's declare a variable to store the user's input
    int number;

    //let's start a loop
    //we will keep looping until the user enters a valid integer
    while (true) {
        //let's output the message
        cout << message;

        //let's get the user's input
        cin >> number;

        //let's check if the input is valid
        if (cin.fail()) {
            //if the input is not valid we need to clear the error flag
            cin.clear();

            //we also need to ignore the rest of the line
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            //let's output an error message
            cout << "Invalid input. Please try again." << endl;
        } else {
            //if the input is valid we can break out of the loop
            break;
        }
    }

    //let's return the number
    return number;
}