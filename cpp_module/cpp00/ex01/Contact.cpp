#include "Contact.h"

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, int phoneNumber, std::string secret)
    : mFirstName(firstName)
    , mLastName(lastName)
    , mNickName(nickName)
    , mPhoneNumber(phoneNumber)
    , mSecret(secret)
{
    std::cout << "Contact obj is maded!" << std::endl;
}