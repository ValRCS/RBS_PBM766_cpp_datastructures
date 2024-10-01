//let's explore some basics of structs
//structs are user defined data types

#include <iostream>
#include <string>
//my structs are in gameStructs.h
#include "gameStructs.h"

using namespace std;

//let's start with a simple Point data type
//a point has an x and y coordinate (maybe more dimensions)

//structs are typically defined outside of main
//structs are typically defined in header files - later about those

//structs are typically named with a capital letter - but not required

//structs are typically defined in CamelCase - but not required

//structs are typically defined with a _s suffix - but not required
// _t is typically for typedefs NOT structs


//let's create a function that prints a Point
//function with classical side effect - printing to console
void print_point(Point p) {
    cout << "Point has x: " << p.x << " and y: " << p.y << endl;
}

//similarly let's create a function that prints a Player
void print_player(Player player) {
    cout << "Player has name: " << player.name << " health: " << player.health << " score: " << player.score << endl;
    //let's print the position of the player
    print_point(player.position);
}
//note these function take my structs as arguments
//this is similar to how I would have done this in regular C language
//C++ offers also member functions which are more object oriented - but those are for later when we talk about classes


//for now to compare two players we would compare ALL their values
//this is not very efficient and not very practical
//we could write a function to do this
bool are_players_equal(Player p1, Player p2) {
    // if (p1.name == p2.name && p1.health == p2.health && p1.score == p2.score && p1.position.x == p2.position.x && p1.position.y == p2.position.y) {
    //     return true;
    // }
    // return false;
    //we do not need the if here since we are returning a boolean!!
    return p1.name == p2.name 
        && p1.health == p2.health 
        && p1.score == p2.score 
        && p1.position.x == p2.position.x 
        && p1.position.y == p2.position.y;
}

//lets make a function that returns the player with highest score
Player get_best_player(Player p1, Player p2) {
    if (p1.score > p2.score) {
        return p1;
    } else {
        return p2;
    }
}

//for now let's use Point inside our main

int main() {
    Point p1; //this will create a Point object with x and y coordinates
    //so we used Point template to create a Point object - very similar to how class objects are created

    //to access members of a struct you use the dot operator
    p1.x = 5;
    p1.y = 10;

    //let's print the coordinates of the point
    cout << "Point p1 has x: " << p1.x << " and y: " << p1.y << endl;

    //let's create a player
    Player player1; //this will create a Player object with name, health, score and position

    //let's print the player
    print_player(player1); //big question what will happen here?
    //so we got garbage values for name, health, score and position because we did not initialize them

    //let's initialize the player Valdis
    player1.name = "Valdis";
    player1.health = 100;
    player1.score = 0;
    player1.position = Point{77, 32.56}; //we can use Point constructor to initialize the position

    //let's print the player
    print_player(player1); //now we should see the values we set

    //let's make another Player with different values
    //how about Spongebob with health 200 and score 100
    //let's initialize at the time of creation
    Player player2{"Spongebob", 200, 100, Point{0, 0}}; //note again how we create a Point object inside the Player object

    //let's print the player
    print_player(player2); //now we should see the values we set

    //let's copy player 2 to player 3
    Player player3 = player2; //this will copy ALL the values from player2 to player3
    //cout let's print just the name of player3
    cout << "Player 3 name is: " << player3.name << endl;
    //now let's change the name to Squidward
    player3.name = "Squidward";
    //let's print the name of player3
    cout << "Player 3 name is: " << player3.name << endl;
    //let's print the name of player2
    cout << "Player 2 name is: " << player2.name << endl;

    //let's change coordinates of player3 //will it change player 2?
    //note we are not using Point constructor here, we use double . notation
    player3.position.x = 100;
    player3.position.y = 200.5;
    //so actually player2 will not be changed because we copied the values not the reference

    //let's print both players
    print_player(player2);
    print_player(player3);
    //Note this behaviour of = is different from say Python where = would create a reference to the same object!!

    //let's make another Player Patrick with health 150 and score 50
    //let's use = syntax to initialize

    Player player4 = {
        .name = "Patrick", 
        .health = 150,         
        .score = 50, 
        .position = Point{10, 20}
        }; 
            //it could be used to skip initializing some values if you have a lot of them

    //let's print the player
    print_player(player4); //now we should see the values we set

    //how could we compare our Players?
    //we could compare them by name
    if (player1.name == player2.name) {
        cout << "Player 1 and Player 2 have the same name!" << endl;
    } else {
        cout << "Player 1 and Player 2 have different names!" << endl;
    }
    //how about whole struct comparison?
    //not built in but you could write a function to compare all the values
    // if (player1 == player2) {
    //     cout << "Player 1 and Player 2 are the same!" << endl;
    // } else {
    //     cout << "Player 1 and Player 2 are different!" << endl;
    // }
    //lets compare players with our function
    if (are_players_equal(player1, player2)) {
        cout << "Player 1 and Player 2 have same contents(not necessarily memory location)!" << endl;
    } else {
        cout << "Player 1 and Player 2 are different!" << endl;
    }

    //let's create 5th player by copying player 4
    Player player5 = player4;
    //let's compare player 4 and player 5
    if (are_players_equal(player4, player5)) {
        cout << "Player 4 and Player 5 have same contents(not necessarily memory location)!" << endl;
    } else {
        cout << "Player 4 and Player 5 are different!" << endl;
    }

    //now let's get the player with  highest score
    Player best_player = get_best_player(player1, player2);
    cout << "Best player is: " << best_player.name << " with score: " << best_player.score << endl;
    return EXIT_SUCCESS;
}