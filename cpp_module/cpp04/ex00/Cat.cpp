#include "Cat.hpp"

Cat::Cat()
    : Animal("Cat")
{
    std::cout << "Cat is created by Default Constructor" << std::endl;
}

Cat::Cat(const Cat &other)
    : Animal(other.mType)
{
    std::cout << "Cat is created by copy Constructor" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
    mType = other.mType;
    std::cout << "Cat is changed by =" << std::endl;

    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat is deleted" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow Meow.." << std::endl;
}