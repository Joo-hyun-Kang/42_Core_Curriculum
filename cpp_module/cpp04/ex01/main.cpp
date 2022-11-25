#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    std::cout << std::endl;

    {
        Animal **animals = new Animal*[100];

        for (int i = 0; i < 50; i++)
        {
            animals[i] = new Cat();
            animals[i + 50] = new Dog();
            std::cout << i << " " << i + 50 << std::endl;
        }

        for (int i = 0; i < 100; i++)
        {
            animals[i]->makeSound();
        }

        for (int i = 0; i < 100; i++)
        {
            delete animals[i];
            std::cout << i << " is deleted" << std::endl;
        }

        delete[] animals;
    }

    //system("leaks Animals");
    
    return 0;
}