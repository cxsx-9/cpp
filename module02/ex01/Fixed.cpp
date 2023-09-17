#include "Fixed.hpp"

const int   Fixed::frac_ = 8;

Fixed::Fixed(void): f_val_(0)
{
	std::cout << "Defualt constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->f_val_ = num << this->frac_;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->f_val_ = roundf(num * (1 << this->frac_));
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
	this->f_val_ = copy.f_val_;
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

float Fixed::toFloat( void ) const
{
	return ((float)this->f_val_ / (float)(1 << this->frac_));
}

int	Fixed::toInt( void ) const
{
	return (this->f_val_ >> this->frac_);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}
