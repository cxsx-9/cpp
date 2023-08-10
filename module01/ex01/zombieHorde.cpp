#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde( int N, std::string name )
{
	Zombie* ZombieH = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		ZombieH[i].name = name;
	}
    return ZombieH;
}