#include "ClapTrap.hpp"

void until_ranout()
{
	ClapTrap a("Jonh");
	
	std::cout << MAGENTA << "John will do something until ranout of energy ;-;\n" << DEFAULT << std::endl;

	while(a.getEnergyPoint())
	{
		a.attack("Someone");
		a.beRepaired(5);
	}

	std::cout << MAGENTA << "\nNow John is ranout of energy. Let's John try to do something.\n" << DEFAULT << std::endl;
	a.takeDamage(15);
	a.beRepaired(2);
	a.attack("H");

	std::cout << std::endl;
}

void	take_damage_and_recover()
{
	ClapTrap b("Jack");

	std::cout << MAGENTA << "Jack will take a damage and try to repair him self ;-;\n" << DEFAULT << std::endl;
	
	while (b.getHitPoint())
	{
		b.takeDamage(3);
		b.beRepaired(2);
	}

	std::cout << MAGENTA << "\nNow Jack is already die. Let's Jack try to do something.\n" << DEFAULT << std::endl;
	b.beRepaired(2);
	b.takeDamage(2);
	b.attack("Someone");
	std::cout << std::endl;
}

void	first_meet()
{
	ClapTrap z;
	ClapTrap a("Someone");
	ClapTrap b(a);
	ClapTrap c = a;
}

int	main ()
{
	std::cout << MAGENTA << "\n-----------------[case 0]-----------------\n" << DEFAULT << std::endl;
	first_meet();
	std::cout << MAGENTA << "\n-----------------[case 1]-----------------\n" << DEFAULT << std::endl;
	until_ranout();
	std::cout << MAGENTA << "\n-----------------[case 2]-----------------\n" << DEFAULT << std::endl;
	take_damage_and_recover();

	return (0);
}
