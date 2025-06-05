#include "ExceptionHandling.h"
using namespace std;

namespace ExceptionHandling {

    // Function that throws one of the standard exceptions based on the input choice.
    // Note: Not every exception has a message constructor.
    void simulateAllExceptions(int choice) {
        switch (choice) {
        case 1:
            throw std::exception(); // Base exception.
        case 2:
            throw std::bad_alloc(); // Memory allocation failure.
        case 3:
            throw std::bad_cast(); // Invalid cast.
        case 4:
            throw std::bad_exception(); // For unexpected exceptions in exception specifications.
        case 5:
            throw std::bad_typeid(); // When using typeid on a null pointer to polymorphic type.
        case 6:
            throw std::logic_error("logic_error thrown");
        case 7:
            throw std::domain_error("domain_error thrown");
        case 8:
            throw std::invalid_argument("invalid_argument thrown");
        case 9:
            throw std::length_error("length_error thrown");
        case 10:
            throw std::out_of_range("out_of_range thrown");
        case 11:
            throw std::runtime_error("runtime_error thrown");
        case 12:
            throw std::range_error("range_error thrown");
        case 13:
            throw std::overflow_error("overflow_error thrown");
        case 14:
            throw std::underflow_error("underflow_error thrown");
        case 15:
            throw std::system_error(std::error_code(1, std::generic_category()), "system_error thrown");
        case 16:
            throw std::future_error(std::future_errc::broken_promise);
        case 17:
            throw std::ios_base::failure("ios_base::failure thrown");
        default:
            throw "Unknown exception thrown"; // C-style string exception.
        }
    }

    // Function to run the exception simulation and catch all native exceptions.
    void run() {
        for (int i = 1; i <= 17; ++i) {
            try {
                cout << "Throwing exception " << i << endl;
                simulateAllExceptions(i);
            }
            catch (const std::bad_alloc& e) {
                cout << "Caught bad_alloc: " << e.what() << endl;
            }
            catch (const std::bad_cast& e) {
                cout << "Caught bad_cast: " << e.what() << endl;
            }
            catch (const std::bad_exception& e) {
                cout << "Caught bad_exception: " << e.what() << endl;
            }
            catch (const std::bad_typeid& e) {
                cout << "Caught bad_typeid: " << e.what() << endl;
            }
            catch (const std::domain_error& e) {
                cout << "Caught domain_error: " << e.what() << endl;
            }
            catch (const std::invalid_argument& e) {
                cout << "Caught invalid_argument: " << e.what() << endl;
            }
            catch (const std::length_error& e) {
                cout << "Caught length_error: " << e.what() << endl;
            }
            catch (const std::out_of_range& e) {
                cout << "Caught out_of_range: " << e.what() << endl;
            }
            catch (const std::range_error& e) {
                cout << "Caught range_error: " << e.what() << endl;
            }
            catch (const std::overflow_error& e) {
                cout << "Caught overflow_error: " << e.what() << endl;
            }
            catch (const std::underflow_error& e) {
                cout << "Caught underflow_error: " << e.what() << endl;
            }
            catch (const std::logic_error& e) {
                cout << "Caught logic_error: " << e.what() << endl;
            }
            catch (const std::runtime_error& e) {
                cout << "Caught runtime_error: " << e.what() << endl;
            }
            catch (const std::system_error& e) {
                cout << "Caught system_error: " << e.what() << endl;
            }
            catch (const std::future_error& e) {
                cout << "Caught future_error: " << e.what() << endl;
            }
            catch (const std::regex_error& e) {
                cout << "Caught regex_error: " << e.what() << endl;
            }
            catch (const std::ios_base::failure& e) {
                cout << "Caught ios_base::failure: " << e.what() << endl;
            }
            catch (const std::exception& e) {
                cout << "Caught std::exception: " << e.what() << endl;
            }
            catch (...) {
                cout << "Caught an unknown exception." << endl;
            }
            cout << "---------------------------------" << endl;
        }
    }
}
