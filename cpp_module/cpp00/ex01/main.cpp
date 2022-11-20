#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    std::string input;
    PhoneBook phonebook;

    while(true)
    {
        std::cout << "Please input what you want (ADD, SEARCH, EXIT)" << std::endl;

        std::getline(std::cin, input);

        if (input == "ADD")
        {
            phonebook.addContact();
        }
        else if (input == "SEARCH")
        {
            phonebook.searchContact();
        }
        else if (input == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Wrong command Try again!" << std::endl;
        }
    }
    
    return 0;
}