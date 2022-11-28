#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat intern("intern", 150);
    Bureaucrat nine("nine", 90);
    Bureaucrat seven("seven", 70);
    Bureaucrat minister("minister", 5);
    
    Form *shrub = new ShrubberyCreationForm("tree1");
    intern.executeForm(*shrub);
    delete shrub;
    shrub = NULL;

    shrub = new ShrubberyCreationForm("tree2");
    nine.signForm(*shrub);
    nine.executeForm(*shrub);
    delete shrub;
    shrub = NULL;

    Form *robo = new RobotomyRequestForm("robo1");
    nine.signForm(*robo);
    nine.executeForm(*robo);
    delete robo;
    robo = NULL;

    robo = new RobotomyRequestForm("robo2");
    seven.signForm(*robo);
    seven.executeForm(*robo);
    delete robo;
    robo = NULL;

    robo = new RobotomyRequestForm("robo3");
    minister.signForm(*robo);
    minister.executeForm(*robo);
    delete robo;
    robo = NULL;

    Form *pres = new PresidentialPardonForm("obama");
    seven.signForm(*pres);
    seven.executeForm(*pres);
    delete pres;
    pres = NULL;

    pres = new PresidentialPardonForm("trump");
    minister.signForm(*pres);
    minister.executeForm(*pres);
    delete pres;
    pres = NULL;

    //system("leaks Form");

    return 0;
}