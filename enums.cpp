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

//let's create a typedef for Week
typedef Week W; //just an alias for Week, of course W is a bit short for Week

//let's try weekend enum
//this will cause name collision with Week enum
// enum Weekend {
//     Saturday = 6,
//     Sunday = 7
// };

using namespace std; //now we do not have to prefix cout, cin, etc with std::

//let's make a function that returns bool if it is a weekday
bool isWeekday(Week day) {
    //return day >= Monday && day <= Friday; //this could be written as day < Saturday but this is more readable
    //personally I would consider full names for the days of the week in switch statements
    switch (day) {
        case Monday:
        case Tuesday:
        case Wednesday:
        case Thursday:
        case Friday:
        //also easy to add Saturday if you have an evil boss
            return true;
        default:
            return false;
    }
}

//how about a function to adjust a day by a number of days and return the new day
Week adjustDay(Week day, int days) {
    return static_cast<Week>((day + days) % 7); //of course 7 is the number of days in a week
}

//how about similar function that modifies the day in place
void adjustDayInPlace(Week &day, int days) {
    day = static_cast<Week>((day + days) % 7);
}

//let's make a function to return string representation of the day
string dayToString(Week day) {
    switch (day) {
        case Monday:
            return "Monday";
        case Tuesday:
            return "Tuesday";
        case Wednesday:
            return "Wednesday";
        case Thursday:
            return "Thursday";
        case Friday:
            return "Friday";
        case Saturday:
            return "Saturday";
        case Sunday:
            return "Sunday";
        default:
            return "Not a day of the week";
    }
}

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

    //now let's loop through all the days of the week
    for (Week day = Monday; day <= Sunday; day = static_cast<Week>(day + 1)) {
        std::cout << "Day " << day + 1 << std::endl;
    }
    //day should be out of scope here - good! you want your scope to be as small as possible

    //it is very common to use enums in switch statements

    Week day = Tuesday;
    switch (day) {
        case Monday:
            std::cout << "It's Monday!" << std::endl;
            break;
        case Tuesday:
            std::cout << "It's Tuesday!" << std::endl;
            break;
        case Wednesday:
            std::cout << "It's Wednesday!" << std::endl;
            break;
        case Thursday:
            std::cout << "It's Thursday!" << std::endl;
            break;
        case Friday:
            std::cout << "It's Friday!" << std::endl;
            break;
        case Saturday:
            std::cout << "It's Saturday!" << std::endl;
            break;
        case Sunday:
            std::cout << "It's Sunday!" << std::endl;
            break;
        default:
            std::cout << "It's not a day of the week!" << std::endl;
            break;
    }

    //since I defined W in typedef, I can use W instead of Week
    //in practice W is a bit too short for Week, very short names can be hard to read
    W anotherDay2 = Sunday; //So W is just an alias for Week
    cout << "Day " << anotherDay2 + 1 << endl;

    //let's use our adjustDay function
    //this is OUT OF PLACE function
    Week day2 = adjustDay(Tuesday, 50); //so what day of week is 50 days after Tuesday?
    cout << "Day " << day2 + 1 << " " << dayToString(day2) << endl;
    //now let's use our IN PLACE function
    Week day3 = Tuesday;
    //we modify day3 in place by passing it by reference so it is changed
    adjustDayInPlace(day3, 50); //so what day of week is 50 days after Tuesday?
    cout << "Day " << day3 + 1 << " " << dayToString(day3) << endl;

    cout << "Whew all done!" << endl;
    return 0;

    //one of the takeaways from this lesson - use enums as simple identifiers
    // avoid doing math with enums
}