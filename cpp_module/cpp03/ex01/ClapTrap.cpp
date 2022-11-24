#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
    : mName("ClapTrap")
    , mHitPoint(10)
    , mEnergyPoint(10)
    , mAttackDamage(0)
{
    std::cout << "ClapTrap is made by default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : mName(name)
    , mHitPoint(10)
    , mEnergyPoint(10)
    , mAttackDamage(0)
{
    std::cout << mName << " is made by constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoint, unsigned int energyPoint, unsigned int attackDamage)
    : mName(name)
    , mHitPoint(hitPoint)
    , mEnergyPoint(energyPoint)
    , mAttackDamage(attackDamage)
{
    std::cout << mName << " is made by constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
    : mName(clapTrap.mName)
    , mHitPoint(clapTrap.mHitPoint)
    , mEnergyPoint(clapTrap.mEnergyPoint)
    , mAttackDamage(clapTrap.mAttackDamage)
{
    std::cout << mName << " is made by copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    mName = clapTrap.mName;
    mHitPoint = clapTrap.mHitPoint;
    mEnergyPoint = clapTrap.mEnergyPoint;
    mAttackDamage = clapTrap.mAttackDamage;
    
    std::cout << mName << " is created by Copy assignment operator" << std::endl;

    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << mName << " is deleted" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (mEnergyPoint == 0 || mHitPoint == 0)
    {
        std::cout << "ClapTrap" << mName << " can not attack!" << std::endl;
        return ;
    }

    std::cout << "ClapTrap " << mName << " attacks " \
            << target << ", causing " << mAttackDamage \
            << " points of damage!" << std::endl;

    --mEnergyPoint;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (mHitPoint == 0)
    {
        std::cout << mName << " is died" << std::endl;
        return ;
    }
    

    if (mHitPoint >= amount)
    {
        mHitPoint -= amount;
    }
    else
    {
        mHitPoint = 0;
    }

    std::cout << mName << " take damage " 
            << amount << ", now hp is " << mHitPoint << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (mEnergyPoint == 0 || mHitPoint == 0)
    {
        std::cout << mName << " can not repaired!" << std::endl;
        return ;
    }
    
    mHitPoint += amount;

    std::cout << mName << " is repaired of " 
            << amount << ", now hp is " << mHitPoint << std::endl;

    --mEnergyPoint;
}