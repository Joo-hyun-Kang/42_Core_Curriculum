#include "Fixed.hpp"

const int Fixed::FRACTIONAL_BITS = 8;

Fixed::Fixed()
    : mValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    mValue = value << Fixed::FRACTIONAL_BITS;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    mValue = (int)roundf(value * (1 << Fixed::FRACTIONAL_BITS));
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    mValue = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    mValue = fixed.getRawBits();

    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;

    return mValue;
}

void Fixed::setRawBits(int const raw)
{
    mValue = raw;
}

float Fixed::toFloat(void) const
{
    return (float)mValue / (1 << Fixed::FRACTIONAL_BITS);
}

int Fixed::toInt(void) const
{
    return (mValue >> Fixed::FRACTIONAL_BITS);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}