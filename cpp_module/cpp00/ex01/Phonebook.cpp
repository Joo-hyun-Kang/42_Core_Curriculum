#include "PhoneBook.hpp"

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

    for (unsigned int i = 0; i < mTotal && i < MAX_CONTACTS; i++)
    {
        std::cout << std::right << std::setw(10) << i + 1 << "|";
        mContacts[i].printContact();
    }

    
    std::cout << "the index of the entry to display" << std::endl;

    unsigned index;
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
