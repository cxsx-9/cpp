#include "AAnimal.hpp"

AAnimal::AAnimal ( void ) : _type("Neutral")
{
	std::cout << YELLOW << "Abstract Animal type " << this->getType() << " has been created!" << DEFAULT << std::endl;
}

AAnimal::~AAnimal ( void )
{
	std::cout << YELLOW << "Abstract Animal type " << this->getType() << " has gone" << DEFAULT << std::endl;
}

AAnimal::AAnimal( const AAnimal &copy )
{
	*this = copy;
}

AAnimal	const &AAnimal::operator=(const AAnimal &copy)
{
	this->setType(copy._type);
	return (*this);
}

void	AAnimal::setType ( std::string type )
{
	this->_type = type;
}

std::string const	AAnimal::getType ( void ) const
{
	return (this->_type);
}
