//let's use person.h in personFactory.cpp

#include <iostream>
#include "person.h"

using namespace std;

int main() {
    //create a person object
    Person person("Alice", 25);
    Person person2("Bob", 30);
    Person person3("Carol", 35);
    Person person4("Dave", 40); //this is the last person object created
    //almost would feel like these would fit nicely in an array or a vector

    //let's call the print method
    person.print();
    person2.print();
    person3.print();
    person4.print();

    //lets move and print Alice a few times in same line
    person.move(1).print().move(2).move(3).print(); //FIXME our chain is producing a copy of the object
    //person should be at 6 meters NOT 1 meter!
    cout << "Alice is now at " << person.x << " meters" << endl;

    return 0;
}