#include "Fixed.hpp"

const int Fixed::FRACTIONAL_BITS = 8;

Fixed::Fixed()
    : mValue(0)
{
}

Fixed::Fixed(const int value)
{
    mValue = value << Fixed::FRACTIONAL_BITS;
}

Fixed::Fixed(const float value)
{
    mValue = (int)roundf(value * (1 << Fixed::FRACTIONAL_BITS));
}

Fixed::Fixed(const Fixed &fixed)
{
    mValue = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    mValue = fixed.getRawBits();

    return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
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

bool Fixed::operator>(const Fixed &fixed)
{
    return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed)
{
    return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed)
{
    return this->getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed)
{
    return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed)
{
    return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed)
{
    return this->getRawBits() != fixed.getRawBits();    
}

Fixed Fixed::operator+(const Fixed &fixed)
{
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed)
{
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed)
{
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed)
{
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void)
{
    mValue++;
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    mValue--;
    return (*this);
}

const Fixed Fixed::operator++(int)
{
    Fixed origin(*this);
    mValue++;

    return origin;
}

const Fixed Fixed::operator--(int)
{
    Fixed origin(*this);
    mValue--;

    return origin;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() >= b.getRawBits())
    {
        return b;
    }
    else
    {
        return a;
    }
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() >= b.getRawBits())
    {
        return b;
    }
    else
    {
        return a;
    }
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() >= b.getRawBits())
    {
        return a;
    }
    else
    {
        return b;
    }
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() >= b.getRawBits())
    {
        return a;
    }
    else
    {
        return b;
    }
}