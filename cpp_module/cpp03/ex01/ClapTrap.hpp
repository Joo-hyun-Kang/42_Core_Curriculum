#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string mName;
    unsigned int mHitPoint;
    unsigned int mEnergyPoint;
    unsigned int mAttackDamage;

public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(std::string name, unsigned int hitPoint, unsigned int energyPoint, unsigned int attackDamage);
    ClapTrap(const ClapTrap &clapTrap);
    ClapTrap& operator=(const ClapTrap &clapTrap);
    virtual ~ClapTrap();
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
