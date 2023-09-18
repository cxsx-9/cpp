#include "Brain.hpp"

Brain::Brain ( std::string type )
{
	std::cout << RED << "Brain is growing!" << DEFAULT << std::endl;
	int i;
	int j;
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
	std::cout << RED << "Brain is dissappearing ;-;" << DEFAULT << std::endl;
}

void	Brain::ExpressTheIdea ( void ) const
{
	int i;
	for (i = 0; i < 10; i++)
	{
		std::cout << this->_ideas[i] << std::endl;
	}
}