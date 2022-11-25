#include "Brain.hpp"

Brain::Brain()
{
    const std::string ideas[] = {"sad", "happy", "angry", "up", "down"};

    for (int i = 0; i < 100; i++)
    {
        mIdeas[i] = ideas[i % 5];
    }

    std::cout << "Brain is created by Default Constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
    for (int i = 0; i < 100; i++)
    {
        mIdeas[i] = other.getIdea(i);
    }

    std::cout << "Brain is created by copy Constructor" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    for (int i = 0; i < 100; i++)
    {
        mIdeas[i] = other.getIdea(i);
    }

    std::cout << "Brain is changed by =" << std::endl;

    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain is deleted" << std::endl;
}

const std::string &Brain::getIdea(int index) const
{
    return mIdeas[index];
}