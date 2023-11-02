#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void test0()
{
	std::cout << MAGENTA << "\n---- TEST 0 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Create Form by Intern [ShrubberyCreationForm] [145:137]" << DEFAULT << std::endl;
	try
	{
		Bureaucrat	agent("Leela", 145);
		Bureaucrat	executer("Zoidberg", 137);
		Intern		Newbie;
		AForm		*sheet = Newbie.makeForm("shrubbery creation", "Earth");

		agent.signForm(*sheet);
		executer.executeForm(*sheet);
		delete sheet;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT;
	}
}

void test1()
{
	std::cout << MAGENTA << "\n---- TEST 1 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Create Form by Intern [RobotomyRequestForm] [72:45]" << DEFAULT << std::endl;
	try
	{
		Bureaucrat	agent("Phillip", 72);
		Bureaucrat	executer("Leela", 45);
		Intern		Newbie;
		AForm		*sheet = Newbie.makeForm("robotomy request", "Bender");

		agent.signForm(*sheet);
		executer.executeForm(*sheet);
		delete sheet;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT;
	}
}

void test2()
{
	std::cout << MAGENTA << "\n---- TEST 2 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Create Form by Intern [PresidentialPardonForm] [25:5]" << DEFAULT << std::endl;
	try
	{
		Bureaucrat	agent("Phillip", 25);
		Bureaucrat	executer("Leela", 5);
		Intern		Newbie;
		AForm		*sheet = Newbie.makeForm("presidential pardon", "Dr.Farnsworth");

		agent.signForm(*sheet);
		executer.executeForm(*sheet);
		delete sheet;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT;
	}
}

void test3()
{
	std::cout << MAGENTA << "\n---- TEST 3 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Create Form by Intern [Unknow]" << DEFAULT << std::endl;
	try
	{
		Bureaucrat	agent("Leela", 1);
		Bureaucrat	executer("Zoidberg", 1);
		Intern		Newbie;
		AForm		*sheet = Newbie.makeForm("Unknow", "Home");

		agent.signForm(*sheet);
		executer.executeForm(*sheet);
		delete sheet;
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