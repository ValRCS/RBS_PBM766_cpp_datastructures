// let's explore different ways to implement linear search

//let's assume we have an array of integers and we want to find a specific integer in the array

//let's make a function where we pass in pointer to the array, the size of the array and the integer we are looking for

#include <iostream>
//lets add algorithm to use built in binary search as well
#include <algorithm>
using namespace std;

int linear_search(int *arr, size_t size, int target){
    //so complexity of this function is O(n) where n is the size of the array
    for(size_t i = 0; i < size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1; //represent that the target integer was not found, because there is no index -1
}

//let's make a function for binary search
int binary_search(int *arr, size_t size, int target){
    //complexity of this function is O(log(n)) where n is the size of the array
    size_t left = 0;
    size_t right = size - 1;
    while(left <= right){
        size_t mid = left + (right - left) / 2; //why are parentheses used here? because of operator precedence
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1; //represent that the target integer was not found, because there is no index -1
}

//our main will take two arguments one will be size of array to initialize and the second will be the target integer to search for
//we will be initalizing array with n consecutive integers starting from 0

//let's make a function for creating an array of n consecutive integers
int* create_array(size_t n, int offset = 0){
    int *arr = new int[n]; //dynamic allocation! will need to delete this memory later
    for(size_t i = 0; i < n; i++){
        arr[i] = i + offset;
    }
    return arr;
}

//let's make a function to delete the array
void delete_array(int *arr){
    delete[] arr;
}

//now let's make our main
int main(int argc, char *argv[]){
    if(argc != 5){
        cout << "Usage: " << argv[0] << " <size of array> <offset> <target integer> <-bin|-lin|-algolin|-algobin>" << endl;
        return 1;
    }
    size_t n = stoi(argv[1]);
    int offset = stoi(argv[2]);
    int target = stoi(argv[3]);
    int *arr = create_array(n, offset);
    if(string(argv[4]) == "-bin"){
        int index = binary_search(arr, n, target);
        if(index == -1){
            cout << "Target integer not found" << endl;
        }else{
            cout << "Target integer found at index: " << index << endl;
        }
    }else if(string(argv[4]) == "-lin"){
        int index = linear_search(arr, n, target);
        if(index == -1){
            cout << "Target integer not found" << endl;
        }else{
            cout << "Target integer found at index: " << index << endl;
        }
    } else if(string(argv[4]) == "-algolin"){
        //so find is a linear search algorithm
        auto it = find(arr, arr + n, target);
        if(it == arr + n){
            cout << "Target integer not found" << endl;
        }else{
            cout << "Target integer found at index: " << it - arr << endl; //pointer arithmetic
        }
    } else if (string(argv[4]) == "-algobin"){
        //so binary_search is a binary search algorithm
        auto it = binary_search(arr, arr + n, target);
        if(it){
            cout << "Target integer " << target << "found" << endl;
            //to get index we need to use different function since binary_search returns a boolean
        }else{
             cout << "Target integer not found" << endl;
        }
    }
    else{
        cout << "Invalid search type ??:" << argv[4] << endl;
    }
    // int index = linear_search(arr, n, target);
    // if(index == -1){
    //     cout << "Target integer not found" << endl;
    // }else{
    //     cout << "Target integer found at index: " << index << endl;
    // }
    delete_array(arr);
    return 0;
}