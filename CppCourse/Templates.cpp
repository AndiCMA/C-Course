#include "Templates.h"

namespace Templates {

    void run() {
        std::cout << "=== Template Classes Demo ===" << std::endl;
        Container<int> intContainer(42);
        intContainer.display();
        Container<double> doubleContainer(3.14);
        doubleContainer.display();
        Container<std::string> stringContainer("Hello Templates");
        stringContainer.display();

        std::cout << "\n=== Variadic Templates Demo ===" << std::endl;
        printAll(1, "two", 3.0, "four");

        std::cout << "\n=== Partial Template Specialization Demo ===" << std::endl;
        int x = 100;
        Wrapper<int> w1(x);
        w1.display();
        Wrapper<int*> w2(&x);
        w2.display();

        std::cout << "\n=== Type Traits Demo ===" << std::endl;
        checkIntegral<int>();
        checkIntegral<double>();

        std::cout << "\n=== SFINAE Demo ===" << std::endl;
        double val = 10.0;
        std::cout << "Half of " << val << " is " << halfValue(val) << std::endl;
        // Uncommenting the next line will result in a compile-time error:
        // std::cout << halfValue(10) << std::endl; // int is not a floating-point type.
    }

} // namespace Templates
