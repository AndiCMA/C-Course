#ifndef EXCEPTION_HANDLING_H
#define EXCEPTION_HANDLING_H

#include <iostream>
#include <exception>
#include <stdexcept>
#include <system_error>
#include <regex>
#include <future>
#include <ios>
#include <typeinfo>
#include <string>

namespace ExceptionHandling {

    // Function that throws one of the standard exceptions based on the input choice.
    // Note: Not every exception has a message constructor.
    void simulateAllExceptions(int choice);

    // Function to run the exception simulation and catch all native exceptions.
    void run();
}

#endif // EXCEPTION_HANDLING_H
