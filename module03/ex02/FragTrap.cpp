#include "FragTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap()
{
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
	std::cout << RED << "FragTrap [" << this->_name << "] was created." << DEFAULT << std::endl;
}

FragTrap::FragTrap( std::string name ): ClapTrap( name )
{
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
	std::cout << RED << "FragTrap [" << this->_name << "] was created." << DEFAULT << std::endl;
}

FragTrap::FragTrap( const FragTrap &copy ): ClapTrap( copy )
{
	std::cout << RED << "FragTrap [" << this->_name << "] was copied." << DEFAULT << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << RED << "FragTrap [" << this->_name << "] has been laid off." << DEFAULT << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	if (this->_hit_point)
		std::cout << "FragTrap [" << this->_name << "] Let's high five !!" << std::endl;
	else
	{
		std::cout << "FragTrap wanna high fives guys?	";
		std::cout << "[" << this->_name << "] is already died. ;-;" << std::endl;
	}
}

// Name, which is passed as parameter to a constructor 
// Hit points (100), represent the health of the ClapTrap 
// Energy points (100)
// Attack damage (30)
