#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

namespace Idioms {

    // 1. RAII (Resource Acquisition Is Initialization)
    class Resource {
    public:
        Resource() { cout << "[RAII] Resource acquired." << endl; }
        ~Resource() { cout << "[RAII] Resource released." << endl; }
        void doSomething() { cout << "[RAII] Using resource." << endl; }
    };

    void demonstrateRAII() {
        cout << "=== RAII Demo ===" << endl;
        Resource res;
        res.doSomething();
    }

    // 2. Pimpl (Pointer to Implementation) Idiom
    class Widget {
    public:
        Widget(const string& name);
        ~Widget();
        void display() const;
    private:
        class Impl;              // Forward declaration
        unique_ptr<Impl> pImpl;  // Pointer to implementation
    };

    // Define the implementation class
    class Widget::Impl {
    public:
        Impl(const string& name) : name(name) {}
        void display() const { cout << "[Pimpl] Widget: " << name << endl; }
    private:
        string name;
    };

    Widget::Widget(const string& name) : pImpl(make_unique<Impl>(name)) {}
    Widget::~Widget() = default;
    void Widget::display() const { pImpl->display(); }

    void demonstratePimpl() {
        cout << "=== Pimpl Demo ===" << endl;
        Widget w("MyWidget");
        w.display();
    }

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
        void implementation() {
            cout << "[CRTP] DerivedCRTP implementation." << endl;
        }
    };

    void demonstrateCRTP() {
        cout << "=== CRTP Demo ===" << endl;
        DerivedCRTP d;
        d.interface();
    }

    // 4. Non-Copyable Idiom
    class NonCopyable {
    public:
        NonCopyable() = default;
        NonCopyable(const NonCopyable&) = delete;
        NonCopyable& operator=(const NonCopyable&) = delete;
    };

    class UniqueResource : public NonCopyable {
    public:
        UniqueResource() { cout << "[NonCopyable] UniqueResource acquired." << endl; }
        ~UniqueResource() { cout << "[NonCopyable] UniqueResource released." << endl; }
    };

    void demonstrateNonCopyable() {
        cout << "=== Non-Copyable Demo ===" << endl;
        UniqueResource ur;
        // Uncommenting the lines below will cause compile-time errors:
        // UniqueResource ur2 = ur;
        // UniqueResource ur3;
        // ur3 = ur;
    }

    // 5. Erase-Remove Idiom
    void demonstrateEraseRemove() {
        cout << "=== Erase-Remove Idiom Demo ===" << endl;
        vector<int> vec = { 1, 2, 3, 2, 4, 2, 5 };
        cout << "[Erase-Remove] Before: ";
        for (int v : vec) cout << v << " ";
        cout << endl;
        vec.erase(remove(vec.begin(), vec.end(), 2), vec.end());
        cout << "[Erase-Remove] After: ";
        for (int v : vec) cout << v << " ";
        cout << endl;
    }

    // 6. Copy and Swap Idiom
    class CopySwap {
    public:
        CopySwap(int value = 0) : data(new int(value)) {}
        // Copy constructor
        CopySwap(const CopySwap& other) : data(new int(*other.data)) {}
        // Copy assignment using copy and swap
        CopySwap& operator=(CopySwap other) {
            swap(data, other.data);
            return *this;
        }
        ~CopySwap() { delete data; }
        int get() const { return *data; }
        void set(int value) { *data = value; }
    private:
        int* data;
    };

    void demonstrateCopySwap() {
        cout << "=== Copy and Swap Idiom Demo ===" << endl;
        CopySwap cs1(10);
        CopySwap cs2(20);
        cout << "Before assignment: cs1 = " << cs1.get() << ", cs2 = " << cs2.get() << endl;
        cs1 = cs2;
        cout << "After assignment: cs1 = " << cs1.get() << ", cs2 = " << cs2.get() << endl;
    }

    // 7. Copy-on-Write Idiom
    class CowString {
    public:
        CowString(const string& str = "") : data(make_shared<string>(str)) {}
        CowString(const CowString&) = default;
        CowString& operator=(const CowString&) = default;
        // Non-const access triggers copy on write
        void append(const string& str) {
            if (!data.use_count() < 2 ) {
                data = make_shared<string>(*data);
            }
            data->append(str);
        }
        const string& get() const { return *data; }
    private:
        shared_ptr<string> data;
    };

    void demonstrateCopyOnWrite() {
        cout << "=== Copy-on-Write Idiom Demo ===" << endl;
        CowString s1("Hello");
        CowString s2 = s1; // s1 and s2 share the same string
        cout << "[Copy-on-Write] Before modification: s1 = " << s1.get() << ", s2 = " << s2.get() << endl;
        s1.append(", World!");
        cout << "[Copy-on-Write] After modification: s1 = " << s1.get() << ", s2 = " << s2.get() << endl;
    }

    void run() {
        demonstrateRAII();
        cout << endl;
        demonstratePimpl();
        cout << endl;
        demonstrateCRTP();
        cout << endl;
        demonstrateNonCopyable();
        cout << endl;
        demonstrateEraseRemove();
        cout << endl;
        demonstrateCopySwap();
        cout << endl;
        demonstrateCopyOnWrite();
    }
}

