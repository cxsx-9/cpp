#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const AAnimal* puppy = new Dog();
	std::cout << std::endl;
	const AAnimal* kitty = new Cat();
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

	delete puppy;
	std::cout << std::endl;
	delete kitty;
	std::cout << std::endl;

	return (0);
}