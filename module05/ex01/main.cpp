#include "Bureaucrat.hpp"
#include "Form.hpp"

void test0()
{
	std::cout << MAGENTA << "\n---- TEST 0 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Normal assign" << DEFAULT << std::endl;
	Form sheet0;
	Form sheet1("A", 75, 50);
	Form sheet2(sheet0);
	Form sheet3 = sheet1;
	std::cout << sheet0;
	std::cout << sheet1;
	std::cout << sheet2;
	std::cout << sheet3;
}

void test1()
{
	std::cout << MAGENTA << "\n---- TEST 1 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : out of range assign" << DEFAULT << std::endl;
	try
	{
		Form sheet1("MoreFood", 0, 50);
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT;
	}

	try
	{
		Form sheet1("MoreFood", 151, 50);
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT;
	}

	try
	{
		Form sheet1("MoreFood", 50, 0);
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT;
	}

	try
	{
		Form sheet1("MoreFood", 50, 151);
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception : " << e.what() << DEFAULT;
	}
}

void test2()
{
	std::cout << MAGENTA << "\n---- TEST 2 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Normal sign Form" << DEFAULT << std::endl;

	Bureaucrat	agent("Antony", 10);
	Form		sheet("TopSecret", 30, 25);

	std::cout << agent;
	std::cout << sheet;
	agent.signForm(sheet);
	std::cout << sheet;
}

void test3()
{
	std::cout << MAGENTA << "\n---- TEST 3 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Lower grade sign Form" << DEFAULT << std::endl;

	Bureaucrat	agent("Antony", 50);
	Form		sheet("TopSecret", 30, 25);

	agent.signForm(sheet);
}

void test4()
{
	std::cout << MAGENTA << "\n---- TEST 4 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Multiple case" << DEFAULT << std::endl;

	Bureaucrat	agent1("Antony", 50);
	Bureaucrat	agent2("Angela", 1);
	Form		sheet1("BasicForm", 150, 25);
	Form		sheet2("TopSecret", 30, 25);

	std::cout << YELLOW << "\n--- " << agent1.getName() << " already signed " << sheet2.getName() << " form, but " << agent2.getName() << "want to sign too. ---" << DEFAULT << std::endl;
	std::cout << YELLOW<< "Status :" << DEFAULT << std::endl;
	std::cout << sheet1;
	std::cout << YELLOW<< agent1.getName() << " try to sign the form." << DEFAULT << std::endl;
	agent1.signForm(sheet1);
	std::cout << YELLOW<< "Status :" << DEFAULT << std::endl;
	std::cout << sheet1;
	std::cout << YELLOW<< agent1.getName() << " try to sign the form." << DEFAULT << std::endl;
	agent2.signForm(sheet1);

	std::cout << YELLOW << "\n--- " << agent1.getName() << " want to sign a " << sheet2.getName() << "form so much! ---" << DEFAULT << std::endl;
	std::cout << YELLOW<< "Status :" << DEFAULT << std::endl;
	std::cout << sheet2;
	std::cout << agent1;
	std::cout << YELLOW<< "Let's try to sign the form." << DEFAULT << std::endl;
	agent1.signForm(sheet2);
	std::cout << YELLOW<< "So he worked hard and harder to know the Top secret information." << DEFAULT << std::endl;
	agent1.incrementGrade(30);
	std::cout << agent1;
	std::cout << YELLOW<< "Let's try to sign the form." << DEFAULT << std::endl;
	agent1.signForm(sheet2);
	std::cout << YELLOW<< "Status :" << DEFAULT << std::endl;
	std::cout << sheet2 << std::endl;
}

void test5()
{
	std::cout << MAGENTA << "\n---- TEST 5 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Copy form" << DEFAULT << std::endl;
	Bureaucrat	agent1("Admin", 1);
	Form		sheet1("Rocket", 50, 50);
	Form		sheet2(sheet1);
	std::cout << std::endl;
	std::cout << sheet1;
	std::cout << sheet2;
	std::cout << std::endl;
	agent1.signForm(sheet1);
	agent1.signForm(sheet2);
	std::cout << std::endl;
	std::cout << sheet1;
	std::cout << sheet2;
}

int main()
{
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
}