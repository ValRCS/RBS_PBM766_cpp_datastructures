//let's implement a closed hashing data structure
//it will be unordered
//it will use fixed size
//for collisiions we will use quadratic probing
//keys will be integers
//values will be strings
//TODO generic later

#include <iostream>
#include <string>

using namespace std;

class ClosedHashing {
    private:
        int size;
        int* keys;
        string* values;
        int capacity;
        int count;
        int hash(int key) {
            return key % size;
        }
        int probe(int key, int i) {
            return (hash(key) + i * i) % size;
            //replace i*i with a function call to some probing function such as 2nd hash function
        }
    public:
        ClosedHashing(int size) {
            this->size = size;
            keys = new int[size];
            values = new string[size];
            capacity = size;
            count = 0;
            for (int i = 0; i < size; i++) {
                keys[i] = -1;
                values[i] = "";
            }
        }
        ~ClosedHashing() {
            delete[] keys;
            delete[] values;
        }
        void insert(int key, string value) {
            if (count == capacity) {
                cout << "Hash table is full" << endl;
                return;
            }
            int i = 0;
            int index = probe(key, i);
            while (keys[index] != -1) {
                i++;
                index = probe(key, i);
            }
            keys[index] = key;
            values[index] = value;
            count++;
        }
        string search(int key) {
            int i = 0;
            int index = probe(key, i);
            while (keys[index] != key && keys[index] != -1) {
                i++;
                index = probe(key, i);
            }
            if (keys[index] == key) {
                return values[index];
            }
            return "";
        }
        void remove(int key) {
            int i = 0;
            int index = probe(key, i);
            while (keys[index] != key && keys[index] != -1) {
                i++;
                index = probe(key, i);
            }
            if (keys[index] == key) {
                keys[index] = -1;
                values[index] = "";
                count--;
            }
        }
        void display() {
            for (int i = 0; i < size; i++) {
                if (keys[i] != -1) {
                    cout << "Key: " << keys[i] << " Value: " << values[i] << endl;
                }
            }
        }
};

//let's see our closed hashing in action

int main () {
    ClosedHashing closedHashing(13); //13 is prime number good for hashing table
    closedHashing.insert(1, "One");
    closedHashing.insert(2, "Two");
    closedHashing.insert(15, "Fifteen"); //collision
    closedHashing.insert(28, "Twenty Eight");

    closedHashing.display();

    cout << "Search for 5: " << closedHashing.search(5) << endl;
    cout << "Search for 28: " << closedHashing.search(28) << endl;
    closedHashing.remove(5);
    closedHashing.remove(28);
    closedHashing.display();
    return 0;
}