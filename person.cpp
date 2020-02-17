//
// Created by ali-masa on 2/17/20.
//

#include <cstring>
#include <cstdlib>
#include "person.h"

template <size_t POOL_SIZE>
Person<POOL_SIZE>::Person(char fullname[32], unsigned int id, unsigned int age)
:id(id), age(age)
{
    strcpy(this->fullname, fullname);
}

template <size_t POOL_SIZE>
void *Person<POOL_SIZE>::operator new(size_t size) {
    void* pointer = (int*)Person::s_firstFree + sizeof(void*);
    Person::s_firstFree = *static_cast<void**>(Person::s_firstFree);

    return pointer;
}

template <size_t POOL_SIZE>
void Person<POOL_SIZE>::operator delete(void *ptr) {
    void** ptrToNext = reinterpret_cast<void**>(
            ((int*)ptr - sizeof(void*))
            );
    *ptrToNext = Person::s_firstFree;
    Person::s_firstFree = *ptrToNext;
}

template <size_t POOL_SIZE>
void *Person<POOL_SIZE>::operator new[](size_t count) {
    return NULL;
}

template <size_t POOL_SIZE>
void Person<POOL_SIZE>::operator delete[](void *ptr) {}

template <size_t POOL_SIZE>
void *Person<POOL_SIZE>::init_pool() {
    return NULL;
}

