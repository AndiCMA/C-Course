#ifndef ADVANCEDATATYPES_H
#define ADVANCEDATATYPES_H

#include <iostream>
#include <typeinfo>
#include <any>
#include <string>

namespace AdvanceDataTypes {

    class Base {
    public:
        virtual ~Base() {}
    };

    class Derived1 : public Base {
    public:
        void display();
    };

    class Derived2 : public Base {
    public:
        void display();
    };

    void runRTTI();
    void runDynamicTypes();
    void run();

} // namespace AdvanceDataTypes

#endif // ADVANCEDATATYPES_H
