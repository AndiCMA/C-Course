#include "StructuresClasses.h"
#include <iostream>

namespace StructuresClasses {

    // Rule of Three implementations.
    RuleOfThree::RuleOfThree(int value) : data(new int(value)) {}
    RuleOfThree::RuleOfThree(const RuleOfThree& other) : data(new int(*other.data)) {}
    RuleOfThree& RuleOfThree::operator=(const RuleOfThree& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
    RuleOfThree::~RuleOfThree() { delete data; }

    // Rule of Five implementations.
    RuleOfFive::RuleOfFive(int value) : data(new int(value)) {}
    RuleOfFive::RuleOfFive(const RuleOfFive& other) : data(new int(*other.data)) {}
    RuleOfFive& RuleOfFive::operator=(const RuleOfFive& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
    RuleOfFive::RuleOfFive(RuleOfFive&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }
    RuleOfFive& RuleOfFive::operator=(RuleOfFive&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
    RuleOfFive::~RuleOfFive() { delete data; }

    // Base1 and Base2 implementations.
    void Base1::base1Func() {
        std::cout << "Base1 function" << std::endl;
    }
    void Base2::base2Func() {
        std::cout << "Base2 function" << std::endl;
    }

    // DerivedMultiple implementation.
    void DerivedMultiple::show() {
        std::cout << "DerivedMultiple calling:" << std::endl;
        base1Func();
        base2Func();
    }

    // BaseDiamond implementation.
    void BaseDiamond::greet() {
        std::cout << "Hello from BaseDiamond" << std::endl;
    }

    // DiamondChild implementation.
    void DiamondChild::speak() {
        std::cout << "DiamondChild says: ";
        greet(); // Unambiguous due to virtual inheritance.
        std::cout << std::endl;
    }

    // Overloaded functions implementations.
    void overloadedFunc(int a) {
        std::cout << "Overloaded with int: " << a << std::endl;
    }
    void overloadedFunc(double a) {
        std::cout << "Overloaded with double: " << a << std::endl;
    }
    void overloadedFunc(const std::string& a) {
        std::cout << "Overloaded with string: " << a << std::endl;
    }

    // Run demo.
    void run() {
        std::cout << "=== Structures and Classes Demo ===" << std::endl;

        // Structure (Rule of Zero)
        Point pt{ 10, 20 };
        std::cout << "Point: (" << pt.x << ", " << pt.y << ")" << std::endl;

        // Rule of Three demonstration.
        RuleOfThree r3(42);
        RuleOfThree r3copy = r3;
        std::cout << "RuleOfThree data: " << *r3copy.data << std::endl;

        // Rule of Five demonstration.
        RuleOfFive r5(100);
        RuleOfFive r5m = std::move(r5);
        std::cout << "RuleOfFive data after move: " << (r5m.data ? *r5m.data : 0) << std::endl;

        // Multiple Inheritance demonstration.
        DerivedMultiple dm;
        dm.show();

        // Diamond Inheritance demonstration.
        DiamondChild dc;
        dc.speak();

        // Overloaded functions demonstration.
        overloadedFunc(10);
        overloadedFunc(3.14);
        overloadedFunc("Overload example");

        // Template add demonstration.
        std::cout << "Template add (int): " << add(5, 7) << std::endl;
        std::cout << "Template add (double): " << add(2.5, 3.5) << std::endl;
    }
}
