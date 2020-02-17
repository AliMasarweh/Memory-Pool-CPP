//
// Created by ali-masa on 2/17/20.
//

#include <cstring>
#include <cstdlib>
#include "person.h"

Person::Person(char fullname[32], unsigned int id, unsigned int age)
:id(id), age(age)
{
    strcpy(this->fullname, fullname);
}

void *Person::operator new(size_t size) {
    void* pointer = (int*)Person::s_firstFree + sizeof(void*);
    Person::s_firstFree = *static_cast<void**>(Person::s_firstFree);

    return pointer;
}

void Person::operator delete(void *ptr) {
    void** ptrToNext = reinterpret_cast<void**>(
            ((int*)ptr - sizeof(void*))
            );
    *ptrToNext = Person::s_firstFree;
    Person::s_firstFree = *ptrToNext;
}

void *Person::operator new[](size_t count) {
    return NULL;
}

void Person::operator delete[](void *ptr) {}

void *Person::init_pool() {
    return NULL;
}

