#include "Dog.hpp"

Dog::Dog ( void )
{
	this->setType("Dog");
	std::cout << GRAY << "Dog type " << this->getType() << " has been created!" << DEFAULT << std::endl;
}

Dog::~Dog ( void )
{
	std::cout << GRAY << "Dog type " << this->getType() << " has gone" << DEFAULT << std::endl;
}

Dog::Dog( const Dog &copy )
{
	this->_type = copy.getType() + " (copy)";
	std::cout << GRAY << "Dog type " << this->getType() << " has been created! (copy)" << DEFAULT << std::endl;
}

Dog	const &Dog::operator=(const Dog &copy)
{
	this->setType(copy._type);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << this->getType() << " : Woof Woof !" << std::endl;
}
