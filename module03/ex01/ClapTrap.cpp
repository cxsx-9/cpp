#include "ClapTrap.hpp"

// instruction / destruction
ClapTrap::ClapTrap( void ):_name("Unknow"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << YELLOW << "CrapTrap [" << this->_name << "] was created." << DEFAULT << std::endl;
}

ClapTrap::ClapTrap( std::string name ): _hit_point(10), _energy_point(10), _attack_damage(0)
{
	this->_name = name;
	std::cout << YELLOW << "CrapTrap [" << this->_name << "] was created." << DEFAULT << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &copy ):_name(copy._name), _hit_point(copy._hit_point), _energy_point(copy._energy_point), _attack_damage(copy._attack_damage)
{
	std::cout << YELLOW << "CrapTrap [" << this->_name << "] was copied." << DEFAULT << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << YELLOW << "CrapTrap [" << this->_name << "] has been laid off." << DEFAULT << std::endl;
}

// getter
std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}

int	ClapTrap::getHitPoint( void ) const
{
	return (this->_hit_point);
}

int	ClapTrap::getEnergyPoint( void ) const
{
	return (this->_energy_point);
}

int	ClapTrap::getAttackDamage( void ) const
{
	return (this->_attack_damage);
}

// setter
void	ClapTrap::setName( std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHitPoint( int hit_point)
{
	this->_hit_point = hit_point;
}

void	ClapTrap::setEnergyPoint( int energy_point)
{
	this->_energy_point = energy_point;
}

void	ClapTrap::setAttackDamage( int attack_damage )
{
	this->_attack_damage = attack_damage;
}

// subject require
void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_point && this->_hit_point)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_point--;
	}
	else if (!this->_energy_point)
	{
		std::cout << "CrapTrap Attack?		";
		std::cout << "Ran out of energy, [" << this->_name << "] can't do anything. ;-;" << std::endl;
	}
	else
	{
		std::cout << "CrapTrap Attack?		";
		std::cout << "[" << this->_name << "] is already died. ;-;" << std::endl;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int hp = this->getHitPoint();
	int total = hp - (int) amount;

	if (total < 0)
		total = 0;

	if (hp)
	{
		std::cout << "ClapTrap " << this->_name << " take a damage " << amount;
		this->setHitPoint(total);
		std::cout << " points of damage!" << " HP total : " << total;
		if (!total)
			std::cout << " [" << this->_name << "] died. ;-;";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "CrapTrap Take Damage?		";
		std::cout << "[" << this->_name << "] is already died. ;-;" << std::endl;
	}

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_point && this->_hit_point)
	{
		std::cout << "ClapTrap " << this->_name << " Repairing " << amount << " points.";
		this->_energy_point--;
		this->setHitPoint(this->_hit_point + (int) amount);
		std::cout << " HP total : " << this->getHitPoint() << std::endl;
	}
	else if (!this->_energy_point)
	{
		std::cout << "CrapTrap Repair?		";
		std::cout << "Ran out of energy, [" << this->_name << "] can't do anything. ;-;" << std::endl;
	}
	else
	{
		std::cout << "CrapTrap Repair?		";
		std::cout << "[" << this->_name << "] is already died. ;-;" << std::endl;
	}
	return ;
}