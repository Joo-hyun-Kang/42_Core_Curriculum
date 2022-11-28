#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>

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
    
public:
    Parser();
    Parser(std::string value);
    Parser(const Parser &other);
    Parser &operator=(const Parser &other);
    ~Parser();

    void setValue(std::string value);
    void parseValue();
    void printValue();

};


#endif