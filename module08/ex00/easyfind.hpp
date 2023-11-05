#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <vector>
# include <list>
# include <iostream>

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"
# define DEBUG "\001\033[1;93m\002"
# define RED "\001\033[1;91m\002"
# define GREEN "\001\033[1;92m\002"
# define BLUE "\001\033[1;94m\002"
# define CYAN "\001\033[1;96m\002"
# define MAGENTA "\001\033[1;95m\002"
# define GRAY "\001\033[1;90m\002"

// using typename T for STL (standard template library)
// input_iterator > std::find(input_iterator first, input_iterator last, const T& value);

// If the value is found in the sequence, the iterator to its position is returned.
// If the value is not found, the iterator to the last position is returned.

template<typename T>
typename T::const_iterator easyfind(T &container, int target)
{
    typename T::const_iterator it = find(container.begin(), container.end(), target);
    if (it == container.end())
        throw std::out_of_range("Not found");
    return (it);
}

#endif