#include <iostream>
#include <math.h>
#include <valarray>
#include <string>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

// Declaring Functions
// Power of Two Functions
bool is_power_of_two_loop(int x); // loop ver.
bool is_power_of_two(int y); // non-loop ver.
void run_test_power_of_two_loop(int number, bool expecfted); // loop ver.
void run_test_power_of_two(int number, bool expected); // non-loop ver.

// Prime Number Functions
bool is_prime(int x);
void run_test_is_prime(int number, bool expected);

// Fraction Functions
std::string simplify_fraction(int num, int denom);
void run_test_simplify_fraction(int num, int denom, int expected_num, int expected_denom);
int find_GCD(int num, int denom);




int main() {
    // To Do: Check whether a number is a power of two using a loop method and non-loop method
    // Create test functions to verify it's correct

    // LOOP VERSION TEST CASES: PASSED
    std::cout << "Power of Two Loop Ver. Tests: " << std::endl;
    run_test_power_of_two_loop(1, true);
    run_test_power_of_two_loop(2, true);
    run_test_power_of_two_loop(3, false);
    run_test_power_of_two_loop(4, true);
    run_test_power_of_two_loop(5, false);
    run_test_power_of_two_loop(-1, false);

    std::cout << "\nPower of Two Non-Loop Ver. Tests:" << std::endl;
    // NON-LOOP VERSION TEST CASES: PASSED
    run_test_power_of_two_loop(1, true);
    run_test_power_of_two_loop(2, true);
    run_test_power_of_two_loop(3, false);
    run_test_power_of_two_loop(4, true);
    run_test_power_of_two_loop(5, false);
    run_test_power_of_two_loop(-1, false);

    std::cout << "\nPrime Number Tests: " << std::endl;
    // PRIME NUMBERS TEST CASES:
    run_test_is_prime(1, false);
    run_test_is_prime(2, true);
    run_test_is_prime(3, true);
    run_test_is_prime(4, false);
    run_test_is_prime(5, true);
    run_test_is_prime(-1, false);

    std::cout << "\nSimplify Fraction Test: " << std::endl;
    run_test_simplify_fraction(12, 16, 3, 4);
    run_test_simplify_fraction(6, 8, 3, 4);
    run_test_simplify_fraction(12, 18, 2, 3);
    run_test_simplify_fraction(9, 27, 1, 3);
    run_test_simplify_fraction(20, 40, 1, 2);
    run_test_simplify_fraction(3, 4, 3, 4);

} // end of main





// Function: Is this number a power of two? loop ver.
bool is_power_of_two_loop(int number) {

    // if statement if the number is less than two
    if (number <= 0) {
        return false;
    }

    while (true) {
        if (number == 1) { // if the number is one, then it is always power of 2
            return true;
        }

        if (number % 2 == 0) { // if the number modular two equals zero, it is a power of 2 and returns true
            return true;
        } else if (number % 2 != 0) { // if the number modular two doesn't equal zero, it is not a power of 2
            return false;
        }
    }
}

//Function: Is this number a power of two? Non-loop ver.
bool is_power_of_two(int number) {
    // if statement if the number is less than zero
    if (number <= 0) {
        return false;
    }

    // I had used ChatGPT to help me understand the concept of bitwise AND and lecture video to recall using binary
    bool result;
    result = (number & (number - 1)) == 0;

    return result;
}

//Function: is this number a prime number?
bool is_prime(int number) {

    // special cases for prime numbers 1 and 2
    if (number <= 1) {
        return false;
    }
    if (number == 2) {
        return true;
    }
    // if the number is divisible by two
    if (number % 2 == 0) {
        return false;
    }

    // for loop to loop through any possible divisors starting at the first prime number which is 3
    // a number is prime if it is not divisble by prime numbers up to the square root of the number and skipping even numbers
    for (int i = 3; i <= sqrt(number); i += 2) {
        // if statement to check if it is divisble by that prime number
        if (number % i == 0) {
            return false;
        }
    }
    return true; // else return true!
}

// Function: Simplifying the Fraction:
std::string simplify_fraction(int num, int denom) {
    // finding the gcd and dividing both the numerator and the denominator by the gcd
    int gcd = find_GCD(num, denom);
    int numerator = num / gcd;
    int denominator = denom / gcd;

    // changing the ints to be strings to then return a string result in the form of a fraction
    std::string string_num = std::to_string(numerator);
    std::string string_denom = std::to_string(denominator);

    // putting the strings together to form a fraction
    std::string result = string_num + "/" + string_denom;
    return result;
}

// Function: Finding the GCD
int find_GCD(int num, int denom) {
    while (denom != 0) {
        int temp = denom;
        denom = num % denom;
        num = temp;
    }
    return num;
}








// Test Cases for Function: is_power_of_two_loop
void run_test_power_of_two_loop(int number, bool expected) {
    // the result of the number
    bool result = is_power_of_two_loop(number);

    // if the result matches with the expectation, then it will print out pass or fail
    if (result == expected) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }
}

// Test cases for Function: is_power_of_two
void run_test_power_of_two(int number, bool expected) {
    // the result of the number
    bool result = is_power_of_two(number);

    // if the result matches with the expectation, then it will print out pass or fail
    if (result == expected) {
        std::cout << "PASSED" << std::endl;
    } else {
        std::cout << "FAILED" << std::endl;
    }
}

// Test cases for Function: is_prime
void run_test_is_prime(int number, bool expected) {
    // the result of the number
    bool result = is_prime(number);

    // if the result matches the expectation, then it will print out pass, else, false
    if (result == expected) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }
}

// Test cases for Function: simplify_fraction
void run_test_simplify_fraction(int num, int denom, int expected_num, int expected_denom) {
    // running the function and simplofying the fraction
    std::string str = simplify_fraction(num, denom);

    // changing the expected num and denom into strings
    std:: string string_num = std::to_string(expected_num);
    std:: string string_denom = std::to_string(expected_denom);

    // then putting those into fraction form
    std::string expected_str = string_num + "/" + string_denom;

    // if statement comparing whether or not the strings are the same, if they are then they pass!
    if (str == expected_str) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }
}



// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.