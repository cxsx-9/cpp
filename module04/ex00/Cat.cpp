#include "Cat.hpp"

Cat::Cat ( void )
{
	this->setType("Cat");
	std::cout << GRAY << "Cat type " << this->getType() << " has been created!" << DEFAULT << std::endl;
}

Cat::~Cat ( void )
{
	std::cout << GRAY << "Cat type " << this->getType() << " has gone" << DEFAULT << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << this->getType() << " : Meow Meow ~" << std::endl;
}
