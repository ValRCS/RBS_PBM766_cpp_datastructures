//let's explore some containers, iterators and also algorithms in C++ STL - standard template library

#include <iostream>
//lets include algorithm for sort
#include <algorithm>
//let's start with vectors
#include <vector>
//now map container
#include <map> //this similar to dictionary in Python, HashMap in Java and C#, but this is ORDERED! so O(log n) operations
#include <unordered_map> //this is similar to HashMap in Java and C# but this is UNORDERED! so O(1) operations


using namespace std;

//let's initialize a vector with some values
//then we will iterate over the vector and print the values in reverse order

//let's make a generic function to print a vector
template <typename T>
void print_vector(const vector<T>& v) {
    //we use iterators to iterate over the vector
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    //let's create a vector of integers
    vector<int> v = {1, 2, 3, 4, 5};

  //let's iterate over a vector in forward order and then reverse order
  //classical approach
  for (size_t i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
    cout << endl;
  //auto approach
  for (auto it = v.begin(); it != v.end(); it++) {
    //to see the value we dereference the iterator
    cout << *it << " ";
  }

    cout << endl;

    //so now let's iterate in reverse order
    //classical approach
    for (size_t i = v.size(); i > 0; i--) { //careful with -- on size_t because it will wrap around to the maximum value
        cout << v[i-1] << " "; //again v[i] is basically dereferencing *(v.begin() + i)
    }

    cout << endl;

    //auto approach
    for (auto it = v.rbegin(); it != v.rend(); it++) { //so here ++ goes to the previous element not the next element
        cout << *it << " ";
    }

    cout << endl;

    //let's remove 3rd element from the vector
    v.erase(v.begin() + 2); //v.begin() + 2 is the iterator to the 3rd element  //this is O(n) operation !!
    //if you do frequent insertions and deletions, you should use a list instead of a vector
    //then at the end convert to vector if you need to do random access

    //let's print the vector again
    print_vector(v);

    //let's swap the first and last elements
    swap(v[0], v[v.size() - 1]); //this is O(1) operation
    //let's print the vector again
    print_vector(v);

    //let's sort the vector
    sort(v.begin(), v.end()); //this is O(n log n) operation
    //sort usually uses introsort which is a combination of quicksort, heapsort and insertion sort

    //let's print the vector again
    print_vector(v);

}