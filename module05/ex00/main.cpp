#include "Bureaucrat.hpp"

void test_0()
{
	std::cout << MAGENTA << "\n---- TEST 0 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Normal assign" << DEFAULT << std::endl;
	Bureaucrat agent_1("Smith", 1);
	std::cout << agent_1;
	Bureaucrat agent_2("Adam", 150);
	std::cout << agent_2;
}

void test_1()
{
	std::cout << MAGENTA << "\n---- TEST 1 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : out of range assign" << DEFAULT << std::endl;
	
	try
	{
		Bureaucrat agent_1("Smith", 0);
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT << std::endl;
	}

	try
	{
		Bureaucrat agent_1("Adam", 151);
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT << std::endl;
	}
}

void test_2()
{
	std::cout << MAGENTA << "\n---- TEST 2 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Normal increment and decrement" << DEFAULT << std::endl;
	Bureaucrat agent_1("Smith", 1);
	std::cout << agent_1;
	agent_1.decrementGrade(9);
	std::cout << agent_1;
	Bureaucrat agent_2("Adam", 150);
	std::cout << agent_2;
	agent_2.incrementGrade(10);
	std::cout << agent_2;
}

void test_3()
{
	std::cout << MAGENTA << "\n---- TEST 3 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : out of range by increment and decrement" << DEFAULT << std::endl;
	
	try
	{
		Bureaucrat agent_1("Smith", 2);
		agent_1.incrementGrade(9);
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT << std::endl;
	}

	try
	{
		Bureaucrat agent_1("Adam", 148);
		agent_1.decrementGrade(9);
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT << std::endl;
	}
}
int main()
{
	test_0();
	test_1();
	test_2();
	test_3();
}