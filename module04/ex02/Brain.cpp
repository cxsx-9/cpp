#include "Brain.hpp"

Brain::Brain ( std::string type )
{
	std::cout << RED << "Brain is growing!" << DEFAULT << std::endl;
	int i;
	int j;

	this->_ideas = new std::string[100];
	for (i = 0; i < 100; i++)
	{
		j = i % 3;
		switch (j)
		{
		case 0:
			this->_ideas[i] = type + " need to Sleep!";
			break;
		case 1:
			this->_ideas[i] = type + " need more Food!";
			break;
		case 2:
			this->_ideas[i] = type + " need to Play!";
			break;
		default:
			break;
		}
	}
}

Brain::~Brain ( void )
{
	delete[] this->_ideas;
	std::cout << RED << "Brain is dissappearing ;-;" << DEFAULT << std::endl;
}

Brain::Brain( const Brain &copy )
{
	int i;
	this->_ideas = new std::string[100];

	for (i = 0; i < 100; i++)
	{
		this->_ideas[i] = copy._ideas[i] + " copy";
	}
	std::cout << RED << "Copy Brain is growing!" << DEFAULT << std::endl;
}

Brain	const &Brain::operator=(const Brain &copy)
{
	this->_ideas = copy._ideas;
	return (*this);
}

std::string	const *Brain::getIdea( void ) const
{
	return (this->_ideas);
}

void	Brain::ExpressTheIdea ( void ) const
{
	int i;
	for (i = 0; i < 10; i++)
	{
		std::cout << this->_ideas[i] << std::endl;
	}
}