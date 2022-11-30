#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

class Span {
private:
    std::vector<int> vec;
    unsigned int size;
    Span(void);

public:
    Span(unsigned int n);
    Span(const Span &other);
    Span& operator=(const Span &other);
    ~Span(void);

    void addNumber(int num);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    int longestSpan(void) const;
    int shortestSpan(void) const;

    unsigned int getSize(void) const;
    std::vector<int> getVector(void) const;
};

#endif