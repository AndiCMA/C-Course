#include "PointersReferences.h"
using namespace std;

namespace PointersReferences {

    // Demonstrates references: a reference is an alias for another variable.
    void demonstrateReferences() {
        int a = 42;            // Regular integer variable.
        int& ref = a;          // 'ref' is a reference to 'a'.
        cout << "a = " << a << ", ref = " << ref << endl;
        ref = 100;             // Changing 'ref' changes 'a' too.
        cout << "After modifying ref, a = " << a << endl;
    }

    // Demonstrates raw pointers and memory management.
    void demonstrateRawPointers() {
        // Allocate an int on the heap using new.
        int* p = new int(10);  // 'p' points to an integer with value 10.
        cout << "Raw pointer value: " << *p << ", address: " << p << endl;

        // Demonstrate dynamic array allocation.
        int arrSize = 3;
        int* arr = new int[arrSize] {1, 2, 3}; // Allocating array of 3 ints.
        cout << "Dynamic array values: ";
        for (int i = 0; i < arrSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // IMPORTANT: Free the allocated memory to prevent memory leaks.
        delete p;            // Free single object.
        delete[] arr;        // Free array.
    }

    // Demonstrates smart pointers: unique_ptr, shared_ptr, and weak_ptr.
    void demonstrateSmartPointers() {
        // unique_ptr: exclusive ownership.
        unique_ptr<int> up(new int(50));
        cout << "Unique pointer value: " << *up << endl;

        // Ownership transfer using move.
        unique_ptr<int> up2 = move(up);
        if (!up)
            cout << "up is now empty after move." << endl;
        cout << "up2 value: " << *up2 << endl;

        // shared_ptr: shared ownership, reference-counted.
        shared_ptr<int> sp1 = make_shared<int>(100);
        cout << "Shared pointer value: " << *sp1 << ", count: " << sp1.use_count() << endl;
        {
            shared_ptr<int> sp2 = sp1; // sp1 and sp2 share ownership.
            cout << "After sp2 copy, count: " << sp1.use_count() << endl;
        }
        cout << "After sp2 goes out of scope, count: " << sp1.use_count() << endl;

        // weak_ptr: a non-owning pointer to observe an object managed by shared_ptr.
        weak_ptr<int> wp = sp1;
        cout << "Weak pointer use_count: " << wp.use_count() << endl;
        if (auto sp3 = wp.lock()) { // lock() returns a shared_ptr if the object exists.
            cout << "Locked weak pointer value: " << *sp3 << endl;
        }
        else {
            cout << "Object no longer exists." << endl;
        }
    }

    // Demonstrates lifetime of objects and potential memory leaks.
    void demonstrateLifetime() {
        // Automatic (stack) variable: lifetime is limited to its scope.
        {
            int x = 10; // x exists only within this block.
            cout << "Inside scope: x = " << x << endl;
        }
        // x is destroyed here.

        // Dynamic allocation: lifetime must be managed manually.
        int* y = new int(20);
        cout << "Dynamically allocated y = " << *y << endl;
        // If delete is not called here, it results in a memory leak.
        delete y;
    }

    // Entry function for demonstrating pointers and references.
    void run() {
        cout << "=== Demonstrate References ===" << endl;
        demonstrateReferences();
        cout << "\n=== Demonstrate Raw Pointers and Memory Management ===" << endl;
        demonstrateRawPointers();
        cout << "\n=== Demonstrate Smart Pointers (unique, shared, weak) ===" << endl;
        demonstrateSmartPointers();
        cout << "\n=== Demonstrate Object Lifetime ===" << endl;
        demonstrateLifetime();
    }
}
