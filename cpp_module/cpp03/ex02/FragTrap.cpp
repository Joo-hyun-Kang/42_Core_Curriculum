#include "FragTrap.hpp"
    
FragTrap::FragTrap(void)
    : ClapTrap("FragTrap", 100, 100, 30)
{   
    std::cout << "FragTrap is made by default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name, 100, 100, 30)
{   
    std::cout << "FragTrap " << mName << " is made by constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
    : ClapTrap(fragTrap.mName, fragTrap.mHitPoint, fragTrap.mEnergyPoint, fragTrap.mAttackDamage)
{
    std::cout << "FragTrap " << mName << " is made by copy constructor" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &fragTrap)
{
    mName = fragTrap.mName;
    mHitPoint = fragTrap.mHitPoint;
    mEnergyPoint = fragTrap.mEnergyPoint;
    mAttackDamage = fragTrap.mAttackDamage;

    std::cout << "FragTrap " << mName << " is made by copy constructor" << std::endl;

    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << mName << " is deleted" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (mHitPoint == 0)
    {
        std::cout << "FragTrap " << mName << " is died" << std::endl;
        return ;
    }

    std::cout << "FragTrap " << mName << " high high five!!" << std::endl;
}