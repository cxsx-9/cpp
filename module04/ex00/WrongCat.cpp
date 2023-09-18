#include "WrongCat.hpp"

WrongCat::WrongCat ( void )
{
	this->setType("AlienCat@#$ ! `  ~");
	std::cout << GRAY << "WrongCat type " << this->getType() << " has been created!" << DEFAULT << std::endl;
}

WrongCat::~WrongCat ( void )
{
	std::cout << GRAY << "WrongCat type " << this->getType() << " has gone" << DEFAULT << std::endl;
}

WrongCat::WrongCat( const WrongCat &copy )
{
	*this = copy;
}

WrongCat	const &WrongCat::operator=(const WrongCat &copy)
{
	this->setType(copy._type);
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << this->getType() << " : Woem Woem @*!# $# *  %  ~" << std::endl;
}
