//
// Created by ali-masa on 2/17/20.
//

#ifndef TEST_PERSON_H
#define TEST_PERSON_H

#include <stddef.h>
template <size_t POOL_SIZE>
class Person
{
public:
    Person(char fullname[32], unsigned int id, unsigned int age);
    void* operator new ( size_t size );
    void operator delete ( void* ptr );

private:
    void* operator new[]( size_t count );
    void operator delete[]( void* ptr );

    static void* init_pool();

    const static size_t pool_size =
            POOL_SIZE - POOL_SIZE%(sizeof(Person)+sizeof(void*));
    static void* s_pool;
    static void* s_firstFree;

    char fullname[32];
    unsigned int id;
    unsigned int age;
};

#endif //TEST_PERSON_H
