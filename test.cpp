//
// Created by ali-masa on 2/17/20.
//

#include <gtest/gtest.h>
#include <iostream>
#include "person.h"

using namespace std;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(BasicPersonTest, InitlizePersonPool) {
    const size_t y = 18*(sizeof(Person<>) + sizeof(void*));
    Person<y> x("XYZ", 15, 12);
}
