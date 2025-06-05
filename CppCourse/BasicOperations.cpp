#include "BasicOperations.h"

using namespace std;

namespace BasicOperations {

    void staticDataTypes() {
        // int: integer with values from -2,147,483,648 to 2,147,483,647
        int integer = 0;

        // signed char: at least 8 bits, range from -128 to 127
        signed char schar = 0;

        // unsigned char: at least 8 bits, range from 0 to 255
        unsigned char uchar = 0;

        // short (or short int, signed short, signed short int): at least 16 bits, range from -32768 to 32767
        short s = 0;
        short int s_int = 0;
        signed short ss = 0;
        signed short int ssi = 0;

        // unsigned short (or unsigned short int): at least 16 bits, range from 0 to 65535
        unsigned short us = 0;
        unsigned short int usi = 0;

        // signed int (same as int): at least 16 bits, typically 32 bits
        signed int sgn_int = 0;

        // unsigned int: at least 16 bits, typically 32 bits, range from 0 to 4,294,967,295
        unsigned int u_int = 0;

        // long (or long int, signed long, signed long int): at least 32 bits, range typically -2,147,483,648 to 2,147,483,647 (or more)
        long l = 0;
        long int li = 0;
        signed long sl = 0;
        signed long int sli = 0;

        // unsigned long (or unsigned long int): at least 32 bits, range from 0 to 4,294,967,295 (or more)
        unsigned long ul = 0;
        unsigned long int uli = 0;

        // long long (or long long int, signed long long, signed long long int): at least 64 bits, range from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
        long long ll = 0;
        long long int lli = 0;
        signed long long sll = 0;
        signed long long int slli = 0;

        // unsigned long long (or unsigned long long int): at least 64 bits, range from 0 to 18,446,744,073,709,551,615
        unsigned long long ull = 0;
        unsigned long long int ulli = 0;

        // Simple demonstration of an operation:
        integer = 5;
        sgn_int = 10;
        cout << "Sum: " << integer << " + " << sgn_int << " = " << (integer + sgn_int) << endl;
    }

    void arithmeticOperators() {
        int a = 10, b = 3;  // Two integers for demonstration

        // Basic arithmetic operations:
        cout << "Addition: " << a << " + " << b << " = " << (a + b) << endl;    // +
        cout << "Subtraction: " << a << " - " << b << " = " << (a - b) << endl; // -
        cout << "Multiplication: " << a << " * " << b << " = " << (a * b) << endl; // *
        cout << "Division: " << a << " / " << b << " = " << (a / b) << endl;       // /
        cout << "Modulus: " << a << " % " << b << " = " << (a % b) << endl;       // %

        // Increment and Decrement operators (prefix versions):
        cout << "Increment: ++a = " << (++a) << endl;   // Increases a by 1
        cout << "Decrement: --a = " << (--a) << endl;   // Decreases a by 1

        // Compound assignment operators:
        a += 5; // Same as a = a + 5
        cout << "Compound Addition (a += 5): a = " << a << endl;
        a -= 2; // Same as a = a - 2
        cout << "Compound Subtraction (a -= 2): a = " << a << endl;
        a *= 3; // Same as a = a * 3
        cout << "Compound Multiplication (a *= 3): a = " << a << endl;
        a /= 4; // Same as a = a / 4
        cout << "Compound Division (a /= 4): a = " << a << endl;
        a %= 3; // Same as a = a % 3
        cout << "Compound Modulus (a %= 3): a = " << a << endl;
    }

    void logicalOperators() {
        int x = 10, y = 20;

        // Logical AND: true only if both conditions are true.
        if (x < y && y > 15)
            cout << "Both conditions true: x < y and y > 15" << endl;
        else
            cout << "At least one condition false." << endl;

        // Logical OR: true if at least one condition is true.
        if (x < y || x > 100)
            cout << "At least one condition true: x < y or x > 100" << endl;
        else
            cout << "Both conditions false." << endl;

        // Logical NOT: inverts the boolean value of the condition.
        if (!(x == y))
            cout << "x is not equal to y" << endl;
        else
            cout << "x equals y" << endl;

        // Inline if (ternary operator): condition ? value_if_true : value_if_false.
        int max = (x > y) ? x : y; // if x > y, max = x; otherwise, max = y.
        cout << "The greater value is " << max << endl;
    }

    void loops() {
        // For loop: iterates from 0 to 4
        for (int i = 0; i < 5; i++) {
            cout << "For loop iteration " << i << endl;
        }

        // While loop: executes while condition is true
        int j = 0;
        while (j < 5) {
            cout << "While loop iteration " << j << endl;
            j++;
        }

        // Do-while loop: runs at least once before checking the condition
        int k = 0;
        do {
            cout << "Do-while loop iteration " << k << endl;
            k++;
        } while (k < 5);

        // Range-based for loop: iterates over all elements in a container
        vector<int> nums = { 10, 20, 30, 40, 50 };
        for (int num : nums) {
            cout << "Range-based loop value: " << num << endl;
        }

        // Loop using break and continue:
        // 'continue' skips the rest of the loop iteration when i == 3,
        // 'break' exits the loop when i == 7.
        for (int i = 0; i < 10; i++) {
            if (i == 3) continue;
            if (i == 7) break;
            cout << "Break/continue loop iteration: " << i << endl;
        }

        // Nested loops: Print a simple 3x3 multiplication table
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                cout << i << "x" << j << "=" << (i * j) << "\t";
            }
            cout << endl;
        }

        // Inline if (ternary operator) inside a loop:
        // Checks if a number is even or odd in each iteration.
        for (int i = 0; i < 5; i++) {
            cout << "Number " << i << " is " << ((i % 2 == 0) ? "even" : "odd") << endl;
        }
    }

    void run() {
        staticDataTypes();
        arithmeticOperators();
        logicalOperators();
        loops();
    }
}

