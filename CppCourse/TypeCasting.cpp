#include "TypeCasting.h"
using namespace std;

namespace TypeCasting {

    void originalCastExample() {
        double d = 3.14159;
        int i = (int)d;
        cout << "Original cast: double " << d << " -> int " << i << endl;
    }

    void staticCastExample() {
        double d = 3.14159;
        int i = static_cast<int>(d);
        cout << "static_cast: double " << d << " -> int " << i << endl;
    }

    void constCastExample() {
        const int x = 10;
        const int* ptr = &x;
        int* modifiablePtr = const_cast<int*>(ptr);
        cout << "const_cast: original const int x = " << x << endl;
    }

    // Implement Derived::show (do not redefine class Derived).
    void Derived::show() {
        cout << "Derived object accessed via dynamic_cast." << endl;
    }

    void dynamicCastExample() {
        Base* basePtr = new Derived();
        Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
        if (derivedPtr) {
            cout << "dynamic_cast successful: ";
            derivedPtr->show();
        }
        else {
            cout << "dynamic_cast failed." << endl;
        }
        delete basePtr;
    }

    void reinterpretCastExample() {
        int a = 65;
        char* charPtr = reinterpret_cast<char*>(&a);
        cout << "reinterpret_cast: int " << a << " interpreted as char: " << *charPtr << endl;
    }

    void run() {
        cout << "=== Type Casting Examples ===" << endl;
        originalCastExample();
        staticCastExample();
        constCastExample();
        dynamicCastExample();
        reinterpretCastExample();
    }
}
