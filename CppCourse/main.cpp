#include <iostream>
#include "gtest/gtest.h"


#include "AdvanceDataTypes.h"
#include "BasicOperations.h"
#include "CodeStructure.h"
#include "ExceptionHandling.h"
#include "Functions.h"
#include "Idioms.h"
#include "Multithreading.h"
#include "OOP.h"
#include "PointersReferences.h"
#include "STL.h"
#include "StructuresClasses.h"
#include "Templates.h"
#include "TypeCasting.h"


using namespace std;


int main(int argc, char* argv[]) {
    AdvanceDataTypes::run();

    BasicOperations::run();

    CodeStructure::run();

    ExceptionHandling::run();
    
    Functions::run();

    Idioms::run();

    Multithreading::run();

    OOP::run();

    PointersReferences::run();

    STL::run();

    StructuresClasses::run();

    Templates::run();

    TypeCasting::run();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}