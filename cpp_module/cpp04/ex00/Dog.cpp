#include "Dog.hpp"

Dog::Dog()
    : Animal("Dog")
{
    std::cout << "Dog is created by Default Constructor" << std::endl;
}

Dog::Dog(const Dog &other)
    : Animal(other.mType)
{
    std::cout << "Dog is created by copy Constructor" << std::endl;
}

Dog &Dog::operator=(const Dog& other)
{
    mType = other.mType;
    std::cout << "Dog is changed by =" << std::endl;

    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog is deleted" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Bark Bark!!" << std::endl;
}