//let's make our namespace to store a few data types, constants and simple functions
#include <iostream>
#include <string>

namespace myNamespace {
    //let's make a namespace to store our enums
    namespace enums {
        //let's make an enum for the days of the week
        enum Week {
            Monday = 0,
            Tuesday,
            Wednesday,
            Thursday,
            Friday,
            Saturday,
            Sunday
        };
    }

    //let's make a namespace to store our functions
    namespace functions {
        //let's make a function that returns bool if it is a weekday
        bool isWeekday(enums::Week day) {
            //return day >= Monday && day <= Friday; //this could be written as day < Saturday but this is more readable
            //personally I would consider full names for the days of the week in switch statements
            switch (day) {
                case enums::Week::Monday:
                case enums::Week::Tuesday:
                case enums::Week::Wednesday:
                case enums::Week::Thursday:
                case enums::Week::Friday:
                //also easy to add Saturday if you have an evil boss
                    return true;
                default:
                    return false;
            }
        }

        //how about a function to adjust a day by a number of days and return the new day
        enums::Week adjustDay(enums::Week day, int days) {
            return static_cast<enums::Week>((day + days) % 7); //of course 7 is the number of days in a week
        }

        //how about similar function that modifies the day in place
        void adjustDayInPlace(enums::Week &day, int days) {
            day = static_cast<enums::Week>((day + days) % 7);
        }

        //let's make a function to return string representation of the day
        std::string dayToString(enums::Week day) {
            switch (day) {
                case enums::Week::Monday:
                    return "Monday";
                case enums::Week::Tuesday:
                    return "Tuesday";
                case enums::Week::Wednesday:
                    return "Wednesday";
                case enums::Week::Thursday:
                    return "Thursday";
                case enums::Week::Friday:
                    return "Friday";
                case enums::Week::Saturday:
                    return "Saturday";
                case enums::Week::Sunday:
                    return "Sunday";
                default:
                    return "Not a day of the week";
            }
        }
    }
}

using namespace myNamespace; //now I can use enums and functions directly
//so just like using namespace std I avoid the need to prefix my enums and functions with myNamespace::

//if I want to use functions directly then I can supply two levels of namespaces
using namespace myNamespace::functions; //now my functions are directly accessible
//i skip two levels of namespaces 
int main() {
    //define new day
    myNamespace::enums::Week today = myNamespace::enums::Week::Monday;
    //so we actually have double layer of namespaces here
    //we have myNamespace which has two namespaces inside it
    //one of them is enums and the other is functions
    //so if I want to skip this access to enums I can use using

    //now I can create new day without the need to prefix it with myNamespace::enums::
    enums::Week anotherDay = enums::Week::Sunday; //I had to avoid a naming collision here with Weekend enum
}

//your own namespaces are great in larger projects
//for smaller projects they can be overkill especially two levels of namespaces or more