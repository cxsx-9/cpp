#include "Cat.hpp"

Cat::Cat ( void )
{
	this->setType("Cat");
	this->_brain = new Brain(this->_type);
	std::cout << GRAY << "Cat type " << this->getType() << " has been created!" << DEFAULT << std::endl;
}

Cat::~Cat ( void )
{
	delete this->_brain;
	std::cout << GRAY << "Cat type " << this->getType() << " has gone" << DEFAULT << std::endl;
}

Cat::Cat( const Cat &copy )
{
	*this = copy;
	this->_brain = new std::string(*copy.getBrain());
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

void	Cat::openTheBrain() const
{
	this->_brain->ExpressTheIdea();
}

Brain*	Cat::getBrain() const
{
	return (this->_brain);
}

