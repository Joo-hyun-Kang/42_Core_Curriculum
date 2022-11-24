#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap japan("Japan");
    ClapTrap germany("Germany");
    
    japan.attack("Germany");
    germany.takeDamage(10);
    germany.takeDamage(5);
    germany.takeDamage(5);
    
    germany.attack("Japan");
    japan.takeDamage(10);
    japan.takeDamage(20);
    japan.takeDamage(30);

    japan.attack("Germany");
    japan.beRepaired(30);
}