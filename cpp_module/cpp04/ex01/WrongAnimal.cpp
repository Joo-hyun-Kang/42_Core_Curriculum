#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
    : mType("WrongAnimal")
{
    std::cout << "WrongAniaml is created by Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
    : mType(type)
{
    std::cout << "WrongAniaml is created by Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
    : mType(other.mType)
{
    std::cout << "WrongAniaml is created by Copy Constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    mType = other.mType;
    std::cout << "WrongAniaml is changed by =" << std::endl;

    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAniaml is deleted" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAniaml sound!!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return mType;
}