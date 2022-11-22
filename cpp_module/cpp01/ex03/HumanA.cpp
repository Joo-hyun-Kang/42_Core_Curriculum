#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
    : mName(name)
    , mWeapon(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack(void) const
{
    std::cout << mName << " attacks with his " << mWeapon.getType() << std::endl;
}