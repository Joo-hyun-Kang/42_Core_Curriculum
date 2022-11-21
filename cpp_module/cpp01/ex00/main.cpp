#include "Zombie.hpp"

int main(void)
{
    Zombie zombie("seoul");
    zombie.announce();

    randomChump("tokyo");

    Zombie *heapZombie = newZombie("newyork");
    heapZombie->announce();
    delete heapZombie;
    
    return 0;
}