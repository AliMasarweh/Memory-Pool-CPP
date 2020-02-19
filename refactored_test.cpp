//
// Created by ali-masa on 2/18/20.
//

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
    Person x("XYZ", 15, 12);
}

TEST(BasicPersonTest, NewAndDeletePerson)
{
    Person *person1 = NULL, *person2 = NULL, *person3 = NULL;
    person1 = new Person("1", 15, 12);
    person2 = new Person("12", 15, 12);
    person3 = new Person("123", 15, 12);

    size_t personSize = sizeof(Person), pntrSize = sizeof(void*);

    ASSERT_EQ(reinterpret_cast<size_t>(person1)+personSize,
              reinterpret_cast<size_t>(person2));
    ASSERT_EQ(reinterpret_cast<size_t>(person2)+personSize,
              reinterpret_cast<size_t>(person3));
    delete person3;
    delete person2;
    delete person1;

    person1 = new Person("1", 15, 12);
    delete person1;
}

TEST(AdvancedPersonTest, NewAndDeleteOrderPerson)
{
    Person *person1 = NULL, *person2 = NULL,
            *person3 = NULL, *person4 = NULL, *person5 = NULL;

    person1 = new Person("1", 15, 12);
    person2 = new Person("12", 15, 12);
    person3 = new Person("123", 15, 12);
    person4 = new Person("1234", 15, 12);
    person5 = new Person("12345", 15, 12);

    size_t address2 = reinterpret_cast<size_t>(person2);
    size_t address4 = reinterpret_cast<size_t>(person4);
    size_t address1 = reinterpret_cast<size_t>(person1);
    size_t address5 = reinterpret_cast<size_t>(person5);
    size_t address3 = reinterpret_cast<size_t>(person3);

    delete person2;
    delete person4;
    delete person1;
    delete person5;
    delete person3;

    person1 = new Person("1", 15, 12);
    person2 = new Person("12", 15, 12);
    person3 = new Person("123", 15, 12);
    person4 = new Person("1234", 15, 12);
    person5 = new Person("12345", 15, 12);

    ASSERT_EQ(address3, reinterpret_cast<size_t>(person1));
    ASSERT_EQ(address5, reinterpret_cast<size_t>(person2));
    ASSERT_EQ(address1, reinterpret_cast<size_t>(person3));
    ASSERT_EQ(address4, reinterpret_cast<size_t>(person4));
    ASSERT_EQ(address2, reinterpret_cast<size_t>(person5));
}
