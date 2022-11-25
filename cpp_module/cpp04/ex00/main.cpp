#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    {
        Animal stack;
        stack.makeSound();

        Animal *heap = new Animal();
        heap->makeSound();    
        delete heap;

        std::cout << std::endl;
    }

    {
        Animal *hidden_dog = new Dog();
        Dog *real_dog = new Dog();

        hidden_dog->makeSound();
        real_dog->makeSound();

        delete hidden_dog;
        delete real_dog;
        
        std::cout << std::endl;
    }

    {
        Animal *hidden_cat = new Cat();
        Cat *real_cat = new Cat();

        hidden_cat->makeSound();
        real_cat->makeSound();

        delete hidden_cat;
        delete real_cat;

        std::cout << std::endl;
    }

// {
//     Animal **animals = new Animal*[3];
//     animals[0] = new Animal();
//     animals[1] = new Cat();
//     animals[2] = new Dog();

//     for (int i = 0; i < 3; i++)
//     {
//         animals[i]->makeSound();
//     }

//     for (int i = 0; i < 3; i++)
//     {
//         delete animals[i];
//     }

//     delete[] animals;
// }


    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;

    std::cout << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    const WrongCat* wrongCat2 = new WrongCat();

    wrongAnimal->makeSound();
    wrongCat->makeSound();
    wrongCat2->makeSound();

    delete wrongAnimal;
    delete wrongCat;
    delete wrongCat2;

    return 0;
}