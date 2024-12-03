//let's implement a trie data structure for english lowercase alphabets
//we will use a struct to represent a node in the trie
//each node will have a boolean flag to indicate if it is the end of a word
//then it will have an array of 26 pointers to represent the 26 lowercase alphabets
//the array index will serve as the index of the alphabet
//we will also have a constructor to initialize the node
//then we will have a Trie class to represent the trie data structure
//we will have a root node in the trie
//we will have a constructor to initialize the root node
//we will have a method to insert a word into the trie
//we will have a method to search for a word in the trie
//we will have a method to delete a word from the trie
//also we will add startsWith method to check if a prefix exists in the trie - not necessarily a word

#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

//let's start with a node in the trie
struct TrieNode {
    bool isEndOfWord;
    TrieNode* children[26]; //26 lowercase alphabets
    //so 0 will represent 'a', 1 will represent 'b' and so on
    //25 will represent 'z'
    //constructor to initialize the node
    TrieNode() {
        isEndOfWord = false;
        for (size_t i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

//now let's make Trie class
class Trie {
    TrieNode* root;
public:
    //constructor to initialize the root node
    Trie() {
        root = new TrieNode();
    }

    //method to insert a word into the trie
    void insert(string word) { //of course we could have used cstring instead of string
        TrieNode* current = root;
        for (size_t i = 0; i < word.size(); i++) {
            //we need to get the index of the alphabet
            //but we need to get lowercase alphabets only
            //so if we want to allow capital letters we need to convert them to lowercase
            //we can use tolower function from cctype
            size_t index = tolower(word[i]) - 'a'; //this is the trick to get the index of the alphabet

            // size_t index = word[i] - 'a'; //this is the trick to get the index of the alphabet
            
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    //method to search for a word in the trie
    bool search(string word) {
        TrieNode* current = root;
        for (size_t i = 0; i < word.size(); i++) {
            size_t index = tolower(word[i]) - 'a'; //this is the trick to get the index of the alphabet

            // size_t index = word[i] - 'a'; //same trick again to get the index of the alphabet
            //if at any point of traversal we encounter a nullptr we know we have not found the word
            if (current->children[index] == nullptr) {
                return false; //no way to continue
            }
            current = current->children[index];
        }
        return current->isEndOfWord; //so if we reach the end of the word we return the isEndOfWord flag
        //this means if that word exists in the trie we will return true
        //if it part of longer word but not a word just yet we will return false
    }

    //method to delete a word from the trie
    void deleteWord(string word) {
        deleteWordHelper(root, word, 0);
    }

    //helper method to delete a word from the trie
    bool deleteWordHelper(TrieNode* current, string word, size_t index) {
        if (index == word.size()) {
            //if we have reached the end of the word
            //we need to check if the current node is the end of the word
            //if it is not we return false
            if (!current->isEndOfWord) {
                return false;
            }
            //if it is we set the isEndOfWord flag to false
            current->isEndOfWord = false;
            //then we check if the current node has any children
            //if it does not we return true
            for (size_t i = 0; i < 26; i++) {
                if (current->children[i] != nullptr) {
                    return false;
                }
            }
            return true;
        }
        //if we have not reached the end of the word
        //we get the index of the alphabet
        size_t charIndex = word[index] - 'a';
        //we check if the current node has a child at that index
        if (current->children[charIndex] == nullptr) {
            return false; //no way to continue
        }
        //we recursively call the deleteWordHelper on the child node
        //if the child node returns true we delete the child node
        //and check if the current node has any children
        //if it does not we return true
        if (deleteWordHelper(current->children[charIndex], word, index + 1)) {
            delete current->children[charIndex];
            current->children[charIndex] = nullptr;
            for (size_t i = 0; i < 26; i++) {
                if (current->children[i] != nullptr) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    //now startsWith method to check if a prefix exists in the trie
    //it is just like search except we do not need to check if the current node is the end of the word
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (size_t i = 0; i < prefix.size(); i++) {
            size_t index = tolower(prefix[i]) - 'a'; //this is the trick to get the index of the alphabet

            // size_t index = prefix[i] - 'a'; //dangerous place we might get out of bounds
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return true; //we do not care whether the current node is the end of the word
    }

    //destructor to delete the trie
    ~Trie() {
        deleteTrie(root);
    }

    //helper method to delete the trie
    void deleteTrie(TrieNode* current) {
        if (current == nullptr) {
            return;
        }
        for (size_t i = 0; i < 26; i++) {
            deleteTrie(current->children[i]); //so we call recursively on the children and so on
        }
        delete current;
    }
};

//now let's test the trie
//we will insert some words from arguments

int main(int argc, char* argv[]) {
    Trie trie;
    for (int i = 1; i < argc; i++) {
        trie.insert(argv[i]); //we might need to cast to string here
    }

    //let's search for some words
    for (int i = 1; i < argc; i++) {
        cout << "Searching for " << argv[i] << ": " << trie.search(argv[i]) << endl;
    }

    //let's search for some words that do not exist
    vector<string> words = {"hello", "RBS", "this", "is", "a", "test"};
    for (auto word : words) {
        cout << "Searching for " << word << ": " << trie.search(word) << endl;
    }

    //TODO check deletion if it works properly
    
    // //let's delete some words
    // for (int i = 1; i < argc; i++) {
    //     trie.deleteWord(argv[i]);
    // }

    // //let's search for some words again
    // for (int i = 1; i < argc; i++) {
    //     cout << "Searching for " << argv[i] << ": " << trie.search(argv[i]) << endl;
    // }

    // //let's search for some words that do not exist again
    // for (auto word : words) {
    //     cout << "Searching for " << word << ": " << trie.search(word) << endl;
    // }

    // //let's test startsWith method
    // vector<string> prefixes = {"he", "wor", "thi", "is", "a", "tes"};
    // for (auto prefix : prefixes) {
    //     cout << "Checking if trie has prefix " << prefix << ": " << trie.startsWith(prefix) << endl;
    // }

    return 0;
}

//so relatively simple implementation of trie data structure
//downsize - large memory consumption

//TODO - implement trie with unordered_map
//TODO - implement trie with shared_ptr
//TODO - implement trie with unique_ptr