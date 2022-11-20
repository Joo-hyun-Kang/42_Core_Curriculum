#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
    std::string mFirstName;
    std::string mLastName;
    std::string mNickName;
    std::string mPhoneNumber;
    std::string mDarkestSecret;
    void printColumn(std::string str);

public:
    Contact();
    void setContact();
    void printContact();
    void printContactDetail();
};

#endif