#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact mContacts[8];
    unsigned int mIndex;
    unsigned int mTotal;
    const unsigned int MAX_CONTACTS;
    void printAllContacts();

public:
    PhoneBook();
    void addContact();
    void searchContact();
};

#endif