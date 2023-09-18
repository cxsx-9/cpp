#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal ( void ) : _type("Alien!#$%")
{
	std::cout << YELLOW << "WrongAnimal type " << this->getType() << " has been created!" << DEFAULT << std::endl;
}

WrongAnimal::~WrongAnimal ( void )
{
	std::cout << YELLOW << "WrongAnimal type " << this->getType() << " has gone" << DEFAULT << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &copy )
{
	*this = copy;
}

WrongAnimal	const &WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->setType(copy._type);
	return (*this);
}

void	WrongAnimal::setType ( std::string type )
{
	this->_type = type;
}

std::string const	WrongAnimal::getType ( void ) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << this->getType() << " : Whoooo o o .. . .  @# &# % # !" << std::endl;
}
