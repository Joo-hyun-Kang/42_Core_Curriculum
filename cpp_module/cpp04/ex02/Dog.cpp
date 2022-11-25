#include "Dog.hpp"

Dog::Dog()
    : Animal("Dog")
    , mBrain(new Brain())
{
    std::cout << "Dog is created by Default Constructor" << std::endl;
}

Dog::Dog(const Dog &other)
    : Animal(other.mType)
    , mBrain(new Brain(*other.mBrain))
{
    std::cout << "Dog is created by copy Constructor" << std::endl;
}

Dog &Dog::operator=(const Dog& other)
{
    *mBrain = *other.mBrain;
    mType = other.mType;
    std::cout << "Dog is changed by =" << std::endl;

    return (*this);
}

Dog::~Dog()
{
    delete mBrain;
    std::cout << "Dog is deleted" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Bark Bark!!" << std::endl;
}

Brain &Dog::getBrain() const
{
    return *mBrain;
}