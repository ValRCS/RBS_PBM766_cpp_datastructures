//I am placing declaration for Point and Player structs in gameStructs.h
//it is good practice to place structs in separate header files
//also we want to use preprocessor directives to avoid multiple inclusions
//this is called include guards
//this is a simple way to avoid multiple inclusions

// #pragma once //this is a preprocessor directive to avoid multiple inclusions
// //it used to be non standard but now it is supported by most compilers
//use it if  your compiler supports it

//sure way is to use #ifndef #define #endif
#ifndef GAMESTRUCTS_H //if not defined
#define GAMESTRUCTS_H //define it

#include <string> //i need to include since I am using string in Player struct

struct Point {
    //members of the struct
    double x; //x coordinate
    double y; //y coordinate
};

//let's make a Player struct
struct Player {
    //members of the struct
    std::string name; //name of the player
    int health; //health of the player
    int score; //score of the player
    //we could also place the player position here
    //we could use x and y but better would be to  use Point which we already defined
    Point position; //position of the player
};

#endif //stop the definition include guards