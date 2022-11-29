#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>

template <typename T>
class Array
{
private:
	T* a;
	unsigned int size;
public:
	Array()
		: a(new T[0])
		, size(0)
	{}

	Array(unsigned int size)
		: a(new T[size])
		, size(size)
	{}

	Array( const Array &oldArray )
		: a(new T[oldArray.size])
		, size(oldArray.size)
	{
		for (unsigned int i = 0; i < size; i++)
			a[i] = oldArray.a[i];
	}

	Array<T>& operator= ( const Array<T> &oldArray )
	{
		delete[] a;
		a = new T[oldArray.size];
		size = oldArray.size;
		for (unsigned int i = 0; i < size; i++)
			a[i] = oldArray.a[i];
		
		// Could be replaced by:
		// delete[] a;
		// a = Array(oldArray);
	}

	T& operator[] ( unsigned int pos )
	{
		if (pos >= size)
			throw std::exception();
		else
			return (a[pos]);
	}

	const T& operator[] ( unsigned int pos ) const
	{
		if (pos >= size)
			throw std::exception();
		else
			return (a[pos]);
	}

	~Array()
	{
		delete[] a;
	}
};


#endif


#include <iostream>
#include <exception>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include "Array.hpp"

#define MAX_VAL 10

// Tests taken from dda-silv github repo, thanks :)
int main(void) {

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // testing deep copy
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    try {
        numbers[-2] = 0;
    } catch(std::exception const& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        numbers[MAX_VAL] = 0;
    } catch(std::exception const& e) {
        std::cerr << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }

    delete[] mirror;

    return 0;
}
