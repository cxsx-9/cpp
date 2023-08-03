#include "Phonebook.hpp"

int main(void)
{
	Phonebook	ph;
	std::string	str;

	while (1)
	{
		std::cout << "Input command : ";
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
		if (str == "EXIT")
			break; 
		else if (str == "ADD")
			ph.add();
		else if (str == "SEARCH")
			ph.search();
	}
	return (0);
}