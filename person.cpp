//lets implement all that is defined in person.h

// #include <iostream> //we should be able to skip this since we included it in person.h
#include "person.h"

using namespace std; //we are lazy and don't want to type std:: before cout and endl

//constructor
Person::Person(string name, int age, double x) {
    this->name = name;
    this->age = age;
    this->x = x;
}

//destructor
Person::~Person() {
    cout << "Person " << name << " object destroyed" << endl;
}

//methods
Person& Person::print() {
    cout << "Person " << name << " is " << age << " years old"  << " x " << x << endl;
    return *this; //this makes the method chainable, we are returning ourselves
}

void Person::jump(double height) {
    //there could be some logic here to test if the person can jump that high
    cout << "Person " << name << " jumped " << height << " meters" << endl;
}

void Person::eat(string food) {
    //same goes for checking if the person can eat that food
    cout << "Person " << name << " ate " << food << endl;
}

//lets implement the move function
Person& Person::move(double distance) {
    //there could be some logic here to test if the person can move that far
    x += distance;
    cout << "Person " << name << " moved " << distance << " meters" << endl;
    return *this; //this makes the method chainable, we are returning ourselves
}