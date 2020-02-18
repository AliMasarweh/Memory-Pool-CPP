//
// Created by ali-masa on 2/17/20.
//

#include <cstring>
#include <stddef.h>
#include <iostream>

#include "fixed_pool_person.h"

unsigned char Person::s_pool[POOL_SIZE];

bool Person::isInit = false;

void* Person::s_firstFree = Person::init_pool();

#define POOL_PTR(i) reinterpret_cast<void**>(s_pool+(i)*sizeof(Person))


Person::Person(char *fullname, unsigned int id, unsigned int age)
        :id(id), age(age)
{
    strcpy(this->fullname, fullname);
}


void *Person::operator new(size_t size) {
    if(Person::s_firstFree == NULL)
        return NULL;

    void* pointer = (int*)Person::s_firstFree;
    Person::s_firstFree =
            *static_cast<void**>(Person::s_firstFree);

    /*Person::s_firstFree = reinterpret_cast<void *>(size + sizeof(void *));*/

    return pointer;
}


void Person::operator delete(void *ptr) {
    void** ptrNextHead = reinterpret_cast<void**>(
            ((int*)ptr)
    );
    *ptrNextHead = Person::s_firstFree;
    Person::s_firstFree = ptrNextHead;
}


void *Person::operator new[](size_t count) {
    return NULL;
}


void Person::operator delete[](void *ptr) {}

void *Person::init_pool() {
    std::cout << "init_pool" << std::endl;
    size_t elements =
            Person::s_poolSize/sizeof(Person);

    isInit = true;

    s_firstFree = s_pool;

    size_t i;
    for(i = 0; i < elements; ++i)
    {
        *POOL_PTR(i) = POOL_PTR(i + 1);
    }

    *POOL_PTR(i) = NULL;

    return s_firstFree;
}