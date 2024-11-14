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

//let's make a generic function to print a map
template <typename K, typename V>
void print_map(const map<K, V>& m) {
    //we use iterators to iterate over the map
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " : " << it->second << endl; //first is the key, second is the value
    }
    cout << endl;
}

//let's make a generic function to print an unordered map
template <typename K, typename V>
void print_map(const unordered_map<K, V>& m) {
    //we use iterators to iterate over the map
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " : " << it->second << endl; //first is the key, second is the value
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

    //let's shuffle the vector
    random_shuffle(v.begin(), v.end()); //this is O(n) operation

    //let's print the vector again
    print_vector(v);

    //let's create a map of char to int
    map<char, int> m; //again this is ORDERED! so O(log n) operations

    //let's create a map from characters in a string to their unicode values
    string s = "Valdis";
    for (size_t i = 0; i < s.size(); i++) {
        m[s[i]] = s[i]; //left side assignent is O(log n) operation, s[i] is O(1) operation of course    
    }
    //let's print the map
    print_map(m);

    //now let's create an unordered map that maps utf8 characters to their unicode values
    //we can not use char we have to use the utf8 string
    // unordered_map<string, int> um; //this is UNORDERED! so O(1) operations often we want this!
    //I will go back to ordered map for a moment
    map<string,int> um; //this is ORDERED! so O(log n) operations

    string utf8_string = "Spožā Rīga"; //this is a utf8 string
    // for (size_t i = 0; i < utf8_string.size(); i++) {
    //     //print what we are processing
    //     cout << "Processing" << utf8_string.substr(i, 1) << endl;
    //     string utf8_char = utf8_string.substr(i, 1); //this is a utf8 character
    //     um[utf8_char] = utf8_char[0]; //left side assignent is O(1) operation, utf8_char[0] is O(1) operation of course
    // }
    //above is not completely correct because utf8 characters can be more than one byte!

    // //let's use iterators to go over utf8 string
    // for (auto it = utf8_string.begin(); it != utf8_string.end(); it++) {
    //     //print what we are processing
    //     cout << "Processing" << utf8_string.substr(it - utf8_string.begin(), 1) << endl;
    //     string utf8_char = utf8_string.substr(it - utf8_string.begin(), 1); //this is a utf8 character
    //     um[utf8_char] = utf8_char[0]; //left side assignent is O(1) operation, utf8_char[0] is O(1) operation of course
    // }

    //let's iterate properly over utf8 string, we could have multiple bytes for one character


    //let's print the unordered map
    print_map(um); //it works now since we made a function that works with unordered_map


}