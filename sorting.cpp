//let's explore some different ways of sorting
//let's start by using built in sort function

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono> //for timing

using namespace std;

//let's make a function to create a vector of n random integers
vector<int> create_vector(size_t n){
    vector<int> vec(n);
    for(size_t i = 0; i < n; i++){
        vec[i] = rand(); //RAND_MAX is the maximum value that rand() can return
        //typically RAND_MAX is 32767 could be bigger not smaller
        // https://en.cppreference.com/w/c/numeric/random/RAND_MAX
        //rand is not high quality random number generator
        //for better random number generation we can use <random> library
        //to get bigger random numbers we can use rand() * RAND_MAX + rand()
    }
    return vec;
}

//let's make a function to delete the vector
// void delete_vector(vector<int> &vec){
//     vec.clear();
// }
//vectors have their own destructor so we don't need to delete them explicitly

//let's make our main we will take in the size of the vector and the sorting algorithm to use

int main(int argc, char *argv[]){
    if(argc != 3){
        cout << "Usage: " << argv[0] << " <size of vector> <-sort|-stable_sort|-partial_sort|-nth_element|-sort_heap|-sort_heap|-sort_heap|-sort_heap>" << endl;
        return 1;
    }
    size_t n = stoi(argv[1]);
    //let's time how long it takes to create random vector
    auto start = chrono::high_resolution_clock::now();
    vector<int> vec = create_vector(n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Time taken to create vector: " << elapsed.count() << " seconds" << endl;
    if(string(argv[2]) == "-sort"){
        auto start = chrono::high_resolution_clock::now();
        sort(vec.begin(), vec.end());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Time taken to sort: " << elapsed.count() << " seconds" << endl;
    }else if(string(argv[2]) == "-stable_sort"){ //so we use stable for complex objects
    //where order of equal elements is preserved
        auto start = chrono::high_resolution_clock::now();
        stable_sort(vec.begin(), vec.end());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Time taken to stable_sort: " << elapsed.count() << " seconds" << endl;
    }else if(string(argv[2]) == "-partial_sort"){
        auto start = chrono::high_resolution_clock::now();
        partial_sort(vec.begin(), vec.begin() + n/2, vec.end());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Time taken to partial_sort: " << elapsed.count() << " seconds" << endl;
    }else if(string(argv[2]) == "-nth_element"){
        auto start = chrono::high_resolution_clock::now();
        nth_element(vec.begin(), vec.begin() + n/2, vec.end());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Time taken to nth_element: " << elapsed.count() << " seconds" << endl;
    }else if(string(argv[2]) == "-sort_heap"){
        auto start = chrono::high_resolution_clock::now();
        make_heap(vec.begin(), vec.end());
        sort_heap(vec.begin(), vec.end());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Time taken to sort_heap: " << elapsed.count() << " seconds" << endl;
    }else if(string(argv[2]) == "-partial_sort"){
        auto start = chrono::high_resolution_clock::now();
        partial_sort(vec.begin(), vec.begin() + n/2, vec.end());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Time taken to partial_sort: " << elapsed.count() << " seconds" << endl;
    } else {
        cout << "Invalid sorting algorithm ??:-> " << argv[2] << endl;
    }

    return EXIT_SUCCESS;
}