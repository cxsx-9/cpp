#include "Serializer.hpp"

void	displayInformation(Data *cus)
{
	std::cout << GREEN;
	std::cout << "\n-CUSTOMER-" << std::endl;
	std::cout << "id :	" << cus->id << std::endl;
	std::cout << "name :	" << cus->name << std::endl;
	std::cout << DEFAULT;
}

int main()
{
	Data		customer;
	customer.id = 0;
	customer.name = "Fry";

	uintptr_t ptr1 = Serializer::serialize(&customer);
	Data	*dummy = Serializer::deserialize(ptr1);
	
	displayInformation(dummy);
	std::cout << "	:from dummy" << std::endl;
	
	std::cout << YELLOW << "\nChange the value inside Data" << DEFAULT << std::endl;
	
	customer.id = 1;
	displayInformation(&customer);
	std::cout << "	:from customer" << std::endl;
	
	std::cout << YELLOW << "\nChange the value inside Data" << DEFAULT << std::endl;
	
	dummy->name = "Phillip";
	displayInformation(dummy);
	std::cout << "	:from dummy" << std::endl;



	std::cout << std::endl;
	std::cout << "Address of customer :	" << &customer << std::endl;
	std::cout << "Address of dummy :	" << dummy << std::endl;
	std::cout << std::endl;
}