#ifndef FRAGTRAP_CPP
# define FRAGTRAP_CPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:

public:
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(const FragTrap &fragTrap);
    FragTrap& operator=(const FragTrap &fragTrap);
    virtual ~FragTrap();

    void highFivesGuys(void);
};

#endif