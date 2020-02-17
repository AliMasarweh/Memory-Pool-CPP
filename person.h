//
// Created by ali-masa on 2/17/20.
//

#ifndef TEST_PERSON_H
#define TEST_PERSON_H

#include <cstring>
#include <stddef.h>

#define tenPersons 480

template <size_t POOL_SIZE = tenPersons>
class Person
{
public:
    Person(char *fullname, unsigned int id, unsigned int age);
    void* operator new ( size_t size );
    void operator delete ( void* ptr );

    static bool isInit;

    static void* init_pool();

private:
    void* operator new[]( size_t count );
    void operator delete[]( void* ptr );

/*    static void* init_pool();*/

    const static size_t s_poolSize = POOL_SIZE;
    static unsigned char s_pool[];
    static void* s_firstFree;

    char fullname[32];
    unsigned int id;
    unsigned int age;
};

template <size_t POOL_SIZE>
unsigned char Person<POOL_SIZE>::s_pool[POOL_SIZE];

template <size_t POOL_SIZE>
bool Person<POOL_SIZE>::isInit = false;

template <size_t POOL_SIZE>
void* Person<POOL_SIZE>::s_firstFree = Person<POOL_SIZE>::init_pool();

template <size_t POOL_SIZE>
Person<POOL_SIZE>::Person(char *fullname, unsigned int id, unsigned int age)
        :id(id), age(age)
{
    strcpy(this->fullname, fullname);
}

template <size_t POOL_SIZE>
void *Person<POOL_SIZE>::operator new(size_t size) {
    if(Person<POOL_SIZE>::s_firstFree == NULL)
        return NULL;

    void* pointer = (int*)Person<POOL_SIZE>::s_firstFree + sizeof(void*);
    Person<POOL_SIZE>::s_firstFree =
            *static_cast<void**>(Person<POOL_SIZE>::s_firstFree);

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
    std::cout << "init_pool" << std::endl;
    size_t elements =
            Person::s_poolSize/(sizeof(Person)+sizeof(void*));

    isInit = true;

    s_firstFree = s_pool;

    void** current_pntr = static_cast<void**>(s_firstFree);

    for(size_t i = 0; i < elements; ++i)
    {
        *current_pntr = current_pntr + sizeof(void*) + sizeof(Person);
        current_pntr = static_cast<void**>(*current_pntr);
    }

    *current_pntr = NULL;

    return s_firstFree;
}

#endif //TEST_PERSON_H
