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

//let's create a class that will simulate big numbers
class BigNumber{
    //we will use vector to store digits of the number
    vector<int> digits;
    //we will also store the sign of the number
    bool isPositive;
    //we will also store the base of the number
    // int base; //we will use base 10 actually for simplicity //TODO add multiple base support later
    //we will also store the number of digits
    size_t num_digits;
    

public:
    //first let's make a constructor that takes in string of digits
    BigNumber(string number){
        //we will need to check if the number is negative
        if(number[0] == '-'){
            isPositive = false;
            //we will need to remove the negative sign
            number = number.substr(1);
        } else {
            isPositive = true;
        }
        //we will need to store the number of digits
        num_digits = number.size();
        //we will need to store the digits in reverse order
        for(size_t i = 0; i < num_digits; i++){
            digits.push_back(number[num_digits - i - 1] - '0'); //we are converting char to int
        }
    }

    //we will need a helper function to add two numbers
    BigNumber add(BigNumber &other){
        //we need to start with first digit and simply add the digits
        //and we would implement carry
        //we will need to check if the numbers are of the same sign
        //if signs are different, we will need to subtract the numbers
        
        //lets start with easy case when both numbers are positive
        //so we loop from first digits and simply keep track of carry until we reach the end of one the numbers
        //if one number is longer, we will need to add the rest of the digits
        
        //lets set up carry
        int carry = 0;
        //new number will be stored in this vector
        vector<int> new_digits;
        //now simply loop through the digits and add them starting from the first digit
        for(size_t i = 0; i < num_digits || i < other.num_digits; i++){
            //we will need to add the digits and carry
            int sum = carry;
            //we will need to check if we have digits in the first number
            if(i < num_digits){
                sum += digits[i];
            }
            //we will need to check if we have digits in the second number
            if(i < other.num_digits){
                sum += other.digits[i];
            }
            //we will need to calculate the carry
            carry = sum / 10;
            //we will need to calculate the digit
            new_digits.push_back(sum % 10);
        }
        //we will need to check if we have carry left
        if(carry){
            new_digits.push_back(carry);
        }
        //we will need to update the number of digits
        num_digits = new_digits.size();
        //now we need to create a new BigNumber object using the new digits
        //lets convert the vector to string
        string new_number = "";
        for(size_t i = 0; i < num_digits; i++){
            new_number += to_string(new_digits[num_digits - i - 1]); //this might not be efficient
        }
        //we will need to return a new BigNumber object 
        return BigNumber(new_number);
    }

    //we want to create friend function for cout to print the number
    friend ostream& operator<<(ostream &os, const BigNumber &number){
        //we will need to print the sign
        if(!number.isPositive){
            os << "-";
        }
        //we will need to print the digits in reverse order
        for(size_t i = 0; i < number.num_digits; i++){
            os << number.digits[number.num_digits - i - 1];
        }
        return os;
    }
};

//lets start with recursive factorial
long factorial(long n){
    //our base case
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
    return fibonacci(n-1) + fibonacci(n-2); //so this part without optimization is O(2^n)
    //the tree of recursive calls grows exponentially
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
        return memo[n]; //this is what saves us from exponential growth
    }
    //if not, calculate it and store it in memo
    memo[n] = fibonacci_memo(n-1, memo, memo_size) + fibonacci_memo(n-2, memo, memo_size);
    //this is very dangerous if we do not know how big our array is
    return memo[n];
}

//let's create a tail recursive solution to fibonacci for better performance
//we will need a helper function to wrap the tail recursive function
//let's start with the actual tail recursive function

//tail recursive solutions can be optimized by the compiler to loops
//it optimizes the stack space - often reusing the same stack frame from the previous call

long fibonacci_tail_recursive(long n, long a, long b){
    //first we have two base cases
    if(n == 0){
        return a;
    }
    if(n == 1){
        return b;
    }
    //key property of tail recursive function is that it only calls itself at the very end
    //the compiler can optimize this to a loop
    return fibonacci_tail_recursive(n-1, b, a+b); //note only one recursive call!
    //thus we can avoid stack overflow
    //also we get O(n) complexity for the cost of storing some variables
}

//we also need a wrapper function to call the tail recursive function
long fibonacci_tail_recursive_wrapper(long n){
    return fibonacci_tail_recursive(n, 0, 1); // in essence we initialize a=0 and b=1
}

//let's create a simple loop based fibonacci function
long fibonacci_loop(long n){
    //first we have two base cases
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    long a = 0;
    long b = 1;
    long c;
    for(size_t i = 2; i <= size_t(n); i++){
        //we are using a temporary variable to store the sum to swap values
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(int argc, char const *argv[]){
    // cout << factorial(5) << endl;
    //we need two arguments -f and number to calculate factorial
    if(argc != 3){
        cout << "Usage: " << argv[0] << " -fact <number>" << endl;
        cout << "Usage: " << argv[0] << " -fib <number>" << endl;
        cout << "Usage: " << argv[0] << " -fibmemo <number>" << endl;
        cout << "Usage: " << argv[0] << " -fibtail <number>" << endl;
        cout << "Usage: " << argv[0] << " -fibloop <number>" << endl;
        cout << "Usage: " << argv[0] << " -big <number>" << endl;
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
    } else if (arg == "-fibtail"){
        cout << fibonacci_tail_recursive_wrapper(n) << endl;
    } else if (arg == "-fibloop"){
        cout << fibonacci_loop(n) << endl;
    } else if (arg == "-big"){
        string argument = argv[2];
        // BigNumber big_number("1234556"); //we need to convert from char*(C style string) to string (C++ style string)
        BigNumber big_number(argument); //we need to convert from char*(C style string) to string (C++ style string)
        cout << big_number << endl;
        BigNumber big_number2("1234556");
        BigNumber result = big_number.add(big_number2);
        cout << result << endl;
    } else { 
        cout << "Usage: " << argv[0] << " -f <number>" << endl;
        //lets return error code
        return EXIT_FAILURE;
    }

    //return success code
    return EXIT_SUCCESS;
}