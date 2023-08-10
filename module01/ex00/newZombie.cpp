#include "Zombie.hpp"

Zombie* Zombie::newZombie( std::string name )
{
    Zombie  *NewZombie = new Zombie;

    NewZombie->name = name;
    return NewZombie;
}