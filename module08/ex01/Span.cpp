#include "Span.hpp"

Span::Span(){}

Span::~Span(){}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span &Span::operator=(const Span &copy)
{
    _vec = copy._vec;
    _max = copy._max;
    return (*this);
}

Span::Span(unsigned int n) : _max(n){}

void Span::addNumber(int number)
{
    if (_vec.size() == _max)
        throw std::out_of_range ("Array is full, Can't add anymore.");
    _vec.push_back(number);
}

int Span::shortestSpan()
{
    int size = _vec.size();
    if (!size)
        throw std::underflow_error("Array has nothing, Can't find a span");
    if (size == 1)
        return (0);
    int tmp = this->longestSpan();
    std::vector<int> sortVec = _vec;
    std::sort(sortVec.begin(), sortVec.end());
    std::vector<int>::const_iterator it;
    for (it = sortVec.begin(); it != sortVec.end(); it++)
    {
        int diff = ::absolute(*it - *(it - 1));
        if (it != sortVec.begin() && diff < tmp)
            tmp = diff;
    }
    return (tmp);
}

int Span::longestSpan()
{
    int size = _vec.size();
    if (!size)
        throw std::underflow_error("Array has nothing, Can't find a span");
    if (size == 1)
        return (0);
    std::vector<int>::const_iterator min = min_element(_vec.begin(), _vec.end());
    std::vector<int>::const_iterator max = max_element(_vec.begin(), _vec.end());
    return (*max - *min);
}

void Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    unsigned int size = _vec.size();
    if (size == _max || _max - size < std::distance(begin, end))
        throw std::out_of_range ("Array is full, Can't add anymore.");
    _vec.insert(_vec.end(), begin, end);
}

void Span::print() // DEBUG
{
    std::vector<int>::const_iterator it;
	std::cout << "[ ";
	for (it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
}
