#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <limits.h>

class Convert {
private:
    std::string value;
    double doubleValue;
    char *endptr;
public:
    Convert();
    Convert(std::string value);
    Convert(Convert const &convert);
    ~Convert();
    Convert& operator=(Convert const &convert);

    void charConvert() const;
    void intConvert() const;
    void floatConvert() const;
    void doubleConvert() const;
    void convertAll() const;

    bool checkValid(std::string value) const;
    bool checkIsConvertable() const;

    std::string getValue() const;
    double getDoubleValue() const;
};

#endif

#include "Convert.hpp"

Convert::Convert() { }

Convert::Convert(std::string value) {
    this->value = value;
    doubleValue = strtod(this->value.c_str(), &(this->endptr));
}

Convert::~Convert() { }

Convert::Convert(Convert const &convert) {
    *this = convert;
}

Convert& Convert::operator=(Convert const &convert) {
    this->value = convert.getValue();
    this->doubleValue = convert.getDoubleValue();
    return *this;
}

void Convert::charConvert() const {
    std::cout << "char: ";
    if (!checkValid(this->value)) {
        std::cout << "impossible\n";
    } else if (this->doubleValue < 33 || this->doubleValue > 128) {
        std::cout << "Non displayable\n";
    } else {
        std::cout << "'" << static_cast<char>(doubleValue) << "'\n";
    }
}

void Convert::intConvert() const {
    std::cout << "int: ";
    if (!checkValid(this->value)) {
        std::cout << "impossible\n";
    } else if (this->doubleValue > INT_MAX || this->doubleValue < INT_MIN) {
        std::cout << "impossible\n";
    } else {
        std::cout << static_cast<int>(doubleValue) << "\n";
    }
}

void Convert::floatConvert() const {
    std::cout << "float: ";
    if (!checkValid(this->value)) {
        std::cout << this->value << "f\n";
    } else if (static_cast<int>(doubleValue) == doubleValue) {
        std::cout << static_cast<float>(doubleValue) << ".0f\n";
    } else if (this->value.find(".") != std::string::npos) {
        std::cout << static_cast<float>(doubleValue) << "f\n";
    } else {
        std::cout << static_cast<float>(doubleValue) << ".0f\n";
    }
}

void Convert::doubleConvert() const {
    std::cout << "double: ";
    if (!checkValid(this->value)) {
        std::cout << this->value << "\n";
    } else if (static_cast<int>(doubleValue) == doubleValue) {
        std::cout << doubleValue << ".0\n";
    } else if (this->value.find(".") != std::string::npos) {
        std::cout << doubleValue << "\n";
    } else {
        std::cout << doubleValue << ".0\n";
    }
}

void Convert::convertAll() const {
    if (!this->checkIsConvertable()) {
        std::cout << "Wrong inputs\n";
    } else {
        this->charConvert();
        this->intConvert();
        this->floatConvert();
        this->doubleConvert();
    }
}

bool Convert::checkValid(std::string value) const {
    if (value == "nan" || value == "-inf" || value == "+inf" || value == "inf") {
        return false;
    } else {
        return true;
    }
}

bool Convert::checkIsConvertable() const {
    if (*(this->endptr) && !(*(this->endptr) == 'f'))
        return false;
    return true;
}

std::string Convert::getValue() const {
    return this->value;
}

double Convert::getDoubleValue() const {
    return this->doubleValue;
}