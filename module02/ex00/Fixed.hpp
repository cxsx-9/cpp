#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					num_;
		static const int	frac_;
	public:
		Fixed( void );
		Fixed( const Fixed &copy );
		Fixed &operator=(const Fixed &copy);
		~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif