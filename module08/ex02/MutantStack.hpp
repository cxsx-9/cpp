#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

// https://en.cppreference.com/w/cpp/header/stack

# include <iostream>
# include <stack>
# include <vector>

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"
# define DEBUG "\001\033[1;93m\002"
# define RED "\001\033[1;91m\002"
# define MAGENTA "\001\033[1;95m\002"

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {}
        ~MutantStack() {}
        MutantStack(const MutantStack<T> & copy){ *this = copy; }
        MutantStack &operator=(const MutantStack<T> & copy)
        {
            this->c = copy.c;
            return (*this);
        }

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin(){ return (this->c.begin()); }
        iterator end(){ return (this->c.end()); }
};

#endif