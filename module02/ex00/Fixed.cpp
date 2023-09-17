#include "Fixed.hpp"

const int   Fixed::frac_ = 8;

Fixed::Fixed(void): f_val_(0)
{
	std::cout << "Defualt constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed   &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->f_val_ = copy.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->f_val_);
}

void Fixed::setRawBits( int const raw )
{
	this->f_val_ = raw;
}
