#ifndef TYPECASTING_H
#define TYPECASTING_H

#include <iostream>

namespace TypeCasting {

    // Original (C-style) cast example:
    void originalCastExample();

    // static_cast example:
    void staticCastExample();

    // const_cast example:
    void constCastExample();

    // Classes for dynamic_cast example.
    class Base {
    public:
        virtual ~Base() {} // Must be polymorphic.
    };

    class Derived : public Base {
    public:
        void show();
    };

    // dynamic_cast example:
    void dynamicCastExample();

    // reinterpret_cast example:
    void reinterpretCastExample();

    // Run function demonstrating all type casts.
    void run();
}

#endif // TYPECASTING_H
