#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : weapon_(weapon) // constructor
{
    this->name_ = name;
}

void HumanA::attack( void )
{
    std::cout << this->name_ << " attacks with their " << this->weapon_.getType() << std::endl;
}

void HumanA::setWeapon( Weapon weapon )
{
    this->weapon_ = weapon;
}