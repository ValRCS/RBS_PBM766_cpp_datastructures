#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "Time to start looping!" << endl;
    //let's start with a while loop
    //for while loops we need a condition
    //typically it will involve a variable that changes
    //if the condition is false the loop will not run

    int i = 0;
    while (i < 10) {
        cout << "i is: " << i << endl;
        i++;
    }

    //let's do another while loop but we will have a simple i as the condition
    //so as long as i is NOT 0 the loop will run
    while (i) {
        cout << "i is: " << i << endl;
        i--;
    }
    cout << "i is: " << i << endl;

    //philosophically while loops are best for intedeterminate loops, where we are not sure
    // how many times we need to loop

    //one usage of while loops is to get input from the user
    //let's get an input from user if it is not a number we will keep asking
    // int number;
    // cout << "Please enter a number: ";
    // cin >> number; //it is possible that a user inputs non number here
    // while (cin.fail()) {
    //     cin.clear(); //if there is a fail you need to reset the state of fail
    //     //we want to ignore max characters in the buffer
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     //of course sometimes you might need something from buffer then you can use cin.ignore(100, '\n'); etc
    //     cout << "Please enter a number: ";
    //     cin >> number;
    // }
    // cout << "You entered: " << number << endl;

    //also it is somewhat common to use sentinel values (flag values) to stop a loop
    // bool stop_please = false;
    // //we could have used bool continue_please set to true
    // while (!stop_please) {
    //     cout << "Do you want to stop? (y/n): ";
    //     char answer;
    //     cin >> answer;
    //     if (answer == 'y') {
    //         stop_please = true;
    //     }
    // }
    //too many flags might make the code hard to read
    //personally I try to avoid them as much as possible
    //flags might be a way to get some code working but it is not the best way
    //it is a judgement call



    return 0;
}