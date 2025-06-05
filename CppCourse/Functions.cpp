#include "Functions.h"
using namespace std;

namespace Functions {
    // Simple function: adds two numbers.
    int add(int a, int b) {
        return a + b;
    }

    // Function with default parameter: multiplies a by b (default b = 2).
    int multiply(int a, int b = 2) {
        return a * b;
    }

    // Recursive function: computes factorial of n.
    int factorial(int n) {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    }

    // Demonstrates lambda functions.
    void lambdaFunctions() {
        // Define a lambda to compute the square of a number.
        // []         - Capture list (empty here, so no outside variables are used).
        // (int x)    - Parameter list: takes an integer x.
        // -> int     - Return type: returns an integer.
        // { return x * x; } - Function body: returns the square of x.
        auto square = [](int x) -> int {
            return x * x;
            };
        cout << "Square of 5: " << square(5) << endl;

        // Create a vector of integers.
        vector<int> nums = { 1, 2, 3, 4, 5 };

        // Initialize a sum variable to accumulate values.
        int sum = 0;

        // Define a lambda that adds a number to 'sum'.
        // [&sum]    - Capture list: captures 'sum' by reference so changes affect the original variable.
        // (int x)   - Parameter list: takes an integer x.
        // { sum += x; } - Function body: adds the value of x to sum.
        auto addToSum = [&sum](int x) {
            sum += x;  // Each call to this lambda adds the passed value to 'sum'
            };

        // Iterate over the vector and apply the lambda to each element.
        for (int num : nums) {
            addToSum(num); // This updates 'sum' with each element's value.
        }
        cout << "Sum of vector elements: " << sum << endl;
    }

    // Special inline lambda example: checks if numbers are even.
    void inlineLambdaExample() {
        auto isEven = [](int n) { return n % 2 == 0; };
        for (int i = 0; i < 10; i++) {
            cout << i << " is " << (isEven(i) ? "even" : "odd") << endl;
        }
    }

    // Special inline lambda example: checks if numbers are even using capture.
    void inlineLambdaExampleCapture() {
        string even;
        for (int i = 0; i < 10; i++) {
            auto setParity = [&even](int n) { even = (n % 2 == 0) ? "even" : "odd"; };
            setParity(i);
            cout << i << " is " << even << endl;
        }
    }

    void run() {
        cout << "Add: 3 + 4 = " << add(3, 4) << endl;
        cout << "Multiply (default): 3 * 2 = " << multiply(3) << endl;
        cout << "Multiply: 3 * 5 = " << multiply(3, 5) << endl;
        cout << "Factorial of 5: " << factorial(5) << endl;
        lambdaFunctions();
        inlineLambdaExample();
        inlineLambdaExampleCapture();
    }
}
