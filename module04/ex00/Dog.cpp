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

void	Dog::makeSound() const
{
	std::cout << this->getType() << " : Woof Woof !" << std::endl;
}
