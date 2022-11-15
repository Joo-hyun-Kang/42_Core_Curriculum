#include <iostream>
#include "Contact.h"

class Phonebook
{
public:
    Phonebook();

    Contact *getContacts();
    void    setContact();

    void    add();

private:
    Contact **mContact;
    int mCount;
    int mMax_count;
};