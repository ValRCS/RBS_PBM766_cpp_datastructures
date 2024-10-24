//let's explore how assert works in c++

#include <iostream>
// #define NDEBUG //comment this line to turn ON assert
#include <cassert> //this is the header file for assert
//wiki https://en.wikipedia.org/wiki/Assert.h claims cassert is functionally equivalent to assert.h
//thus you could have used #include <assert.h> instead of #include <cassert>

//turn off assert by defining NDEBUG
//this is useful when you want to turn off all the assert statements in the code
//this is useful when you are running the code in production

//assert should be used for basic sanity checks in the code
//assert should not be used for input validation
//assert should not be used for error handling



using namespace std;

//let's create a simple add function
int add(int a, int b) {
    return a + b;
}

//now we will assert some basic conditions in the main function

int main() {
    //assert is a macro that is used to test assumptions in the code
    //if the condition is true, nothing happens
    //if the condition is false, the program is terminated
    //assert is a debugging tool, it is not used in production code
    //assert is defined in the cassert header file
    //assert is used to check for bugs in the code
    //assert is used to check for conditions that should never happen
    //assert is used to check for conditions that are not expected

    //let's assert that 1 + 1 is equal to 2
    assert(add(1, 1) == 2); //nothing will happen because the condition is true

    //let's add a condition that is false
    assert(add(1, 1) == 3); //the program will terminate here because the condition is false
    //1 + 1 == 3 for large values of 1, as the joke goes

    //let's write some more assertions
    assert(add(2, 2) == 4); //nothing will happen because the condition is true
    //you usually want to test edge cases with assert
    //edge cases are the minimum and maximum values that the function can take
    //edge cases are the values that are at the boundary of the input space
    //also values such as 1 or 0 are considered edge cases
    //edge cases are the values that are most likely to cause bugs in the code

    //let's do more more assertion with extreme values
    assert(add(0, 0) == 0); //nothing will happen because the condition is true
    assert(add(1000000000, 1000000000) == 2000000000); //nothing will happen because the condition is true
    //above still fits in the int range
    //assert(add(10000000000, 10000000000) == 20000000000); //this will fail because the result is too large for int
    //you could test things like maximum int value, minimum int value, etc
    //but then you would have to decide what to do if the assertion fails
    //is it a bug in the code or is it an edge case that you need to handle
}