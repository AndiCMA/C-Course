#ifndef STRUCTURES_CLASSES_H
#define STRUCTURES_CLASSES_H

#include <iostream>
#include <string>
#include <utility>

namespace StructuresClasses {

    // Rule of Zero: Simple structure.
    struct Point {
        int x;
        int y;
    };

    // Rule of Three: Class managing a dynamic int.
    class RuleOfThree {
    public:
        int* data;
        RuleOfThree(int value);
        RuleOfThree(const RuleOfThree& other);
        RuleOfThree& operator=(const RuleOfThree& other);
        ~RuleOfThree();
    };

    // Rule of Five: Class with move semantics.
    class RuleOfFive {
    public:
        int* data;
        RuleOfFive(int value);
        RuleOfFive(const RuleOfFive& other);
        RuleOfFive& operator=(const RuleOfFive& other);
        RuleOfFive(RuleOfFive&& other) noexcept;
        RuleOfFive& operator=(RuleOfFive&& other) noexcept;
        ~RuleOfFive();
    };

    // Multiple Inheritance: Two base classes.
    class Base1 {
    public:
        void base1Func();
    };

    class Base2 {
    public:
        void base2Func();
    };

    // Derived class from Base1 and Base2.
    class DerivedMultiple : public Base1, public Base2 {
    public:
        void show();
    };

    // Diamond Inheritance with virtual inheritance.
    class BaseDiamond {
    public:
        void greet();
    };

    class Derived1Diamond : virtual public BaseDiamond {};

    class Derived2Diamond : virtual public BaseDiamond {};

    class DiamondChild : public Derived1Diamond, public Derived2Diamond {
    public:
        void speak();
    };

    // Overloaded functions.
    void overloadedFunc(int a);
    void overloadedFunc(double a);
    void overloadedFunc(const std::string& a);

    // Template for generic add.
    template <typename T>
    T add(T a, T b) {
        return a + b;
    }

    // Run demo.
    void run();
}

#endif // STRUCTURES_CLASSES_H
