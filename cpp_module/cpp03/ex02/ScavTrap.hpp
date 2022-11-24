#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &scavTrap);
    ScavTrap& operator=(const ScavTrap &scavTrap);
    virtual ~ScavTrap();

    virtual void attack(const std::string& target);
    void guardGate();
};

#endif