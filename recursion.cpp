//let's explore some recursive solutions to problems

#include <iostream>
//header for EXIT_SUCCESS and EXIT_FAILURE
#include <cstdlib>
//lets include regular string from C++ library
#include <string>
//let's include vector from C++ library
#include <vector> 
//we will use vector to simulate big numbers when calculating factorial

using namespace std;

//lets start with recursive factorial
long factorial(long n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
    //TODO explore why it goes to 0 around 65th factorial
    //it overflows around 39th factorial for long
}

//lets try to implement fibonacci
long fibonacci(long n){
    //first we have two base cases
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

//let's implement fibonacci with memoization
long fibonacci_memo(long n, long *memo, size_t memo_size){
    //first we have two base cases
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    //check if we have not gone over the memo size
    if(size_t(n) >= memo_size){
        cout << "Memo size is too small" << endl;
        cout << "Please increase it to at least " << n << endl;
        return EXIT_FAILURE;
    }

    //check if we have already calculated this value
    if(memo[n] != -1){
        return memo[n];
    }
    //if not, calculate it and store it in memo
    memo[n] = fibonacci_memo(n-1, memo, memo_size) + fibonacci_memo(n-2, memo, memo_size);
    //this is very dangerous if we do not know how big our array is
    return memo[n];
}

int main(int argc, char const *argv[]){
    // cout << factorial(5) << endl;
    //we need two arguments -f and number to calculate factorial
    if(argc != 3){
        cout << "Usage: " << argv[0] << " -fact <number>" << endl;
        cout << "Usage: " << argv[0] << " -fib <number>" << endl;
        cout << "Usage: " << argv[0] << " -fibmemo <number>" << endl;
        //lets return error code
        return EXIT_FAILURE;
    }
    //let's convert 2nd argument to normal string
    string arg = argv[1];

    // //now it is easier to check if it is factorial or fibonacci
    // if (arg == "-fact" || arg == "-fib"){
    //     cout << "Usage: " << argv[0] << " -f <number>" << endl;
    //     //lets return error code
    //     return EXIT_FAILURE;
    // }

    //convert the second argument to integer
    long n = atoi(argv[2]);
    if (arg == "-fact"){
        cout << factorial(n) << endl;
    } else if (arg == "-fib"){
        cout << fibonacci(n) << endl;
    } else if (arg == "-fibmemo"){
        //initialize memo array
        long memo[n+1]; //allocate memory for n+1 elements
        //initialize all values to -1
        for(size_t i = 0; i < size_t(n+1); i++){
            memo[i] = -1;
        }
        //initialize first two values
        memo[0] = 0;
        memo[1] = 1;
        cout << fibonacci_memo(n, memo, n+1) << endl;
    } else {
        cout << "Usage: " << argv[0] << " -f <number>" << endl;
        //lets return error code
        return EXIT_FAILURE;
    }

    //return success code
    return EXIT_SUCCESS;
}