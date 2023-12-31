#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					f_val_;
		static const int	frac_;
	public:
		Fixed( void );
		Fixed( const int num );
		Fixed( const float num );
		Fixed( const Fixed &copy );
		Fixed &operator=(const Fixed &copy);
		~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed);

#endif