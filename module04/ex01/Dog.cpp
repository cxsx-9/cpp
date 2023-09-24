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
	this->_type = copy.getType() + " (copy)";
	this->_brain = new Brain(*(copy.getBrain()));
	std::cout << GRAY << "Dog type " << this->getType() << " has been created! (copy)" << DEFAULT << std::endl;
}

Dog	const &Dog::operator=(const Dog &copy)
{
	this->_type = copy.getType();
	delete this->_brain;
	this->_brain = new Brain(*(copy.getBrain()));
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

Brain	*Dog::getBrain() const
{
	return (this->_brain);
}
