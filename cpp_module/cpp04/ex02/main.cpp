#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    // {
    //     Animal stack;
    //     stack.makeSound();

    //     Animal *heap = new Animal();
    //     heap->makeSound();    
    //     delete heap;

    //     std::cout << std::endl;
    // }

    {
        Animal *hidden_dog = new Dog();
        Dog *real_dog = new Dog();

        hidden_dog->makeSound();
        real_dog->makeSound();

        delete hidden_dog;
        delete real_dog;
        
        std::cout << std::endl;
    }

    return 0;
}