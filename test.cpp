//
// Created by ali-masa on 2/17/20.
//

#include <gtest/gtest.h>
#include "person.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(BasicPersonTest, InitlizePersonPool) {
    const size_t y = 18;
    Person<y> x("XYZ", 15, 12);
    operator new(sizeof(Person<y>));
    size_t size[sizeof(void*)+ sizeof(void*)];
}
