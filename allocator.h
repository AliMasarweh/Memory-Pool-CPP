//
// Created by ali-masa on 2/17/20.
//

#ifndef TEST_ALLOCATOR_H
#define TEST_ALLOCATOR_H

#include <stddef.h>

template <class T, size_t POOL_SIZE>
class Allocator: public T
{
public:
    void* operator new ( size_t size );
    void operator delete ( void* ptr );

private:
    void* operator new[]( size_t count );
    void operator delete[]( void* ptr );

    static void* init_pool();

    const static size_t size =
            POOL_SIZE - POOL_SIZE%(sizeof(T)+sizeof(void*));

    static void* s_firstFree;
    static void* s_pool;
};

template <class T, size_t POOL_SIZE>
void* Allocator<T, POOL_SIZE>::s_pool = init_pool();

#endif //TEST_ALLOCATOR_H
