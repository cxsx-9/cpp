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
		~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		Fixed	&operator=( const Fixed &copy );

		Fixed	&operator++(void);  // pre increment
		Fixed	&operator--(void);
		Fixed	operator++( int num ); // post increment
		Fixed	operator--( int num );

		// bool
		bool	operator>( const Fixed &copy ) const;
		bool	operator<( const Fixed &copy ) const;
		bool	operator>=( const Fixed &copy ) const;
		bool	operator<=( const Fixed &copy ) const;
		bool	operator==( const Fixed &copy ) const;
		bool	operator!=( const Fixed &copy ) const;

		// math
		Fixed	operator+( const Fixed &copy ) const;
		Fixed	operator-( const Fixed &copy ) const;
		Fixed	operator*( const Fixed &copy ) const;
		Fixed	operator/( const Fixed &copy ) const;

		//min max
		static const Fixed	&min( const Fixed &copy1, const Fixed &copy2 );
		static const Fixed	&max( const Fixed &copy1, const Fixed &copy2 );
};

std::ostream	&operator<<( std::ostream &out, Fixed const &fixed );
//  >, <, >=, <=, == and !=		done
// +, -, *, and /				done
// The 4 increment/decrement
// min max

#endif