#include "Contact.hpp"

Contact::Contact()
{
}

void Contact::setContact()
{
    std::cout << "write Firstname" << std::endl;
    std::getline(std::cin >> std::ws, mFirstName);

    std::cout << "write Lastname: "<< std::endl;
    std::getline(std::cin >> std::ws, mLastName);

    std::cout << "write Nickname: " << std::endl;
    std::getline(std::cin >> std::ws, mNickName);

    std::cout << "write Phonenumber: " << std::endl;
    std::getline(std::cin >> std::ws, mPhoneNumber);

    std::cout << "write Darkestsecret: " << std::endl;
    std::getline(std::cin >> std::ws, mDarkestSecret);
}

void Contact::printContact()
{
    printColumn(mFirstName);
    printColumn(mLastName);
    printColumn(mNickName);
    std::cout << std::endl;
}

void Contact::printColumn(std::string str)
{
    if (str.length() <= 10)
    {
        std::cout << std::right << std::setw(10) << str << "|";
    }
    else
    {
        std::cout << str.substr(0, 9) << "." << "|";
    }
}

void Contact::printContactDetail()
{
	std::cout << "first name : " << mFirstName << std::endl;
	std::cout << "last name : " << mLastName << std::endl;
	std::cout << "nickname : " << mNickName << std::endl;
	std::cout << "phone number : " << mPhoneNumber << std::endl;
	std::cout << "darkest secret : " << mDarkestSecret << std::endl;
}