//let's explore the concept of composition in C++ and in Object Oriented Programming
//composition is a concept where a class can contain(has) an object of another class
//this is different from inheritance where a class can inherit (is a) another class

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//let's define a class Engine
class Engine {
    public:
        //engine size
        double volume;
        int hp; //horsepower
        void start() {
            cout << "Engine started!" << endl;
        }
        void stop() {
            cout << "Engine stopped!" << endl;
        }
        //constructor
        Engine(double volume, int hp) {
            this->volume = volume;
            this->hp = hp;
            cout << "Engine created!" << endl;
        }
};

//let's define wheels
class Wheel {
    public:
        int size;
        string brand;
        void rotate() {
            cout << "Wheel made by " << brand << " and size " << size << " is rotating!" << endl;
        }
        //constructor
        Wheel(int size, string brand) {
            this->size = size;
            this->brand = brand;
            cout << "Wheels created!" << endl;
        }
};

//let's define a class Car
class Car {
    //lets include a vector of wheels here


    public:
        //car name
        string maker;
        string model;
        //car engine
        Engine engine;
        //cars generally have 4 wheels, think of a car with 3 wheels...think Mr. Bean's nemesis
        // Wheels wheels[4]; //basic C type array - we could have used vector
        // Wheels wheel; //single one for now
        vector<Wheel> wheels; //this is a better approach than using a C type array
        int wheelCount;

        void drive() {
            cout << "Car is driving!" << endl;
        }
        //constructor
        Car(string maker, 
            string model, 
            double volume, 
            int hp,
            string wheelMaker,
            int wheelSize,
            int wheelCount) : engine(volume, hp) {
            //we already have an engine object created using : engine(volume, hp)
            //we also have a single wheel object created using : wheel(wheelSize, wheelMaker)
            //for wheels we need to make them here
            // for(int i = 0; i < 4; i++) { //again seeing 4 here is a code smell, possibly we might want to support 3 or 6 wheels
            //     wheels[i] = Wheels(wheelSize, wheelMaker);
            // }
            //now I can use the wheelCount to create the wheels
            for(int i = 0; i < wheelCount; i++) {
                wheels.push_back(Wheel(wheelSize, wheelMaker));
            }
            this->maker = maker;
            this->model = model;
            cout << "Car created!" << endl;
        }
};

int main() {
    //create a car object
    Car car("Toyota", "Corolla", 1.8, 140, "Michelin", 16, 4);
    //drive the car
    car.drive();
    //start the engine
    car.engine.start();
    //stop the engine
    //how many hp does the engine have?
    cout << "Engine has " << car.engine.hp << " hp" << endl;
    car.engine.stop();

    //let's create another Car
    // Car car2(string maker="Honda", 
    //         string model="Civic", 
    //         double volume=1.6, 
    //         int hp=120, 
    //         string wheelMaker="Bridgestone", 
    //         int wheelSize=15, 
    //         int wheelCount=4);
    //TODO how to pass named parameters in C++?

    Car car2("Honda", "Civic", 1.6, 120, "Bridgestone", 15, 4);

    car2.drive(); //of course drive should contain a check whether the engine is started...
    car2.engine.start();
    cout << "Engine has " << car2.engine.hp << " hp" << endl;
    cout << "The car is of maker " << car2.maker << " and model " << car2.model << endl;
    //lets rotate the wheels
    car2.wheels[0].rotate();
    car2.engine.stop();

    return 0;
}