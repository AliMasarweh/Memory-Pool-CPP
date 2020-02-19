//
// Created by ali-masa on 2/19/20.
//

#include "memory_pool.h"

void * MemoryPool::allocate() {
    if(this->m_firstFree == NULL)
        return NULL;

    void* pointer = this->m_firstFree;
    this->m_firstFree =
            *static_cast<void**>(this->m_firstFree);

    return pointer;
}

void MemoryPool::deallocate(void *ptr) {
    void** ptrNextHead = reinterpret_cast<void**>(
            ((int*)ptr)
    );
    *ptrNextHead = this->m_firstFree;
    this->m_firstFree = ptrNextHead;
}

#define POOL_PTR(i) reinterpret_cast<void**>(m_pool+(i)*elementSize)

MemoryPool::MemoryPool(void *pntr, size_t poolSize, size_t elementSize) {
    size_t elements =
            poolSize/sizeof(elementSize);

    m_firstFree = (int*) poolSize;

    size_t i;
    for(i = 0; i < elements; ++i)
    {
        *POOL_PTR(i) = POOL_PTR(i + 1);
    }

    *POOL_PTR(i) = NULL;
}
