//이게 어떤 변수인지 알아낸다음
//더블 변수로 변경한다
//더블로 변경한 걸  해당 자자료료형으로 바바꾸꾸고  그  자자료료형형에에서  또  변경한다

#include "Parser.hpp"

Parser::Parser()
    : value("default")
    , isPrintable(false)
    , isParsed(false)
{
}

Parser::Parser(std::string value)
    : value(value)
    , isPrintable(false)
    , isParsed(false)
{
}

Parser::Parser(const Parser &other)
    : value(other.value)
    , valueToChar(other.valueToChar)
    , valueToInt(other.valueToInt)
    , valueToFloat(other.valueToFloat)
    , valueToDouble(other.valueToDouble)
    , isPrintable(other.isPrintable)
    , isParsed(other.isParsed)
{
}

Parser &Parser::operator=(const Parser &other)
{
    value = other.value;
    valueToChar = other.valueToChar;
    valueToInt = other.valueToInt;
    valueToFloat = other.valueToFloat;
    valueToDouble = other.valueToDouble;
    isPrintable = other.isPrintable;
    isParsed = other.isParsed;
    
    return (*this);
}

Parser::~Parser()
{
}

void Parser::setValue(std::string value)
{
    this->value = value;
}

void Parser::parseValue()
{

}

void Parser::printValue()
{
    if (isParsed == false)
    {
        parseValue();
    }

}

