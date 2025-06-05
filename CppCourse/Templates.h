#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream>
#include <string>
#include <type_traits>
#include <initializer_list>
#include <typeinfo>

namespace Templates {

    // 1. Template Class: Generic container.
    template<typename T>
    class Container {
    public:
        T value;
        Container(T v) : value(v) {}
        void display() const {
            std::cout << "Container value: " << value << std::endl;
        }
    };

    // 2. Full Template Specialization for std::string.
    template<>
    class Container<std::string> {
    public:
        std::string value;
        Container(std::string v) : value(v) {}
        void display() const {
            std::cout << "Specialized Container for string: " << value << std::endl;
        }
    };

    // 3. Variadic Templates: Function to print all arguments.
    template<typename... Args>
    void printAll(Args... args) {
        (void)std::initializer_list<int>{ (std::cout << args << " ", 0)... };
        std::cout << std::endl;
    }

    // 5. Partial Template Specialization:
    // Generic Wrapper class.
    template<typename T>
    class Wrapper {
    public:
        T data;
        Wrapper(T d) : data(d) {}
        void display() const {
            std::cout << "Wrapper with data: " << data << std::endl;
        }
    };

    // Partial specialization for pointer types.
    template<typename T>
    class Wrapper<T*> {
    public:
        T* data;
        Wrapper(T* d) : data(d) {}
        void display() const {
            if (data)
                std::cout << "Wrapper for pointer: " << *data << std::endl;
            else
                std::cout << "Wrapper for pointer: nullptr" << std::endl;
        }
    };

    // 6. Type Traits: Check if a type is integral.
    template<typename T>
    void checkIntegral() {
        std::cout << "Is " << typeid(T).name() << " integral? "
            << (std::is_integral<T>::value ? "Yes" : "No") << std::endl;
    }

    // 7. SFINAE: Enable function only for floating-point types.
    template<typename T>
    typename std::enable_if<std::is_floating_point<T>::value, T>::type halfValue(T value) {
        return value / 2;
    }

    // Declaration of run() (non-template) to demo everything.
    void run();

} // namespace Templates

#endif // TEMPLATES_H
