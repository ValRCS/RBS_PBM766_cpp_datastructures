//vector is c++ class that is part of the standard library
//vector is a dynamic array - size can change during runtime
//vector is a generic template class so you can have vector of ints, doubles, strings etc 
///vectors are safer and more flexible than c style arrays
//vectors are iterable with range based for loops
//vectors are iterable with iterators
//vectors are iterable with indexes

//docs https://en.cppreference.com/w/cpp/container/vector
//you could also use fixed size version of vector called array
//docs https://en.cppreference.com/w/cpp/container/array

#include <iostream>
#include <vector> //include vector class from standard library

using namespace std;

//let's use it from main

int main() {
    //vector of numbers
    vector<int> numbers; //empty vector of integers

    //let's add some numbers to the vector
    numbers.push_back(1); //similar to append in python
    numbers.push_back(2);
    numbers.push_back(3);

    //let's print the vector
    for (size_t i = 0; i < numbers.size(); i++) {
        cout << "Element " << i << " is: " << numbers[i] << endl;
    }

    //we can also initialize vector upon creation
    vector<int> more_numbers = {10, 20, 30, 40, 50};

    //now let's get size and also max size of the vector
    //max size is the maximum number of elements the vector can hold at the moment

    cout << "Size of more_numbers is: " << more_numbers.size() << endl;
    cout << "Max size of more_numbers is: " << more_numbers.max_size() << endl;
    //also we want capacity of the vector meaning what is current allocated size
    cout << "Current capacity of more_numbers is: " << more_numbers.capacity() << endl;

    //lets get last element of the vector
    //we could use size() - 1 or back() method
    cout << "Last element of more_numbers is: " << more_numbers.back() << endl;
    //we could store it in a variable
    int last_element = more_numbers.back();
    cout << "Last element of more_numbers stored in a variable is: " << last_element << endl;
    //lets remove the last element
    more_numbers.pop_back(); //unlike Python pop() this does not return the popped element!!

    //now let's print the vector
    //we will use auto keyword to let compiler deduce the type
    //we do not care about index so we will use range based for loop
    for (auto number : more_numbers) {
        cout << "Number is: " << number << endl;
    }

    //let's check capacity and size again
    cout << "Current capacity of more_numbers is: " << more_numbers.capacity() << endl;
    cout << "Size of more_numbers is: " << more_numbers.size() << endl;

    //let's make two dimensional vector that stores multiplication table of 10x5
    vector<vector<int>> multiplication_table;
    for (int i = 1; i <= 10; i++) {
        vector<int> row;
        for (int j = 1; j <= 5; j++) {
            row.push_back(i * j);
        }
        multiplication_table.push_back(row);
    }

    //let's print the multiplication table
    for (auto row : multiplication_table) {
        for (auto cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
    }
    

    //let's do the same with c type arrays in 2d
    int c_multiplication_table[10][5];
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 5; j++) {
            c_multiplication_table[i-1][j-1] = i * j;
        }
    }
    //now let's print the multiplication table
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            cout << c_multiplication_table[i][j] << "\t";
        }
        cout << endl;
    }

    //one big difference is that c style arrays do not know their size
    //let's try to get value which is outside vector size
    cout << "Trying to get value outside vector size: " << more_numbers[100] << endl;
    //instead we could use at method which will throw exception if index is out of bounds
    cout << "Trying to get value outside vector size: " << more_numbers.at(100) << endl;
    //actually crashing and burning might be preferable to silent error
}