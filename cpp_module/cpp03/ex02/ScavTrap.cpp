#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    mName = "ScavTrap";
    mHitPoint = 100;
    mEnergyPoint = 50;
    mAttackDamage = 20;
    
    std::cout << "ScavTrap is made by default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    mName = name;
    mHitPoint = 100;
    mEnergyPoint = 50;
    mAttackDamage = 20;
    
    std::cout << "ScavTrap " << mName << " is made by constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
    mName = scavTrap.mName;
    mHitPoint = scavTrap.mHitPoint;
    mEnergyPoint = scavTrap.mEnergyPoint;
    mAttackDamage = scavTrap.mAttackDamage;

    std::cout << "ScavTrap " << mName << " is made by copy constructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavTrap)
{
    mName = scavTrap.mName;
    mHitPoint = scavTrap.mHitPoint;
    mEnergyPoint = scavTrap.mEnergyPoint;
    mAttackDamage = scavTrap.mAttackDamage;

    std::cout << "ScavTrap " << mName << " is created by copy constructor" << std::endl;

    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << mName << " is deleted" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (mEnergyPoint == 0 || mHitPoint == 0)
    {
        std::cout << "ScavTrap " << mName << " can not attack!" << std::endl;
        return ;
    }

    std::cout <<  "ScavTrap " << mName << " attacks " \
            << target << ", causing " << mAttackDamage \
            << " points of damage!" << std::endl;

    --mEnergyPoint;
}

void ScavTrap::guardGate()
{
    std::cout <<  "Now, ScavTrap " << mName << " is guard keeper mode!" << std::endl;
}