#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *mBrain;

public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat& other);
    ~Cat();
    void makeSound() const;
    Brain &getBrain() const;
};

#endif