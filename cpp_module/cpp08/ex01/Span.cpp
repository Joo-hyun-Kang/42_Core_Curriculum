#include "Span.hpp"

Span::Span(void) 
    : size(16)
{
    vec.reserve(16);
}

Span::Span(unsigned int n)
    : size(n)
{
    vec.reserve(n);
}

Span::Span(Span const &other)
    : vec(other.vec)
    , size(other.size)
{ 
}

Span& Span::operator=(const Span &other)
{
    if (this == &other)
    {
        return *this;
    }
    
    size = other.getSize();
    vec = other.vec;

    return *this;
}

Span::~Span(void) 
{
    vec.clear();
}

void Span::addNumber(int num) 
{
    if (size == vec.size())
    {
        throw std::runtime_error("addNumber : capacity out!");
    }
    vec.push_back(num);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{   
    if (vec.size() + std::distance(begin, end) > size)
    {
        throw std::runtime_error("addNumbers : capacity out!");
    }
	else
    {
		vec.insert(vec.end(), begin, end);
    }
}

int Span::shortestSpan(void) const {
    if (this->vec.size() < 2)
    {
        throw std::runtime_error("Vector requires at least 2 values.");
    }

    std::vector<int> sortedVec(vec);
    std::sort(sortedVec.begin(), sortedVec.end());

    std::vector<int>::iterator iter = sortedVec.begin();
    int preValue = *iter;
    int minSpan = longestSpan();

    iter++;
    while (iter != sortedVec.end()) 
    {
        if (*iter - preValue < minSpan)
        {
            minSpan = *iter - preValue;
        }
        preValue = *iter;
        iter++;
    }

    return minSpan;
}

int Span::longestSpan(void) const {
    if (this->vec.size() < 2)
    {
        throw std::runtime_error("Vector requires at least 2 values.");
    }

    return (*std::max_element(this->vec.begin(), this->vec.end()) - *std::min_element(this->vec.begin(), this->vec.end()));
}

unsigned int Span::getSize(void) const
{
    return this->size;
}

std::vector<int> Span::getVector(void) const
{
	return this->vec;
}
