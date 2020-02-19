//
// Created by ali-masa on 2/18/20.
//

#ifndef REFACTORED_TEST_MEMORY_POOL_H
#define REFACTORED_TEST_MEMORY_POOL_H

#include <stddef.h>

class MemoryPool
{
public:
    MemoryPool(void* pntr, size_t size, size_t elementSize) ;

    void *allocate();
    void deallocate(void *ptr);

private:
    void * m_firstFree;
    unsigned char m_pool[];

};

#endif //REFACTORED_TEST_MEMORY_POOL_H
