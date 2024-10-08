//let's explore the concept on inheritance in C++
//in inheritance, a class can inherit the properties of another class
//the class that is inherited is called the base class
//the class that inherits is called the derived class

#include <iostream>
#include <string>

using namespace std;

//base class
class Animal {
    string allergies; //private by default
    public:
        //name
        string name;
        void eat() {
            cout << "I can eat!" << endl;
        }
        void sleep() {
            cout << "I can sleep!" << endl;
        }
        void setAllergies(string allergies) {
            this->allergies = allergies;
        }
        string getAllergies() {
            return allergies;
        }

        //constructor
        Animal(string name, string allergies) {
            this->name = name;
            this->allergies = allergies;
            cout << "Animal created!" << endl;
        }
        //protected members are accessible by derived classes, but not by the outside world
        //private members are not accessible by derived classes
        //public members are accessible by derived classes
    protected: //callable by derived classes but not by the outside world
        void breathe() {
            cout << "I can breathe!" << endl;
        }
};

//lets create a derived class
class Dog : public Animal {
    public:
        void bark() {
            cout << "I can bark!" << endl;
        }
    //constructor by using : Animal(name) to call the base class constructor
    Dog(string name, string allergies) : Animal(name, allergies) {
        //so here we are calling the base class constructor and passing the name
        //now we can use the name in the derived class
        //and we can pass in the name when creating the derived class
        cout << "Dog created!" << endl;
        cout << "My name is " << name << endl;
        cout << "I am allergic to " << getAllergies() << endl; //no way to get allergies from base class directly
    }

    //we can use the protected method breathe from the base class
    void doggieBreathe() {
        breathe(); //we can call the protected method breathe from the base class
    }
};

int main() {
    Dog dog = Dog("Spot", "Cats");
    dog.eat();
    dog.sleep();
    dog.bark();
    // dog.breathe(); //this will not work because breathe is protected
    dog.doggieBreathe(); //this will work because doggieBreathe is public
    

    //since Animal class is the base class, we can create an Animal object
    Animal animal = Animal("Octopus", "Shellfish");
    animal.eat();
    animal.sleep();
    //animal.bark(); //this will not work because Animal class does not have a bark method
    
    return 0;
}