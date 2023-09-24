#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void case_1()
{
	const Animal* neutral = new Animal();
	const Animal* puppy = new Dog();
	const Animal* kitty = new Cat();

	std::cout << std::endl;

	const WrongAnimal* alien = new WrongAnimal();
	const WrongCat* alienCat = new WrongCat();

	std::cout << std::endl;

	std::cout << "Type check : " << neutral->getType() << std::endl;
	std::cout << "Type check : " << puppy->getType() << std::endl;
	std::cout << "Type check : " << kitty->getType() << std::endl;
	
	std::cout << std::endl;

	std::cout << "Type check : " << alien->getType() << std::endl;
	std::cout << "Type check : " << alienCat->getType() << std::endl;

	std::cout << std::endl;

	neutral->makeSound();
	puppy->makeSound();
	kitty->makeSound();

	std::cout << std::endl;

	alien->makeSound();
	alienCat->makeSound();
	
	std::cout << std::endl;

	delete neutral;
	delete puppy;
	delete kitty;

	std::cout << std::endl;

	delete alien;
	delete alienCat;
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
	std::cout << std::endl;

	Cat &luna_ref = luna;
	Cat luna_kitty(luna_ref);

	std::cout << "Type check : " << luna_kitty.getType() << std::endl;
	luna_kitty.makeSound();
	std::cout << std::endl;
}

int main()
{
	std::cout << "\n---------------- case 1 -------------------\n"<< std::endl;
	case_1();
	std::cout << "\n---------------- case 2 -------------------\n"<< std::endl;
	case_2();

	return (0);
}