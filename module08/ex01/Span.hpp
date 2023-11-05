#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"
# define DEBUG "\001\033[1;93m\002"
# define RED "\001\033[1;91m\002"
# define MAGENTA "\001\033[1;95m\002"

class Span
{
    private:
        std::vector<int>    _vec;
        unsigned int        _max;
    public:
        Span();
        ~Span();
        Span(const Span &copy);
        Span &operator=(const Span &copy);

        Span(unsigned int n);
        void addNumber(int number);
        void addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
        int shortestSpan();
        int longestSpan();

        
        // extension
        void print();
};

template< typename T >
T absolute( T x)
{
    return ( (x<0) ? -x : x);
}

#endif