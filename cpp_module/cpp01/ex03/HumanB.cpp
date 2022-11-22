#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    : mName(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &weapon)
{
    mWeapon = &weapon;
}

void HumanB::attack(void) const
{
    std::cout << mName << " attacks with his " << mWeapon->getType() << std::endl;
}