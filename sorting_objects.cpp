//let's demonstrate how we can use built in sorting algorithms to sort struct of Person objects

#include <iostream>
#include <algorithm>
#include <vector> //we will use vector to store our Person objects
#include <string>

using namespace std;

struct Person {
    string name;
    int age;

    //constructor - old style
    // Person::Person(string name, int age){
    //     this->name = name;
    //     this->age = age;
    // }

    //new style constructor - member initializer list
    Person(const string& name, int age) : name(name), age(age) {}

};

//let's make a function to create a vector of n random Person objects
//we will provide 26 possible names from Alice to Zelda
static const string names[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Heidi",
                                "Ivan", "Judy", "Kevin", "Linda", "Mallory", "Nancy", "Oscar", "Peggy",
                                "Quentin", "Romeo", "Sue", "Trent", "Ursula", "Victor",
                                 "Walter", "Xander", "Yvonne", "Zelda"};

vector<Person> create_vector(size_t n){
    // vector<Person> vec(n);
    //blank vector
    vector<Person> vec;
    for(size_t i = 0; i < n; i++){
        Person newPerson = Person(names[rand() % 26], rand() % 100); //random name and random age
        vec.push_back(newPerson);
    }
    return vec;
}


//now main and we will compare sort and stable_sort

int main(int argc, char *argv[]){
    if(argc != 3){
        cout << "Usage: " << argv[0] << " <size of vector> <-sort|-stable_sort|-sort_reverse|-stable_sort_reverse>" << endl;
        return 1;
    }
    size_t n = stoi(argv[1]);
    vector<Person> vec = create_vector(n);

    if(string(argv[2]) == "-sort"){
        //we will pass through anonymous lambda function to sort by age
        //we could have passed already defined function as well
        sort(vec.begin(), vec.end(), [](const Person &a, const Person &b){
            return a.age < b.age;
        });
    }else if(string(argv[2]) == "-stable_sort"){
        stable_sort(vec.begin(), vec.end(), [](const Person &a, const Person &b){
            return a.age < b.age;
        });
    }else if(string(argv[2]) == "-sort_reverse"){
        sort(vec.begin(), vec.end(), [](const Person &a, const Person &b){
            return a.age > b.age; //I switch the comparison operator
        });
    }else if(string(argv[2]) == "-stable_sort_reverse"){
        stable_sort(vec.begin(), vec.end(), [](const Person &a, const Person &b){
            return a.age > b.age; //I switch the comparison operator
        });
    }else{
        cout << "Invalid sorting algorithm" << endl;
        return 1;
    }
    for(size_t i = 0; i < n; i++){
        cout << vec[i].name << " " << vec[i].age << endl;
    }
    return 0;
}