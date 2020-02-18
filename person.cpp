//
// Created by ali-masa on 2/18/20.
//

#include <stdexcept>
#include "person.h"

const size_t poolSize = 10*sizeof(Person);
char pool[poolSize];
MemoryPool Person::s_memoryPool = MemoryPool::init(pool, poolSize, sizeof(Person));

Person::Person(char *fullname, unsigned int id, unsigned int age)
        :id(id), age(age)
{
    strcpy(this->fullname, fullname);
}


void *Person::operator new(size_t size) {
    if(s_memoryPool.s_firstFree == NULL)
        return NULL;

    void* pointer = (int*)s_memoryPool.s_firstFree + sizeof(void*);
    s_memoryPool.s_firstFree =
            *static_cast<void**>(s_memoryPool.s_firstFree);

    return pointer;
}


void Person::operator delete(void *ptr) {
    void** ptrToNext = reinterpret_cast<void**>(
            ((int*)ptr - sizeof(void*))
    );
    *ptrToNext = s_memoryPool.s_firstFree;
    s_memoryPool.s_firstFree = *ptrToNext;
}


void *Person::operator new[](size_t count) {
    throw std::runtime_error("Unsupported Operator");
    return NULL;
}


void Person::operator delete[](void *ptr) {
    throw std::runtime_error("Unsupported Operator");
}
