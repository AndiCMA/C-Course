//#pragma once is a preprocessor directive that ensures a header 
// file is included only once per compilation, preventing duplicate definitions.
// It's a simpler alternative to traditional include guards (#ifndef CODESTRUCTURE_H).

#ifndef CODESTRUCTURE_H
#define CODESTRUCTURE_H

#include <string>
#include <iostream>

namespace CodeStructure {

    // Forward declaration of Utility class.
    class Utility;

    // Function declaration to print a message.
    void printMessage(const std::string& msg);

    // Helper class declaration.
    class Helper {
    public:
        Helper();
        void doWork();
    };

    // Function that uses a forward-declared Utility pointer.
    void useUtility(Utility* util);

    // Function to create a Utility instance.
    Utility* createUtility();

    // Run function to demonstrate all features.
    void run();

} // namespace CodeStructure

#endif // CODESTRUCTURE_H
