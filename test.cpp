//
// Created by ali-masa on 2/17/20.
//

#include <gtest/gtest.h>
#include <iostream>
#include "person.h"

using namespace std;

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(BasicPersonTest, InitlizePersonPool)
{
    const size_t y = 2*(sizeof(Person<>) + sizeof(void*));
/*    Person<y>::init_pool();*/
    Person<y> x("XYZ", 15, 12);
    cout << "isInit " << Person<y>::isInit << endl;
}

TEST(BasicPersonTest, NewAndDeletePerson)
{
    const size_t pOf3 = 3*(sizeof(Person<>) + sizeof(void*));
    Person<pOf3> *x = NULL;
    cout << "isInit " << Person<pOf3>::isInit << endl;
/*    new Person<pOf3>("XYZ", 15, 12);*/

}