//let's explore classes and objects in C++
//class is a blueprint for an object
//object is an instance of a class

#include <iostream>

//let's use standard namespace
using namespace std;

//define a class Animal 
//for now very basic with few properties and few methods
class Animal {
    //access specifier
    //private members are only accessible within the class
    private: //this is the default access specifier actually so we can skip it
        //properties
        string name;
        string sound;
        int age;
        //methods
        // void setName(string name) {
        //     this->name = name;
        // }
        // void setAge(int age) {
        //     this->age = age;
        // }
        // void setSound(string sound) {
        //     this->sound = sound;
        // };
    //access specifier
    //public members are accessible from outside the class
    public:
        //let's add a public property whether they bite
        bool bites = false; //by default animals do not bite, a brave assumption
        //another approach would be to move bites to private and public function would check if animal bites

        //constructor
        Animal(string name, int age, string sound = "Bark") {
            this->name = name;
            this->age = age;
            this->sound = sound;
            cout << "Animal object created" << endl;
        }
        //destructor
        ~Animal() {
            cout << "Animal object "<< name << " destroyed" << endl;
        }
        //methods
        void display() {
            cout << "Name: " << name << endl; //public method can access private properties
            cout << "Age: " << age << endl;
        }

        //lets add make sound method
        void makeSound() {
            cout << "Animal makes sound " << sound << endl;
        }

        //let's add prototype to public feed method
        void feed(string food);
};

//let use our Animal in main function

int main() {
    //create an object of Animal
    Animal dog("Dog", 5); //we create an instance of Animal class as an object dog
    //above is possible because we created a constructor in Animal class
    //call display method
    dog.display(); //display is public method in Animal class so we can call it as an object method - member function
    // dog.setName("Dog"); //this will not work because setName is private method in Animal class
    dog.makeSound(); //this will not work because we did not set sound property in Animal class
    //does this dog bite?
    cout << "Does this dog bite? " << dog.bites << endl; //will show 0 or 1 for false or true


    //let's make a cat - a different instance of Animal class
    Animal cat("Cat", 3, "Meow"); //note how we can set sound property here
    cat.display();
    cat.makeSound();
    cat.feed("Fish");
    return 0;
}

//let's implement feed method - the function signature is already defined in class
// your implementation should be outside the class and follow the class definition
void Animal::feed(string food) {
    //here we could check whether animal likes the food or not by accessing some private property
    cout << "Animal " << name << " is fed with " << food << endl;
}