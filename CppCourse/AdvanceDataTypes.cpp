#include "AdvanceDataTypes.h"

namespace AdvanceDataTypes {

    void Derived1::display() {
        std::cout << "I am Derived1" << std::endl;
    }

    void Derived2::display() {
        std::cout << "I am Derived2" << std::endl;
    }

    void runRTTI() {
        Base* b1 = new Derived1();
        Base* b2 = new Derived2();
        Base* b3 = new Base();

        std::cout << "Type of b1: " << typeid(*b1).name() << std::endl;
        std::cout << "Type of b2: " << typeid(*b2).name() << std::endl;
        std::cout << "Type of b3: " << typeid(*b3).name() << std::endl;

        if (Derived1* d1 = dynamic_cast<Derived1*>(b1)) {
            std::cout << "b1 is a Derived1 instance." << std::endl;
            d1->display();
        }
        else {
            std::cout << "b1 is NOT a Derived1 instance." << std::endl;
        }

        if (Derived2* d2 = dynamic_cast<Derived2*>(b2)) {
            std::cout << "b2 is a Derived2 instance." << std::endl;
            d2->display();
        }
        else {
            std::cout << "b2 is NOT a Derived2 instance." << std::endl;
        }

        if (dynamic_cast<Derived1*>(b3)) {
            std::cout << "b3 is a Derived1 instance." << std::endl;
        }
        else if (dynamic_cast<Derived2*>(b3)) {
            std::cout << "b3 is a Derived2 instance." << std::endl;
        }
        else {
            std::cout << "b3 is of type Base (neither Derived1 nor Derived2)." << std::endl;
        }

        delete b1;
        delete b2;
        delete b3;
    }

    void runDynamicTypes() {
        auto a = 42;
        auto b = 3.14;
        auto c = "Hello, World!";
        auto d = std::string("Hello, C++");

        std::cout << "auto deduced type for a: " << typeid(a).name() << ", value: " << a << std::endl;
        std::cout << "auto deduced type for b: " << typeid(b).name() << ", value: " << b << std::endl;
        std::cout << "auto deduced type for c: " << typeid(c).name() << ", value: " << c << std::endl;
        std::cout << "auto deduced type for d: " << typeid(d).name() << ", value: " << d << std::endl;

        std::any var;
        var = 100;
        std::cout << "std::any holding int: " << std::any_cast<int>(var) << std::endl;
        var = 3.14159;
        std::cout << "std::any holding double: " << std::any_cast<double>(var) << std::endl;
        var = std::string("std::any with string");
        std::cout << "std::any holding string: " << std::any_cast<std::string>(var) << std::endl;

        auto add = [](auto x, auto y) { return x + y; };
        std::cout << "Lambda add(10, 5): " << add(10, 5) << std::endl;
        std::cout << "Lambda add(3.5, 2.5): " << add(3.5, 2.5) << std::endl;
    }

    void run() {
        std::cout << "=== Run-Time Type Identification (RTTI) ===" << std::endl;
        runRTTI();
        std::cout << "\n=== Dynamic Types (auto, std::any, and lambda with auto) ===" << std::endl;
        runDynamicTypes();
    }

} // namespace AdvanceDataTypes
