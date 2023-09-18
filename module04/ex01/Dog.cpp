#include "Dog.hpp"

Dog::Dog ( void )
{
	this->setType("Dog");
	this->_brain = new Brain(this->_type);
	std::cout << GRAY << "Dog type " << this->getType() << " has been created!" << DEFAULT << std::endl;
}

Dog::~Dog ( void )
{
	delete this->_brain;
	std::cout << GRAY << "Dog type " << this->getType() << " has gone" << DEFAULT << std::endl;
}

Dog::Dog( const Dog &copy )
{
	*this = copy;
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

void	Dog::openTheBrain() const
{
	this->_brain->ExpressTheIdea();
}
