#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test0()
{
	std::cout << MAGENTA << "\n---- TEST 0 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Sign and Execute [ShrubberyCreationForm] [145:137]" << DEFAULT << std::endl;
	try
	{
		Bureaucrat	agent("Leela", 145);
		Bureaucrat	executer("Zoidberg", 137);
		ShrubberyCreationForm sheet("Earth");
		executer.executeForm(sheet);
		std::cout << sheet;
		std::cout << agent;
		agent.signForm(sheet);
		std::cout << sheet;
		std::cout << executer;
		executer.executeForm(sheet);
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT;
	}
}

void test1()
{
	std::cout << MAGENTA << "\n---- TEST 1 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Sign and Execute [RobotomyRequestForm] [72:45]" << DEFAULT << std::endl;
	try
	{
		Bureaucrat	agent("Leela", 72);
		Bureaucrat	executer("Bender", 45);
		RobotomyRequestForm sheet("CAT");
		std::cout << agent;
		std::cout << sheet;
		agent.signForm(sheet);
		std::cout << executer;
		std::cout << sheet;
		executer.executeForm(sheet);
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT;
	}
}

void test2()
{
	std::cout << MAGENTA << "\n---- TEST 2 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Sign and Execute [PresidentialPardonForm] [25:5]" << DEFAULT << std::endl;
	try
	{
		Bureaucrat	agent("Arthur", 25);
		Bureaucrat	executer("Marvin", 5);
		PresidentialPardonForm sheet("Earth");
		std::cout << agent;
		std::cout << sheet;
		agent.signForm(sheet);
		std::cout << executer;
		std::cout << sheet;
		executer.executeForm(sheet);
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT;
	}
}

void test3()
{
	std::cout << MAGENTA << "\n---- TEST 3 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Sign and Execute [MIX]" << DEFAULT << std::endl;
	try
	{
		Bureaucrat	agent("Arthur", 25);
		Bureaucrat	executer("Marvin", 5);
		ShrubberyCreationForm sheet1("SUN");
		RobotomyRequestForm sheet2("MOON");
		PresidentialPardonForm sheet3("EARTH");
		std::cout << agent;
		agent.signForm(sheet1);
		agent.signForm(sheet2);
		agent.signForm(sheet3);
	
		std::cout << YELLOW << "\nCheck Forms information." << DEFAULT << std::endl;

		std::cout << sheet1;
		std::cout << sheet2;
		std::cout << sheet3;
	
		std::cout << std::endl;
		executer.executeForm(sheet1);
		std::cout << std::endl;
		executer.executeForm(sheet2);
		std::cout << std::endl;
		executer.executeForm(sheet3);
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT;
	}
}

int main()
{
	test0();
	test1();
	test2();
	test3();
}