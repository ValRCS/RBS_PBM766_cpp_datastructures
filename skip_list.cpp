//let's build a skip list for integers
//we will use existing doubly linked list to build the skip list
//we will use random number generator to decide the level of the node

#include <iostream>
// #include <list>
// #include <algorithm>
#include <random>
#include <climits>

using namespace std;

//let's make a Node first
class Node {
public:
    int val;
    int level;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
    Node(int val, int level = 1) {
        this->val = val;
        next = nullptr;
        prev = nullptr;
        up = nullptr;
        down = nullptr;
        this->level = level;
    }
};

class SkipList {
private:
    Node* head;
    Node* tail;
    int level;
public:
    SkipList() {
        this->level = 1;
        this->head = new Node(INT_MIN, this->level);
        this->tail = new Node(INT_MAX, this->level);
        this->head->next = tail;
        this->tail->prev = head;
        
    }

    void insert(int val) {
        //FIXME the higher level nodes are not getting correct level numbers
        Node* cur = head;
        Node* next = nullptr;
        while (cur) {
            next = cur->next;
            if (next && next->val < val) {
                cur = next;
            } else {
                if (cur->down) {
                    cur = cur->down;
                } else {
                    break;
                }
            }
        }
        Node* newNode = new Node(val, this->level);
        newNode->next = cur->next;
        cur->next = newNode;
        newNode->prev = cur;
        if (newNode->next) {
            newNode->next->prev = newNode;
        }
        int curLevel = 1;
        while (rand() % 2 == 0) {
            curLevel++;
        }
        if (curLevel > level) {
            level++;
            Node* newHead = new Node(INT_MIN, level);
            Node* newTail = new Node(INT_MAX, level);
            newHead->next = newTail;
            newTail->prev = newHead;
            newHead->down = head;
            newTail->down = tail;
            head = newHead;
            tail = newTail;
        }
        Node* down = newNode;
        Node* prev = newNode;
        while (--curLevel) {
            while (prev->prev && !prev->up) {
                prev = prev->prev;
            }
            if (prev->prev) {
                prev = prev->prev;
                Node* newUp = new Node(val, prev->level);
                newUp->down = down;
                newUp->next = prev->next;
                prev->next = newUp;
                newUp->prev = prev;
                if (newUp->next) {
                    newUp->next->prev = newUp;
                }
                down->up = newUp;
                down = newUp;
            } else {
                Node* newHead = new Node(INT_MIN, level);
                Node* newTail = new Node(INT_MAX, level);
                newHead->next = newTail;
                newTail->prev = newHead;
                newHead->down = head;
                newTail->down = tail;
                head = newHead;
                tail = newTail;
                Node* newUp = new Node(val, prev->level);
                newUp->down = down;
                newUp->next = newHead->next;
                newHead->next = newUp;
                newUp->prev = newHead;
                if (newUp->next) {
                    newUp->next->prev = newUp;
                }
                down->up = newUp;
                down = newUp;
            }
        }
    }

    void remove(int val) {
        Node* cur = head;
        Node* next = nullptr;
        while (cur) {
            next = cur->next;
            if (next && next->val < val) {
                cur = next;
            } else {
                if (next && next->val == val) {
                    cur->next = next->next;
                    if (next->next) {
                        next->next->prev = cur;
                    }
                    Node* temp = next;
                    while (temp->up) {
                        temp = temp->up;
                        temp->prev->next = temp->next;
                        if (temp->next) {
                            temp->next->prev = temp->prev;
                        }
                    }
                    delete next;
                    break;
                } else {
                    if (cur->down) {
                        cur = cur->down;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    bool search(int val) {
        Node* cur = head;
        Node* next = nullptr;
        while (cur) {
            next = cur->next;
            if (next && next->val < val) {
                cur = next;
            } else {
                if (next && next->val == val) {
                    return true;
                } else {
                    if (cur->down) {
                        cur = cur->down;
                    } else {
                        break;
                    }
                }
            }
        }
        return false;
    }

    void print() {
        Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            while (next) {
                cout << next->val << "L:" << next->level << " ";
                next = next->next;
            }
            cout << endl;
            cur = cur->down;
        }
    }

    ~SkipList() {
        Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            while (next) {
                Node* temp = next;
                next = next->next;
                delete temp;
            }
            Node* temp = cur;
            cur = cur->down;
            delete temp;
        }
    }

};

//let's see if this actually works

//we will provide some numbers in command line arguments

int main(int argc, char* argv[]) {
    //lets setup random seed
    srand(time(0));

    SkipList* sl = new SkipList();
    for (int i = 1; i < argc; i++) {
        sl->insert(atoi(argv[i])); //we assume we will provide integers
    }
    sl->print();
    //let's see if 20 is found
    cout << "Is 20 there? " << sl->search(20) << endl;
    cout << "Is 50 there? " << sl->search(50) << endl;
    //let's insert 50
    sl->insert(50);
    //check again
    cout << "Is 50 there? " << sl->search(50) << endl;
    //remove 20
    sl->remove(20);
    //check again
    cout << "Is 20 there? " << sl->search(20) << endl;
    //finally print the list
    sl->print();
    // cout << sl->search(atoi(argv[1])) << endl;
    // cout << sl->search(atoi(argv[argc - 1])) << endl;
    // sl->remove(atoi(argv[1]));
    // sl->remove(atoi(argv[argc - 1]));
    // sl->print();
    // cout << sl->search(atoi(argv[1])) << endl;
    // cout << sl->search(atoi(argv[argc - 1])) << endl;
    delete sl;
    return 0;
}