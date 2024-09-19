// let's have some fun with functions

#include <iostream>
#include <limits.h> //for INT_MIN and also INT_MAX
// math for abs function
#include <cmath>

// i am going to declare my_abs function first
int my_abs(int x); // so we can call this also function prototype or signature
// let's declare my_max function for doubles
double my_max(double x, double y);

int main() {
  int x = -5;
  // abs is a function that returns the absolute value of a number
  std::cout << "Absolute value of " << x << " is: " << abs(x) << std::endl;
  // let's compare ours
  std::cout << "Absolute value of " << x << " is: " << my_abs(x) << std::endl;
  // there is an issue with INT_MIN in 2 complement representation
  // there is no positive equivalent of INT_MIN, INT_MAX is 1 less than INT_MIN
  // so C++ has undefined behavior when abs(INT_MIN) is called
  // let's see if we can launch a spaceship with this
  int y = INT_MIN;
  // WARNING next is undefined behavior so should not be used
  std::cout << "Absolute value of " << y << " is: " << abs(y) << std::endl;
  // let's compare ours
  std::cout << "Absolute value of " << y << " is: " << my_abs(y) << std::endl;

  // even though it is obvious here we should also test my_abs with INT_MAX also
  // some positive int and also 0
  int z = INT_MAX;
  std::cout << "Absolute value of " << z << " is: " << abs(z) << std::endl;
  std::cout << "Absolute value of " << z << " is: " << my_abs(z) << std::endl;
  int zero = 0;
  std::cout << "Absolute value of " << zero << " is: " << abs(zero)
            << std::endl;
  std::cout << "Absolute value of " << zero << " is: " << my_abs(zero)
            << std::endl;
  int positive = 5;
  std::cout << "Absolute value of " << positive << " is: " << abs(positive)
            << std::endl;
  std::cout << "Absolute value of " << positive << " is: " << my_abs(positive)
            << std::endl;

  // let's do one test on my_max
  double a = 5.0;
  double b = 3.0;
  std::cout << "Max of " << a << " and " << b << " is: " << std::max(a, b)
            << std::endl;
  std::cout << "Max of " << a << " and " << b << " is: " << my_max(a, b)
            << std::endl;
  // again for full test we would want to cover cases where a == b, a > b, a < b
  return 0;
}

// now let's write my_abs function
int my_abs(int x) {
  if (x < 0) {
    return -x;
  }
  // we could have added an else here but it is not necessary
  return x;
}

// now let's write my_max function
double my_max(double x, double y) {
  // for education use we will use a local variable max
  double max = x; // so we start with an assumption that x is the max
  // alternative approach would have been use if else and set max to y if y > x
  // else set max to x
  if (y > x) {
    max = y;
  }
  return max; // so max as an identifier goes out of scope here but it is
              // returned so it is not destroyed
}