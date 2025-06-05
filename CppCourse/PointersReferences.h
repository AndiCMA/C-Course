#ifndef POINTERS_REFERENCES_H
#define POINTERS_REFERENCES_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

namespace PointersReferences {

    // Demonstrates references: a reference is an alias for another variable.
    void demonstrateReferences();

    // Demonstrates raw pointers and memory management.
    void demonstrateRawPointers();

    // Demonstrates smart pointers: unique_ptr, shared_ptr, and weak_ptr.
    void demonstrateSmartPointers();

    // Demonstrates lifetime of objects and potential memory leaks.
    void demonstrateLifetime();

    // Entry function for demonstrating pointers and references.
    void run();
}

#endif // POINTERS_REFERENCES_H
