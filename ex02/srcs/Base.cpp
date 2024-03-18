#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdint.h>
#include <stdlib.h> // srand, rand
#include <time.h>   // time

using std::cout;
using std::endl;

#define print(x) cout << #x << endl

#define YoRHa                                                                            \
    do                                                                                   \
    {                                                                                    \
        std::cout << "For the glory of mankind." << std::endl;                           \
        return NULL;                                                                     \
    } while (0);

enum Derived
{
    _A,
    _B,
    _C
};

Base::~Base(){};

Base *generate(void)
{
    srand(time(NULL));

    uint8_t dice = rand() % 3;

    if (dice == _A)
        return new A;
    else if (dice == _B)
        return new B;
    else if (dice == _C)
        return new C;
    else
        YoRHa
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        print(A);
    else if (dynamic_cast<B *>(p))
        print(B);
    else if (dynamic_cast<C *>(p))
        print(C);
}

void identify(Base &p)
{
    try
    {
        A &test = dynamic_cast<A &>(p);
        print(A);
        (void)test;
    }
    catch (...)
    {}
    try
    {
        B &test = dynamic_cast<B &>(p);
        print(B);
        (void)test;
    }
    catch (...)
    {}
    try
    {
        C &test = dynamic_cast<C &>(p);
        print(C);
        (void)test;
    }
    catch (...)
    {}
}
