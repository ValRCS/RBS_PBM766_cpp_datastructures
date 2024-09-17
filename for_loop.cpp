//so philosophically speaking
//we use for loops when we know how many times we need to loop
//we use while loops when we do not know how many times we need to loop

#include <iostream>

//let's make a function to find nth Fibonacci number
//Fibonacci numbers are 0 1 1 2 3 5 8 13 21 34 55 89 144 ...
//sometimes we start with 1 1 2 3 5 8 13 21 34 55 89 144 ...

//the function will take an integer n and return the nth Fibonacci number
//so 0th Fibonacci number is 0
//1st Fibonacci number is 1
//2nd Fibonacci number is 1
//3rd Fibonacci number is 2
//4th Fibonacci number is 3
//5th Fibonacci number is 5
//6th Fibonacci number is 8

long int getFibonacci(int n) {
    //let's declare two variables to store the previous two Fibonacci numbers
    //naming could have been better than a, b, c 
    //for small functions this is acceptable, but not for larger functions
    long int a = 0;
    long int b = 1;

    //let's declare a variable to store the current Fibonacci number
    long int c;

    //let's start a loop
    //we will loop n times
    for (int i = 0; i < n; i++) {
        //the current Fibonacci number is the sum of the previous two Fibonacci numbers
        c = a + b;

        //the previous two Fibonacci numbers are updated
        a = b;
        b = c;
    }

    //let's return the nth Fibonacci number
    return a;
}

//now let's write a main function to test this function
//we will use a loop to print the first n Fibonacci numbers
//we will get the number from arguments
//we will use default 10 if no arguments are provided
int default_n = 10;

int main(int argc, char *argv[]) {
    //set n to default_n if no arguments are provided
    int n = default_n;
    if (argc > 1) {
        n = std::stoi(argv[1]); //convert the first argument to an integer
        std::cout << "n is: " << n << std::endl;
    }

    //let's output a message to the user
    std::cout << "Let's find the first " << n << " Fibonacci numbers!" << std::endl;


    //let's start a loop
    //we will loop 10 times
    for (int i = 0; i < n; i++) { //i is local to the loop, not available outside the loop
        //let's get the ith Fibonacci number
        long int fibonacci = getFibonacci(i); //what is the complexity of this function?

        //let's output the ith Fibonacci number
        std::cout << "The " << i << "th Fibonacci number is: " << fibonacci << std::endl;
    }
    //think how we could have made this function more optimal
    //let's output a message to the user
    std::cout << "Thanks for playing!" << std::endl;

    //let's return 0 to indicate success
    return 0;
}

//note how in this version we are not using namespace std 
//so we had to keep using std::cout, std::endl etc