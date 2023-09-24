#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void case_1()
{
	const Animal* neutral = new Animal();
	std::cout << std::endl;
	const Animal* puppy = new Dog();
	std::cout << std::endl;
	const Animal* kitty = new Cat();
	std::cout << std::endl;

	std::cout << "Type check : " << neutral->getType() << std::endl;
	neutral->makeSound();
	std::cout << "Brain check : " << std::endl;
	neutral->openTheBrain();
	std::cout << std::endl;

	std::cout << "Type check : " << puppy->getType() << std::endl;
	puppy->makeSound();
	std::cout << "Brain check : " << std::endl;
	puppy->openTheBrain();
	std::cout << std::endl;

	std::cout << "Type check : " << kitty->getType() << std::endl;
	kitty->makeSound();
	std::cout << "Brain check : " << std::endl;
	kitty->openTheBrain();
	std::cout << std::endl;
	
	delete neutral;
	std::cout << std::endl;
	delete puppy;
	std::cout << std::endl;
	delete kitty;
	std::cout << std::endl;
}

void case_2()
{
	Cat luna;
	Dog sunny;

	std::cout << "Type check : " << luna.getType() << std::endl;
	luna.makeSound();
	std::cout << std::endl;

	std::cout << "Type check : " << sunny.getType() << std::endl;
	sunny.makeSound();
	std::cout << std::endl;

	std::cout << MAGENTA << "Try to copy the DOG" << DEFAULT << std::endl;

	Dog &sunny_ref = sunny;
	Dog sunny_puppy(sunny_ref);

	std::cout << "Type check : " << sunny_puppy.getType() << std::endl;
	sunny_puppy.makeSound();
	std::cout << "Brain check : " << std::endl;
	sunny_puppy.openTheBrain();
	std::cout << std::endl;

	Cat &luna_ref = luna;
	Cat luna_kitty(luna_ref);

	std::cout << "Type check : " << luna_kitty.getType() << std::endl;
	luna_kitty.makeSound();
	std::cout << "Brain check : " << std::endl;
	luna_kitty.openTheBrain();
	std::cout << std::endl;
}

void case_3()
{
	std::cout << MAGENTA << "Create Array of Animal! Half Dog and Half Cat" << DEFAULT << std::endl;
	Animal* (neutral[4]);
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			neutral[i] = new Cat;
		else
			neutral[i] = new Dog;
	}
	std::cout << MAGENTA << "Type check : "  << DEFAULT <<  std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << neutral[i]->getType() << std::endl;
	}

	std::cout << MAGENTA << "delete" << DEFAULT << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete neutral[i];
	}
}

int main()
{
	std::cout << "\n---------------- case 1 -------------------\n"<< std::endl;
	case_1();
	std::cout << "\n---------------- case 2 -------------------\n"<< std::endl;
	case_2();
	std::cout << "\n---------------- case 3 -------------------\n"<< std::endl;
	case_3();

	return (0);
}