#include <iostream>
#include <string>

class Contact
{
public:
    Contact(std::string firstName, std::string lastName, std::string nickName, int phoneNumber, std::string secret);

private:
    std::string mFirstName;
    std::string mLastName;
    std::string mNickName;
    int mPhoneNumber;
    std::string mSecret;
};