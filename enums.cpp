// Let's explore defining and using enums in C++s
// Enums are a way to define a set of named constants

#include <iostream>

//let's define enum named Week
enum Week {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

//let's try weekend enum
//this will cause name collision with Week enum
// enum Weekend {
//     Saturday = 6,
//     Sunday = 7
// };

using namespace std; //now we do not have to prefix cout, cin, etc with std::

//let's use them
int main() {
    Week today; //note I am using the enum Week here as data type here
    today = Tuesday;
    //as soon as you start doing math with enums you get integer values, which you can print
    //but also be careful with this as it can lead to bugs
    std::cout << "Day " << today + 1 << std::endl;
    std::cout << "Day " << today + 100 << std::endl; //so enum got converted to int
    //personally I would avoid using too much enum to int conversion 

    //we can compare enum values in C++
    //let's compare Monday with Thursday
    if (Monday < Thursday) {
        std::cout << "Monday is less than Thursday" << std::endl;
    } else if (Monday > Thursday) { //this should never happen
        std::cout << "Monday is somehow bigger than Thursday" << std::endl;
    } else { //again this branch should not be reached
        std::cout << "Monday is equal to Thursday" << std::endl;
    }

    //let's adjust our today by 2 days
    today = static_cast<Week>(today + 2);
    std::cout << "Day " << today + 1 << std::endl;

    //let's make another day variable
    // Week anotherDay = Friday;
    Week anotherDay = Week::Sunday; //I had to avoid a naming collision here with Weekend enum
    //print out another day
    std::cout << "Day " << anotherDay + 1 << std::endl;
    //let's add these days together
    Week combinedDay = static_cast<Week>(today + anotherDay); //we should get error here
    //print out the combined day
    std::cout << "Day " << combinedDay + 1 << std::endl;


    //let's try using ++ on today
    // today++; //this will give an error - good!
    // today += 1; //this will give an error - good!
    // today = today + 1; //this will give an error - good!
    today = static_cast<Week>(today + 1); //this is fine but not recommended, could go out of bounds

    std::cout << "Day " << today + 1 << std::endl;

    

    cout << "Whew all done!" << endl;
    return 0;

    //one of the takeaways from this lesson - use enums as simple identifiers
    // avoid doing math with enums
}