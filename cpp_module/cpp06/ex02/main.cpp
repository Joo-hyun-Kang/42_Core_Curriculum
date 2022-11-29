#include "main.hpp"

Base* generate(void)
{
	int randomValue = (rand() % 3);

    if (randomValue == 0)
    {
        return new A();
    }
    else if (randomValue == 1)
    {
        return new B();
    }
    else
    {
        return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
    {
        std::cout << "pointer : A" << std::endl;
    }
	else if (dynamic_cast<B*>(p) != NULL)
    {
		std::cout << "pointer : B" << std::endl;
    }
	else if (dynamic_cast<C*>(p) != NULL)
    {
		std::cout << "pointer : C" << std::endl;
    }
}

void identify(Base& p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "reference : A" << std::endl;
		(void)a;
	} 
    catch (std::exception& e) 
    {
    }

	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "reference : B" << std::endl;
		(void)b;
	} 
    catch (std::exception& e) 
    {
    }

	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "reference : C" << std::endl;
		(void)c;
	} 
    catch (std::exception& e) 
    {
    }
}

int main(void)
{
    srand(time(NULL));
    
    Base* base = generate();
    identify(base);
    identify(*base);

    delete base;

    Base* base2 = generate();
    identify(base2);
    identify(*base2);

    delete base2;
}