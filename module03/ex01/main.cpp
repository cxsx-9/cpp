#include "ScavTrap.hpp"

void attack_test()
{
	ScavTrap a("Josh");
	
	std::cout << MAGENTA << "Josh try to attack everyone -\"-\n" << DEFAULT << std::endl;

	a.attack("Someone");
	a.attack("A");
	a.attack("B");
	a.attack("C");
	a.attack("D");
	a.attack("E");
	a.attack("F");
	a.attack("G");
	a.attack("H");
	a.attack("I");
	a.attack("J");
	a.attack("K");

	std::cout << MAGENTA << "Josh is bored. Now, he wanna be a  Guard Gate!\n" << DEFAULT << std::endl;

	a.guardGate();

	std::cout << std::endl;
}

void	until_die()
{
	ScavTrap b("Jack");

	std::cout << MAGENTA << "Jack will take a damage and try to repair him self ;-;\n" << DEFAULT << std::endl;
	while(b.getHitPoint())
	{
		b.takeDamage(30);
		b.beRepaired(20);
	}
	std::cout << MAGENTA << "\nNow Jack is already die. Let's Jack try to do something.\n" << DEFAULT << std::endl;
	b.beRepaired(40);
	b.attack("Someone");
	b.takeDamage(50);
	b.guardGate();
	std::cout << std::endl;
}

void	until_ranout()
{
	ScavTrap c("John");

	std::cout << MAGENTA << "John will do something until ranout of energy ;-;\n" << DEFAULT << std::endl;
	while(c.getEnergyPoint())
	{
		c.beRepaired(20);
		c.attack("someone");
	}
	std::cout << MAGENTA << "\nNow John is ranout of energy. Let's John try to do something.\n" << DEFAULT << std::endl;
	c.beRepaired(40);
	c.attack("Someone");
	c.takeDamage(50);
	c.guardGate();
	std::cout << std::endl;
}

void	normal_create()
{
	ScavTrap a("Someone");
}

void	first_meet()
{
	normal_create();
	std::cout << std::endl;
	ScavTrap z;
	std::cout << std::endl;
	ScavTrap b(z);
	std::cout << std::endl;
	ScavTrap c = b;
	std::cout << std::endl;
}

int	main ()
{
	std::cout << MAGENTA << "\n-----------------[case 0]-----------------\n" << DEFAULT << std::endl;
	first_meet();
	std::cout << MAGENTA << "\n-----------------[case 1]-----------------\n" << DEFAULT << std::endl;
	attack_test();
	std::cout << MAGENTA << "\n-----------------[case 2]-----------------\n" << DEFAULT << std::endl;
	until_ranout();
	std::cout << MAGENTA << "\n-----------------[case 3]-----------------\n" << DEFAULT << std::endl;
	until_die();

	return (0);
}
