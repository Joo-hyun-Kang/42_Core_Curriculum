#include "Cat.hpp"

Cat::Cat()
    : Animal("Cat")
    , mBrain(new Brain())
{
    std::cout << "Cat is created by Default Constructor" << std::endl;
}

Cat::Cat(const Cat &other)
    : Animal(other.mType)
    , mBrain(new Brain(*other.mBrain))
{
    std::cout << "Cat is created by copy Constructor" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
    *mBrain = *other.mBrain;
    mType = other.mType;
    std::cout << "Cat is changed by =" << std::endl;

    return (*this);
}

Cat::~Cat()
{
    delete mBrain;
    std::cout << "Cat is deleted" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow Meow.." << std::endl;
}

Brain &Cat::getBrain() const
{
    return *mBrain;
}