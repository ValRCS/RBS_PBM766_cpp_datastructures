//let's play around with basic c type arrays
//arrays are a collection of elements of the same data type
//arrays are stored in contiguous memory locations - very efficient
//arrays are zero indexed
//arrays are fixed size
//arrays can be iterated over using a for loop

//more about array initialization
//https://en.cppreference.com/w/c/language/array_initialization

#include <iostream>
using namespace std;

//i recommend using const int for array size
size_t const ARR_SIZE = 10; //less magic numbers

//for now we will put the array in main

//let's make a function that prints all elements of an array
//arrays are passed as references to functions
//thus you do not need to pass the size of the array

//to safely use c type arrays in functions you need to pass the size of !!
void print_array(int arr[], size_t arr_size) {
    cout << "Size of array is: " << arr_size << endl;
    for (size_t i = 0; i < arr_size; i++) {
        cout << "Element " << i << " is: " << arr[i] << endl;
    }
}


int main() {
    //let's have an array of 10 integers
    // int arr[10] = {1,2,3,4,5,6,7,8,9,10}; //this is fine
    int arr[] = {1,2,3,4,5,6,7,8,9,10}; //this will automatically set the size of the array to 10 
    //because we supplied 10 elements

    //accessing elements of the array
    cout << "The first element of the array is: " << arr[0] << endl;

    //how about initializing array to same value
    int arr2[5] = {1,2}; //this will initialize the first two elements to 1 and 2, the rest will be 0
    //compare with arr example above

    arr2[4] = 9000; //let's change the last element to 9000
    //note how last element index is 4 not 5, since we are zero indexed
    //let's use a normal for loop to iterate over the array
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << " is: " << arr2[i] << endl;
    }

    //how could I get size of array?
    //sizeof(arr2) will give you the size of the array in bytes
    //print size of array
    cout << "Size of array is: " << sizeof(arr2) << " bytes" << endl;
    //so to get size of array in number of elements you need to know the size of each element
    //print size of each element
    cout << "Size of each element is: " << sizeof(arr2[0]) << " bytes" << endl;
    //thus to get the number of elements in the array 
    //you divide the size of the array by the size of each element
    cout << "Number of elements in the array is: " << sizeof(arr2)/sizeof(arr2[0]) << endl;
    //so instead of hardcoding the size of the array in the for loop
    //you can use the above formula to get the size of the array
    //thus the for loop becomes
    for (size_t i = 0; i < sizeof(arr2)/sizeof(arr2[0]); i++) {
        cout << "Element " << i << " is: " << arr2[i] << endl;
    }

    //typically we use size_t data type to store the size of an array
    //size_t is an unsigned integer data type
    size_t array_size = sizeof(arr2)/sizeof(arr2[0]);
    cout << "Size of array is: " << array_size << endl;

    //if we do not need index we can use range based for loop
    //we can also iterate over array elements with auto
    // for (auto element : arr2) {
    //     cout << "Element is: " << element << endl;
    //     //let's print its data type
    //     cout << "Data type of element is: " << typeid(element).name() << endl;
    // }

    //so what is going to happen when I access c type array out of bounds let's find out

    // cout << "Element 100 is: " << arr2[100] << endl; //danger!! - technically undefined behavior
    //could print 0 could print garbage could crash your program - anything could happen
    //with c type arrays it is up to you to make sure you are accessing elements within bounds
    //technically C arrays are just thin wrappers around pointers in C and also in C++

    //so let's use predefined ARR_SIZE to iterate to create a blank array without any values
    int arr3[ARR_SIZE]; //this will create an array of size 10 with no values
    //let's print the array, it could be all 0s or garbage values
    //not recommended to say the least
    // for (size_t i = 0; i < ARR_SIZE; i++) {
    //     cout << "Element " << i << " is: " << arr3[i] << endl;
    // }
    //instead let's initialize the array to squares of the index
    for (size_t i = 0; i < ARR_SIZE; i++) {
        arr3[i] = i*i;
    }
    //now let's print the array
    for (size_t i = 0; i < ARR_SIZE; i++) {
        cout << "Element " << i << " is: " << arr3[i] << endl;
    }

    //let's find the maximum value in the array
    int max = arr3[0]; //initialize max to first element
    for (size_t i = 1; i < ARR_SIZE; i++) {
        if (arr3[i] > max) {
            max = arr3[i];
        }
    }
    cout << "Maximum value in the array is: " << max << endl;

    //let's creat a blank array of size 5
    const size_t ARR_SIZE2 = 5;
    int arr4[ARR_SIZE2]; //this will create an array of size 5 with no values
    //let's copy the first 5 elements of arr3 to arr4
    for (size_t i = 0; i < ARR_SIZE2; i++) {
        arr4[i] = arr3[i];
    }
    //let's print the new 
    for (size_t i = 0; i < ARR_SIZE2; i++) {
        cout << "Element " << i << " is: " << arr4[i] << endl;
    }

    //let's print the array using a function
    //to do so we need to pass the size of the array
    //because arrays are passed as references to functions
    print_array(arr4, ARR_SIZE2);
}
