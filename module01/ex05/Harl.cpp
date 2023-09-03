#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << MAGENTA << "DEBUG	: " << DEFAULT;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info ( void )
{
	std::cout << GRAY << "INFO	: " << DEFAULT;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << YELLOW << "WARING	: " << DEFAULT;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << RED << "ERROR	: " << DEFAULT;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/*

The goal of this exercise is to use pointers to member functions. This is not a
suggestion. Harl has to complain without using a forest of if/else if/else. It doesn’t think
twice!

*/

void Harl::complain( std::string level)
{
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*ptr[i])();
			break;
		}
	}
}