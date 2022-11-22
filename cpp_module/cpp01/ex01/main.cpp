#include "Zombie.hpp"

int main(void)
{
    int count = 1;
    Zombie *zombies = zombieHorde(count, "seoul");
    for (int i = 0; i < count; i++)
    {
        zombies[i].announce();
    }
    delete[] zombies;

    count = 3;
    zombies = zombieHorde(count, "tokyo");
    for (int i = 0; i < count; i++)
    {
        zombies[i].announce();
    }
    delete[] zombies;

    return 0;
}