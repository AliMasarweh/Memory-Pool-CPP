//
// Created by ali-masa on 2/18/20.
//

#include <stdexcept>
#include "person.h"

const size_t poolSize = 10*sizeof(Person);
char pool[poolSize];
MemoryPool Person::s_memoryPool(pool, poolSize, sizeof(Person));

Person::Person(char *fullname, unsigned int id, unsigned int age)
        :id(id), age(age)
{
    strcpy(this->fullname, fullname);
}


void *Person::operator new(size_t size) {
    void* pointer = s_memoryPool.allocate();

    return pointer;
}


void Person::operator delete(void *ptr) {
    s_memoryPool.deallocate(ptr);
}


void *Person::operator new[](size_t count) {
    throw std::runtime_error("Unsupported Operator");
    return NULL;
}


void Person::operator delete[](void *ptr) {
    throw std::runtime_error("Unsupported Operator");
}
