#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
private:
    unsigned int mLength;
	T *mArray;

public:
	Array(void);
	Array(unsigned int n);
	Array(const Array &other);
	Array<T>& operator=(const Array<T> &other);
	~Array(void);
	unsigned int size(void) const;
	T& operator[] (unsigned int pos);
	const T& operator[] (unsigned int pos) const;
};

template <typename T>
Array<T>::Array(void)
    : mLength(0) 
    , mArray(new T[0])
{
}

template <typename T>
Array<T>::Array(unsigned int n)
    : mLength(n)
    , mArray(new T[n])
{
}

template <typename T>
Array<T>::Array(const Array &other)
    : mLength(other.mLength)
    , mArray(new T[other.mLength])
{
    for (unsigned int i = 0; i < mLength; i++)
    {
        mArray[i] = other.mArray[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
    if (this == &other)
    {
        return (*this);
    }

    delete[] mArray;
    mArray = NULL;
    mArray = new T[other.mLength];
    mLength = other.mLength;

    for (unsigned int i = 0; i < mLength; i++)
    {
        mArray[i] = other.mArray[i];
    }

    return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
    delete[] mArray;
    mArray = NULL;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return mLength;
}

template <typename T>
T& Array<T>::operator[](unsigned int pos)
{
	if (pos >= mLength)
	{
		throw std::out_of_range("out of Array Index!");
	}
	else
	{
		return mArray[pos];
	}
}

template <typename T>
const T& Array<T>::operator[](unsigned int pos) const
{
	if (pos >= mLength)
	{
		throw std::out_of_range("out of Array Index!");
	}
	else
	{
		return mArray[pos];
	}
}

#endif
