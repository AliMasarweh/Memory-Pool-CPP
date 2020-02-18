//
// Created by ali-masa on 2/17/20.
//

#ifndef TEST_FIXED_POOL_PERSON_H
#define TEST_FIXED_POOL_PERSON_H

#define POOL_SIZE 5*(40+sizeof(void*))

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

#endif //TEST_FIXED_POOL_PERSON_H
