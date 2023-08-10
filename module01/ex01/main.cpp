#include "Zombie.hpp"

int main( void )
{
	int N = 5;
	std::string name = "Jack";
	Zombie* Horde = Zombie::zombieHorde(N, name);

	for (int i = 0; i < N; i++)
	{
		Horde[i].announce();
	}
	delete[] Horde;

	return 0;
}