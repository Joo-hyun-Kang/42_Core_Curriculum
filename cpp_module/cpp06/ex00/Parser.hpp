#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <cmath>
#include <cctype>
#include <sstream>

class Parser 
{
private:
    std::string value;
    char valueToChar;
    int valueToInt;
    float valueToFloat;
    double valueToDouble;
    bool isPrintable;
    bool isParsed;
    bool isInf;

    void printToChar(void) const;
    void printToInt(void) const;
    void printToFloat(void) const;
    void printToDouble(void) const;

public:
    Parser();
    Parser(std::string v);
    Parser(const Parser &other);
    Parser &operator=(const Parser &other);
    ~Parser();

    void setValue(std::string value);
    void parseValue();
    void printValue();
};

#endif