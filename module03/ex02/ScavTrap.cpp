#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ): ClapTrap()
{
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	std::cout << GRAY << "ScavTrap [" << this->_name << "] was created." << DEFAULT << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap( name )
{
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	std::cout << GRAY << "ScavTrap [" << this->_name << "] was created." << DEFAULT << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &copy ): ClapTrap( copy )
{
	std::cout << GRAY << "ScavTrap [" << this->_name << "] was copied." << DEFAULT << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << GRAY << "ScavTrap [" << this->_name << "] has been laid off." << DEFAULT << std::endl;
}

ScavTrap   &ScavTrap::operator=(const ScavTrap &copy)
{
	this->_name = copy._name;
	this->_hit_point = copy._hit_point;
	this->_energy_point = copy._energy_point;
	this->_attack_damage = copy._attack_damage;
	std::cout << YELLOW << "ScavTrap [" << this->_name << "] was assign by operator." << DEFAULT << std::endl;
	return (*this);
}

void ScavTrap::guardGate()
{
	if (this->_hit_point)
		std::cout << "ScavTrap [" << this->_name << "] switch to GATE KEEPER mode!" << std::endl; 
	else
	{
		std::cout << "ScavTrap wanna be a Guard Gate?	";
		std::cout << "[" << this->_name << "] is already died. ;-;" << std::endl;
	}
}