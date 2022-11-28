#ifndef DATA_HPP
# define DATA_HPP


#include <iostream>

struct Data
{
    std::string value;
};

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

#endif