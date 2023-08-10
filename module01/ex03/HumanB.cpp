#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
    this->name_ = name;
}

void HumanB::attack( void )
{
    std::cout << this->name_ << " attacks with their " << this->weapon_->getType() << std::endl;
}

void HumanB::setWeapon( Weapon &weapon )
{
    this->weapon_ = &weapon;
}