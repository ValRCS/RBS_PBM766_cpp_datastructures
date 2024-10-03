//let's create a Person class that will have a name and age and we will use std::string for name
//also we will have a constructor and a method to print out the person
//also a method for person to move
//also a method for person to eat

//we want to use include guards to avoid multiple includes
//could have used #pragma once but include guards are more portable
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
    private:
        std::string name;
        int age;

    public:
        double x;
        //constructor
        Person(std::string name, int age, double x = 0);
        //destructor
        ~Person();
        //methods
        Person& print();
        void jump(double height);
        void eat(std::string food);
        //lets declare a move function that returns the object itself
        Person& move(double distance);
};

#endif