//let's explore operator overloading in C++

#include <iostream>

using namespace std;

//let's define Clock class it will have 3 attributes hour, minute and second to represent time
//we will want a constructor to initialize the time

class Clock {
    private:
        int hour;
        int minute;
        int second;
    public:
        Clock(int h, int m, int s) {
            hour = h;
            minute = m;
            second = s;
        }
        //let's define a method to print the time
        void printTime() {
            cout << hour << ":" << minute << ":" << second << endl;
        }
        //let's define a method to add two clocks
        Clock addClock(Clock c) {
            int h = hour + c.hour;
            int m = minute + c.minute;
            int s = second + c.second;
            if (s >= 60) {
                m++;
                s -= 60;
            }
            if (m >= 60) {
                h++;
                m -= 60;
            }
            //hour is represented in 24 hour format so we want only 0-23
            h = h % 24; //so if it is 24 we get 0, and 25 we get 1 and so on
            return Clock(h, m, s);
        }
        //let's define a method to increment seconds by 1
        void incrementSecond() {
            second++;
            if (second >= 60) {
                second = 0;
                minute++;
                if (minute >= 60) {
                    minute = 0;
                    hour++;
                    if (hour >= 24) {
                        hour = 0; //no days to worry about
                    }
                }
            }
        }
        //finally we want equalTime method to compare two clocks
        bool equalTime(Clock c) {
            return hour == c.hour && minute == c.minute && second == c.second;
        }
        //now let's overload some operators
        //first let's overload the + operator //this is a binary operator
        Clock operator+(Clock c) {
            return addClock(c);
        }

        //now let's overload the == operator //this is a binary operator
        bool operator==(Clock c) {
            return equalTime(c); //you could have written  your own logic here, but then it would be redundant
            //you could have chosen different comparison logic but then the danger is that you might forget to update the equalTime method
        }

        //finally let's add increment operator //this is a unary operator
        void operator++() {
            incrementSecond();
        }
        //https://en.cppreference.com/w/cpp/language/operators
        //let's define postfix ++ operator note the int in the argument list
        void operator++(int) {
            incrementSecond();
        }

        //now let's make a friend function that prints the time using << operator
        //this function is NOT part of the class, but it can access the private members of the class
        friend ostream& operator<<(ostream& os, Clock c) {
            os << c.hour << ":" << c.minute << ":" << c.second; //what you want to output to stream is up to you
            //note we can't quite use the printTime method here because it prints to cout
            //here we return the ostream object so that we can chain the << operator
            return os;
        }

};


int main() {
    //let's make two clocks
    Clock c1(12, 30, 45);
    Clock c2(12, 30, 45);
    //let's print the time
    c1.printTime();
    c2.printTime();
    //let's add the two clocks
    // Clock c3 = c1.addClock(c2);
    Clock c3 = c1 + c2; //it should work the same way as addClock, it is just syntactic sugar
    c3.printTime();
    //let's compare the two clocks
    // cout << "Are first two clocks equal? " << c1.equalTime(c2) << endl;
    cout << "Are first two clocks equal? " << (c1 == c2) << endl; //we have to use parenthesis because == has lower precedence than <<
    //let's increment the second clock by 1 second
    c2.incrementSecond();
    ++c2; //same as c2.incrementSecond(); //i've define the prefix increment operator
    c2++; //same as c2.incrementSecond(); //i've define the postfix increment operator
    c2.printTime();
    //we can also output the time using the << operator
    cout << c2 << endl; //nicer than c2.printTime(); isn't it?
    //let's compare the two clocks again
    // cout << "Are first two clocks equal? " << c1.equalTime(c2) << endl;
    cout << "Are first two clocks equal? " << (c1 == c2) << endl;
}