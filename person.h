//
// Created by ali-masa on 2/17/20.
//

#ifndef TEST_PERSON_H
#define TEST_PERSON_H

#include <cstring>
#include <stddef.h>
#include "memory_pool.h"

class Person
{
public:
    Person(char *fullname, unsigned int id, unsigned int age);
    void* operator new ( size_t size );
    void operator delete ( void* ptr );

private:
    void* operator new[]( size_t count );
    void operator delete[]( void* ptr );

    static MemoryPool s_memoryPool;

    char fullname[32];
    unsigned int id;
    unsigned int age;
};

#endif //TEST_PERSON_H
