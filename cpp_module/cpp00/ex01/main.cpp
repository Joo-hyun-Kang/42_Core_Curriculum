#include "Contact.h"
#include <iostream>
#include <iomanip>

class PhoneBook
{
private:
    Contact mContacts[8];
    unsigned int mIndex;
    unsigned int mTotal;
    const unsigned int MAX_CONTACTS;

public:
    PhoneBook();
    void addContact();
    void searchContact();

    void printAllContacts();
};

PhoneBook::PhoneBook()
    : mIndex(0)
    , mTotal(0)
    , MAX_CONTACTS(8)
{
}

void PhoneBook::addContact()
{
    if (mIndex == MAX_CONTACTS)
    {
        mIndex %= MAX_CONTACTS;
    }
    mContacts[mIndex].setContact();
    mIndex++;
    mTotal++;
}

void PhoneBook::searchContact()
{
    if (mTotal == 0)
    {
        std::cout << "PhoneBook is empty. please add Contact" << std::endl;
        return ;
    }

    std::cout << std::right << std::setw(10) << "index" << "|"
            << std::right << std::setw(10) << "first name" << "|"
            << std::right << std::setw(10) << "last name" << "|"
            << std::right << std::setw(10) << "nickname" << "|"
            << std::endl;

    for (int i = 0; i < mTotal && i < MAX_CONTACTS; i++)
    {
        std::cout << std::right << std::setw(10) << i + 1 << "|";
        mContacts[i].printContact();
    }

    
    std::cout << "the index of the entry to display" << std::endl;

    int index;
    std::cin >> index;

    if (std::cin.fail() || index <= 0 || index > mTotal || index > MAX_CONTACTS)
    {
        std::cout << "Wrong Index!" << std::endl;
    }
    else
    {
        mContacts[index - 1].printContactDetail();
    }

    std::cin.clear();
    std::cin.ignore(LLONG_MAX, '\n');
}

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