#include "Zombie.hpp"

void Zombie::randomChump( std::string name)
{
    Zombie  NewZombie;

    NewZombie.name = name;
    NewZombie.announce();
}