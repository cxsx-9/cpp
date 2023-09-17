#include "Fixed.hpp"

const int   Fixed::frac_ = 8;

Fixed::Fixed(void): f_val_(0)
{
	// std::cout << "Defualt constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->f_val_ = num << this->frac_;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->f_val_ = roundf(num * (1 << this->frac_));
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed   &Fixed::operator=(const Fixed &copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->f_val_ = copy.f_val_;
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
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

// bool
bool	Fixed::operator>(const Fixed &copy) const
{
	return (this->toFloat() > copy.toFloat());
}

bool	Fixed::operator<(const Fixed &copy) const
{
	return (this->toFloat() < copy.toFloat());
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return (this->toFloat() >= copy.toFloat());
}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return (this->toFloat() <= copy.toFloat());
}

bool	Fixed::operator==(const Fixed &copy) const
{
	return (this->toFloat() == copy.toFloat());
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return (this->toFloat() != copy.toFloat());
}

// math
Fixed	Fixed::operator+(const Fixed &copy) const
{
	Fixed tmp = this->toFloat() + copy.toFloat();
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed &copy) const
{
	Fixed tmp = this->toFloat() - copy.toFloat();
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed &copy) const
{
	Fixed tmp = this->toFloat() * copy.toFloat();
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed &copy) const
{
	Fixed tmp = this->toFloat() / copy.toFloat();
	return (tmp);
}

// min max
 const Fixed	&Fixed::min(const Fixed &copy1, const Fixed &copy2)
{
	if (copy1.toFloat() < copy2.toFloat())
		return (copy1);
	return (copy2);
}

 const Fixed	&Fixed::max(const Fixed &copy1, const Fixed &copy2)
{
	if (copy1.toFloat() > copy2.toFloat())
		return (copy1);
	return (copy2);
}

// The 4 increment/decrement
Fixed	&Fixed::operator++(void)  // pre increment
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++( int num ) // post increment
{
	Fixed tmp = *this;
	if (num != 1)
		num = 1;
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed	Fixed::operator--( int num )
{
	Fixed tmp = *this;
	if (num != 1)
		num = 1;
	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}