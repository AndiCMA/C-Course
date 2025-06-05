#include "CodeStructure.h"

namespace CodeStructure {

    // Definition of Utility class; hidden from external files.
    class Utility {
    public:
        void show() {
            std::cout << "Utility is showing!" << std::endl;
        }
    };

    void printMessage(const std::string& msg) {
        std::cout << "Message: " << msg << std::endl;
    }

    Helper::Helper() {
        // Initialization if needed.
    }

    void Helper::doWork() {
        std::cout << "Helper is doing work!" << std::endl;
    }

    void useUtility(Utility* util) {
        if (util)
            util->show();
        else
            std::cout << "No Utility provided." << std::endl;
    }

    Utility* createUtility() {
        return new Utility();
    }

    void run() {
        printMessage("Welcome to the CodeStructure demo!");
        Helper helper;
        helper.doWork();
        Utility* util = createUtility();
        useUtility(util);
        delete util;
    }

} // namespace CodeStructure
