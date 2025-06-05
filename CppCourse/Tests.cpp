#include <iostream>
#include "gtest/gtest.h"
#include "OOP.h"
#include "Idioms.h"

using namespace OOP;
using namespace Idioms;

namespace Tests {

    // --------------------------
    // Person Tests
    // --------------------------
    TEST(PersonTests, OperatorPlusAndOutput) {
        // Create two Person objects.
        OOP::Person p1("Alice", 30);
        OOP::Person p2("Bob", 40);
        // Test operator+ (which concatenates names and averages ages).
        OOP::Person p3 = p1 + p2;
        std::stringstream ss;
        ss << p3;  // Uses the overloaded operator<<.
        std::string output = ss.str();
        // Expect the name to contain "Alice-Bob" and the age to be 35.
        EXPECT_NE(output.find("Alice-Bob"), std::string::npos);
        EXPECT_NE(output.find("35"), std::string::npos);
    }

    TEST(PersonTests, OperatorIndex) {
        // Test operator[] for accessing name characters.
        OOP::Person p("Charlie", 25);
        EXPECT_EQ(p[0], 'C');
    }

    // --------------------------
    // Idioms Tests: Copy and Swap
    // --------------------------
    TEST(IdiomsTests, CopySwap) {
        Idioms::CopySwap cs1(10);
        Idioms::CopySwap cs2(20);
        cs1 = cs2;
        EXPECT_EQ(cs1.get(), 20);
    }
	TEST(BasicTestsInNamespace, BasicTest)
	{
		EXPECT_EQ(10, 10);
	}
}