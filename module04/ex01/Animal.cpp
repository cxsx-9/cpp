#include "Animal.hpp"

Animal::Animal ( void ) : _type("Neutral")
{
	std::cout << YELLOW << "Animal type " << this->getType() << " has been created!" << DEFAULT << std::endl;
}

Animal::~Animal ( void )
{
	std::cout << YELLOW << "Animal type " << this->getType() << " has gone" << DEFAULT << std::endl;
}

Animal::Animal( const Animal &copy )
{
	this->_type = copy.getType() + " (copy)";
	std::cout << GRAY << "Animal type " << this->getType() << " has been created! (copy)" << DEFAULT << std::endl;
}

Animal	const &Animal::operator=(const Animal &copy)
{
	this->setType(copy._type);
	return (*this);
}

void	Animal::setType ( std::string type )
{
	this->_type = type;
}

std::string const	Animal::getType ( void ) const
{
	return (this->_type);
}

void	Animal::openTheBrain() const
{
	std::cout << "There's no Brain here. ;-;" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << this->getType() << " : Wheeee e e .. . .  " << std::endl;
}
