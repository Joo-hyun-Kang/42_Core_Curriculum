#include "Parser.hpp"

Parser::Parser()
    : value("default")
    , valueToChar(0)
    , valueToInt(0)
    , valueToFloat(0)
    , valueToDouble(0)
    , isPrintable(true)
    , isParsed(false)
    , isInf(false)
{
}

Parser::Parser(std::string v)
    : value(v)
    , valueToChar(0)
    , valueToInt(0)
    , valueToFloat(0)
    , valueToDouble(0)
    , isPrintable(true)
    , isParsed(false)
    , isInf(false)
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
    , isInf(other.isInf)
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
    isInf = other.isInf;
    
    return (*this);
}

Parser::~Parser()
{
}

void Parser::setValue(std::string value)
{
    this->value = value;
    isParsed = false;
    isInf = false;
    isPrintable = true;
}

void Parser::parseValue()
{
    //숫자가 아닐 떄
    if (value == "nan" || value == "nanf")
    {
        valueToDouble = sqrt(-1.0);
        
        isParsed = true;
        return ;
    }
    
    //무한대일 때
    if (value == "inf" || value == "+inf" || value == "-inf" || \
    value == "inff" || value == "+inff" || value == "-inff")
	{
        if (value[0] == '-')
        {
            valueToDouble = -1;
        }
        else
        {
            valueToDouble = 1;
        }

        isParsed = true;
        isInf = true;
        return ;
    }

    //문자열인 경우
    if (value.length() == 1 && isdigit(value[0]) == false)
    {
        valueToChar = static_cast<char>(value[0]);
        valueToInt = static_cast<int>(value[0]);
        valueToFloat = static_cast<float>(value[0]);
        valueToDouble = static_cast<double>(value[0]);

        isParsed = true;
        return ;
    }

    //정수인 경우와 출력 불가능한 문자일 때
    size_t indexFloatPoint = value.find('.');
    if (indexFloatPoint == std::string::npos)
    {
        valueToInt = atoi(value.c_str());

        std::string intToString;
        std::stringstream stream;

        stream << valueToInt;
        intToString = stream.str();

        if (intToString == value)
        {
            valueToChar = static_cast<char>(valueToInt);
            valueToFloat = static_cast<float>(valueToInt);
            valueToDouble = static_cast<double>(valueToInt);
        }
        else
        {
            isPrintable = false;
        }

        isParsed = true;
        return ;
    }

    //부동소수점일 경우와 출력 불가능할 때
    char *posAfterLiteral;
    valueToDouble = strtod(value.c_str(), &posAfterLiteral);

    if (*posAfterLiteral == '\0' || (*posAfterLiteral == 'f' && posAfterLiteral == &value[value.length() - 1]))
    {
        valueToChar = static_cast<char>(valueToDouble);
        valueToInt = static_cast<int>(valueToDouble);
        valueToFloat = static_cast<float>(valueToDouble);
    }
    else
    {
        isPrintable = false;
    }

    isParsed = true;
    return ;
}

void Parser::printValue()
{
    if (isParsed == false)
    {
        parseValue();
    }

    printToChar();
    printToInt();
    printToFloat();
    printToDouble();

    std::cout << std::endl;
}

void Parser::printToChar(void) const
{
    std::stringstream stream;
    stream << "char: ";
	
	if (isPrintable == false || isnan(valueToDouble) || isInf == true)
    {
        stream << "impossible";
    }
	else if (valueToInt >= 32 && valueToInt <= 126)
    {
        stream << valueToChar;
    }
	else if (valueToInt >= 0 && valueToInt < 32)
    {
        stream << "Non displayable";
    }
	else
    {
        stream << "impossible";
    }

    std::cout << stream.str() << std::endl;
}

void Parser::printToInt(void) const
{
    std::stringstream stream;
    stream << "int: ";
	
    if (isPrintable == false || isnan(valueToDouble) || isInf == true)
    {
        stream << "impossible";
    }
    else
    {
        stream << valueToInt;
    }
	
    std::cout << stream.str() << std::endl;
}

void Parser::printToFloat(void) const
{
	std::stringstream stream;
    stream << "float: ";
    
    if (isPrintable == false)
    {
        stream << "impossible";        
    }
	else if (isnan(valueToDouble))
    {
        stream << "nanf";           
    }
	else if (isInf == true)
    {
        if (valueToDouble > 0)
        {
            stream << "inff";                
        }
        else
        {
            stream << "-inff";                
        }
    }
    else
    {
        stream << valueToFloat;

        if (valueToInt == static_cast<int>(valueToFloat))
        {
            std::stringstream temp;
            temp << valueToInt;
            
            if (temp.str().length() > 6)
            {
                stream << "f";
            }
            else
            {
                stream << ".0f";
            }
        }
        else
        {
            stream << "f";
        }
    }

    std::cout << stream.str() << std::endl;
}

void Parser::printToDouble(void) const
{
	std::stringstream stream;
    stream << "double: ";
    
    if (isPrintable == false)
    {
        stream << "impossible";        
    }
	else if (isnan(valueToDouble))
    {
        stream << "nan";
    }
	else if (isInf == true)
    {
        if (valueToDouble > 0)
        {
            stream << "inf";                
        }
        else
        {
            stream << "-inf";                
        }
    }
    else
    {
        stream << valueToDouble;

        if (valueToInt == static_cast<int>(valueToDouble))
        {
            std::stringstream temp;
            temp << valueToInt;
            
            if (temp.str().length() <= 6)
            {
                stream << ".0";
            }
        }
    }

    std::cout << stream.str() << std::endl;
}