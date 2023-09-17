#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* neutral = new Animal();
	const Animal* puppy = new Dog();
	const Animal* kitty = new Cat();

	std::cout << "Type check : " << neutral->getType() << std::endl;
	std::cout << "Type check : " << puppy->getType() << std::endl;
	std::cout << "Type check : " << kitty->getType() << std::endl;

	neutral->makeSound();
	puppy->makeSound();
	kitty->makeSound();
	
	delete neutral;
	delete puppy;
	delete kitty;

	return (0);
}