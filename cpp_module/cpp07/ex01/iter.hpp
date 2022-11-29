#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void print(T &t) 
{
    std::cout << t << " ";
}

template <typename T>
void multiply(T &t) 
{
    t = t * 2;
}

void multiply2(int &num) 
{
    num = num * 2;
}

template <typename T>
void iter(T *array, size_t length, void (*fp)(T &t))
{
    for (size_t i = 0; i < length; i++) 
    {
        fp(array[i]);
    }
}

#endif
