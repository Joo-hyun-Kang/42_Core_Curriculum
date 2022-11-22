#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string name)
    :mName(name)
{
}

Zombie::~Zombie()
{
    std::cout << mName << " is dead" << std::endl;
}

void Zombie::setName(std::string name)
{
    mName = name;
}

void Zombie::announce(void)
{
    std::cout << mName << " BraiiiiiiinnnzzzZ..." << std::endl;
}