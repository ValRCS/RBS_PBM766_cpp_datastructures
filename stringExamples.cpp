//C++ has strings as a data type, which can be used to store a sequence of characters.
//we include it here to use it in our functions
#include <iostream>
#include <string>

using namespace std; //string is under std namespace

//simple string example in main
int main() {
    string name = "Valdis";
    string university = "RBS";
    //strings support concatenation with + operator
    string fullName = name + " " + university;
    cout << "My full name is " << fullName << endl;
    //strings have many useful methods - member functions we will talk about OOP later
    //for example size() returns the length of the string
    cout << "My full name has " << fullName.size() << " characters" << endl;
    //we can access individual characters with [] operator
    cout << "First character of my name is " << fullName[0] << endl;

}