#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
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

	return (0);
}