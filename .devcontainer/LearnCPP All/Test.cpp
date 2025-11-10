#include <iostream>
#include <typeinfo>
using namespace std;

size_t foo(size_t n)
{
    int* p = new int[n];

    if (n < 10)
        return 0;

    for (size_t i = 0; i < n; ++i)
        p[i] = rand() & 1;

    size_t s = 0;
    for (size_t i = 0; i < n; ++i)
        s += p[i];

    delete[] p;

    return s;
}
