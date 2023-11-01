#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

# define DEFAULT "\001\033[0;39m\002"
# define MAGENTA "\001\033[1;95m\002"

template< typename T >
T const &	max( T const & x, T const & y)
{
	return ( (x>y) ? x : y );
}

template< typename T >
T const &	min( T const & x, T const & y)
{
	return ( (x<y) ? x : y );
}

template< typename T >
void	swap( T & x, T & y)
{
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
}

#endif