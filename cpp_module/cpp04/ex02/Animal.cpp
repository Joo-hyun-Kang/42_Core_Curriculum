#include "Animal.hpp"

Animal::Animal()
    : mType("Animal")
{
    std::cout << "Aniaml is created by Default Constructor" << std::endl;
}

Animal::Animal(std::string type)
    : mType(type)
{
    std::cout << "Aniaml is created by Constructor" << std::endl;
}

Animal::Animal(const Animal &other)
    : mType(other.mType)
{
    std::cout << "Aniaml is created by Copy Constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    mType = other.mType;
    std::cout << "Aniaml is changed by =" << std::endl;

    return (*this);
}

Animal::~Animal()
{
    std::cout << "Aniaml is deleted" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Aniaml sound!!" << std::endl;
}

std::string Animal::getType() const
{
    return mType;
}