#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Unknow"), _level(150)
{
	std::cout << GRAY << "Bureaucrat [" << this->_name << "] has been created with level " << this->_level << DEFAULT << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << GRAY << "Bureaucrat [" << this->_name << "] has been deleted" << DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int level ) : _name(name), _level(level)
{
	if (level < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (level > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GRAY << "Bureaucrat [" << this->_name << "] has been created with level " << this->_level << DEFAULT << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat &copy )
{
	const_cast<std::string&>(this->_name) = copy._name;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	const_cast<std::string&>(this->_name) = copy._name;
	this->_level = copy._level;
	return (*this);
}

std::string const Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_level);
}

void Bureaucrat::incrementGrade(int amount)
{
	if (this->_level - amount < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_level -= amount;
	std::cout << GRAY << this->_name << " was upgraded [" << amount << "] levels." << DEFAULT << std::endl;
}

void Bureaucrat::decrementGrade(int amount)
{
	if (this->_level + amount > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_level += amount;
	std::cout << GRAY << this->_name << " was downgraded [" << amount << "] levels." << DEFAULT << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat is grade TOO HIGH.\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat is grade TOO LOW.\n");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &agent)
{
	out <<  agent.getName() << ", bureaucrat grade " << agent.getGrade() << std::endl;
	return (out);
}

void	Bureaucrat::signForm(AForm &sheet)
{
	try
	{
		if (sheet.beSigned(*this))
			std::cout << CYAN << this->_name << ", Signed " << sheet.getName() << ". ✔✔✔" << DEFAULT << std::endl;
		else
			std::cout << CYAN << this->_name << ", couldn’t sign " << sheet.getName() << " because form is already signed." << DEFAULT << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception (sign the form): " << e.what() << DEFAULT;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		if (form.execute(*this))
			std::cout << CYAN << this->_name << ", executed " << form.getName() << ". ▷▷▷" << DEFAULT << std::endl;
		else
			std::cout << CYAN << this->_name << ", couldn’t execute " << form.getName() << " because form is Not signed yet." << DEFAULT << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception (sign the form): " << e.what() << DEFAULT;
	}
}