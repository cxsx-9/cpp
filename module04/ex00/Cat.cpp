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

Cat::Cat( const Cat &copy )
{
	this->_type = copy.getType() + " (copy)";
	std::cout << GRAY << "Cat type " << this->getType() << " has been created! (copy)" << DEFAULT << std::endl;
}

Cat	const &Cat::operator=(const Cat &copy)
{
	this->setType(copy._type);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << this->getType() << " : Meow Meow ~" << std::endl;
}
