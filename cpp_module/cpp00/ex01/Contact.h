#include <iostream>
#include <iomanip>

class Contact
{
public:
    Contact();
    void setContact();
    void printContact();
    void printColumn(std::string str);
    void printContactDetail();

private:
    std::string mFirstName;
    std::string mLastName;
    std::string mNickName;
    std::string mPhoneNumber;
    std::string mDarkestSecret;
};