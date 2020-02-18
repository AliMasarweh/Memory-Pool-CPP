//
// Created by ali-masa on 2/18/20.
//

#ifndef REFACTORED_TEST_MEMORY_POOL_H
#define REFACTORED_TEST_MEMORY_POOL_H

#include <stddef.h>

class MemoryPool
{
public:
    static MemoryPool init(void* pntr, size_t size, size_t elementSize) ;

    void *s_firstFree;
};

#endif //REFACTORED_TEST_MEMORY_POOL_H
