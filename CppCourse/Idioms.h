#ifndef IDIOMS_H
#define IDIOMS_H

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

namespace Idioms {

    // 1. RAII (Resource Acquisition Is Initialization)
    class Resource {
    public:
        Resource();
        ~Resource();
        void doSomething();
    };

    void demonstrateRAII();

    // 2. Pimpl (Pointer to Implementation) Idiom
    class Widget {
    public:
        Widget(const std::string& name);
        ~Widget();
        void display() const;
    private:
        class Impl;              // Forward declaration of implementation class.
        std::unique_ptr<Impl> pImpl;  // Pointer to implementation.
    };

    void demonstratePimpl();

    // 3. CRTP (Curiously Recurring Template Pattern)
    template<typename Derived>
    class BaseCRTP {
    public:
        void interface() {
            static_cast<Derived*>(this)->implementation();
        }
    };

    class DerivedCRTP : public BaseCRTP<DerivedCRTP> {
    public:
        void implementation();
    };

    void demonstrateCRTP();

    // 4. Non-Copyable Idiom
    class NonCopyable {
    public:
        NonCopyable() = default;
        NonCopyable(const NonCopyable&) = delete;
        NonCopyable& operator=(const NonCopyable&) = delete;
    };

    class UniqueResource : public NonCopyable {
    public:
        UniqueResource();
        ~UniqueResource();
    };

    void demonstrateNonCopyable();

    // 5. Erase-Remove Idiom
    void demonstrateEraseRemove();

    // 6. Copy and Swap Idiom
    class CopySwap {
    public:
        CopySwap(int value = 0);
        CopySwap(const CopySwap& other);
        CopySwap& operator=(CopySwap other); // Copy-and-swap idiom.
        ~CopySwap();
        int get() const;
        void set(int value);
    private:
        int* data;
    };

    void demonstrateCopySwap();

    // 7. Copy-on-Write Idiom
    class CowString {
    public:
        CowString(const std::string& str = "");
        CowString(const CowString&) = default;
        CowString& operator=(const CowString&) = default;
        // Non-const access triggers copy on write.
        void append(const std::string& str);
        const std::string& get() const;
    private:
        std::shared_ptr<std::string> data;
    };

    void demonstrateCopyOnWrite();

    // Run all idiom demonstrations.
    void run();

} // namespace Idioms

#endif // IDIOMS_H
#pragma once
