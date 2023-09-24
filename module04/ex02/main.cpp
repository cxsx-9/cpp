#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void case_1()
{
	Dog puppy;
	Cat kitty;
	std::cout << std::endl;

	std::cout << "Type check : " << puppy.getType() << std::endl;
	puppy.makeSound();
	std::cout << "Brain check : " << std::endl;
	puppy.openTheBrain();
	std::cout << std::endl;

	std::cout << "Type check : " << kitty.getType() << std::endl;
	kitty.makeSound();
	std::cout << "Brain check : " << std::endl;
	kitty.openTheBrain();
	std::cout << std::endl;

	std::cout << std::endl;
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

int main()
{
	std::cout << "\n---------------- case 1 -------------------\n"<< std::endl;
	case_1();
	std::cout << "\n---------------- case 2 -------------------\n"<< std::endl;
	case_2();
	return (0);
}