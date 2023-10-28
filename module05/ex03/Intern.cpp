#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern( void )
{
	std::cout << GRAY << "Intern has been created." << DEFAULT << std::endl;
}

Intern::~Intern( void )
{
	std::cout << GRAY << "Intern has been deleted." << DEFAULT << std::endl;
}

Intern::Intern( const Intern &copy )
{
	(void) copy;
}

Intern	&Intern::operator=(const Intern &copy)
{
	(void) copy;
	return (*this);
}

static AForm* createRobotomyForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* createShrubberyForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* createPresidentialForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

const char* Intern::UnknowFormException::what() const throw()
{
	return ("A form name is Not Exist.\n");
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	AForm *form = NULL;

	AForm* (*formCreators[])(const std::string&) = {
		&createShrubberyForm,
		&createRobotomyForm,
		&createPresidentialForm
	};

	const char* formName[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i=0; i<3; i++)
	{
		if (name == formName[i])
		{
			std::cout << CYAN << "Intern create a " << formName[i] << " form." << DEFAULT << std::endl;
			form = (formCreators[i])(target);
			return (form);
		}
	}
	std::cout << CYAN << "Intern can't create [" << name << "] form." << DEFAULT << std::endl;
	throw Intern::UnknowFormException();
	return (form);
}
