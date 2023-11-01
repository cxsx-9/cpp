#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

# define DEFAULT "\001\033[0;39m\002"
# define MAGENTA "\001\033[1;95m\002"

template< typename T >
void	print(T &item)
{
	std::cout <<  " >> " << item  << std::endl;
}

template< typename T >
void	iter(const T * array, int & length, void( * function)(const T &))
{
	int i = 0;
	while (i < length)
	{
		function(array[i]);
		i++;
	}
}

#endif