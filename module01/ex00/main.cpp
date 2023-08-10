#include "Zombie.hpp"

int main()
{
	Zombie	Zombie1;

	Zombie1.randomChump("Jack"); // stack memory

	Zombie *Zombie2 = Zombie1.newZombie("John"); // heap memory
	Zombie2->announce();
	delete Zombie2;

	return (0);
}