#include "WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat is created by Default Constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
    : WrongAnimal(other.mType)
{
    std::cout << "WrongCat is created by copy Constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& other)
{
    mType = other.mType;
    std::cout << "WrongCat is changed by =" << std::endl;

    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat is deleted" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Mewwww Mewww Mewwww.." << std::endl;
}