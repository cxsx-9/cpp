#include "Form.hpp"

Form::Form( void ) : _name("Untitle"), _status(false), _rgrade(150), _rexecute(150)
{
		std::cout << GRAY << "Form [" << this->_name << "] has been created with " << std::endl
		<< "	grade required to signed " << this->_rgrade << std::endl
		<< "	grade required to execute " << this->_rexecute << DEFAULT << std::endl;
}

Form::~Form( void )
{
	std::cout << GRAY << "Form [" << this->_name << "] has been deleted" << DEFAULT << std::endl;
}

Form::Form( std::string name, int grade, int execute ) : _name(name), _status(false), _rgrade(grade), _rexecute(execute)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	else if (execute < 1)
		throw Form::GradeTooHighException();
	else if (execute > 150)
		throw Form::GradeTooLowException();
	std::cout << GRAY << "Form [" << this->_name << "] has been created with " << std::endl
		<< "	grade required to signed " << this->_rgrade << std::endl
		<< "	grade required to execute " << this->_rexecute << DEFAULT << std::endl;
	return ;
}

Form::Form( const Form &copy ) : _status(copy._status), _rgrade(copy._rgrade), _rexecute(copy._rexecute)
{
	const_cast<std::string&>(this->_name) = copy._name + " COPY";
	this->_status = copy._status;
	std::cout << GRAY << "Form [" << this->_name << "] has been created with " << std::endl
	<< "	grade required to signed " << this->_rgrade << std::endl
	<< "	grade required to execute " << this->_rexecute << DEFAULT << std::endl;
}

Form	&Form::operator=(const Form &copy)
{
	const_cast<std::string&>(this->_name) = copy._name + " COPY";
	const_cast<int&>(this->_rgrade) = copy._rgrade;
	const_cast<int&>(this->_rexecute) = copy._rexecute;
	this->_status = copy._status;
	std::cout << GRAY << "Form [" << copy._name << "] has been created with " << std::endl
	<< "	grade required to signed " << copy._rgrade << std::endl
	<< "	grade required to execute " << copy._rexecute << DEFAULT << std::endl;
	return (*this);
}

std::string const Form::getName() const
{
	return (this->_name);
}

bool Form::getStatus() const
{
	return (this->_status);
}

int	Form::getGrade() const
{
	return (this->_rgrade);
}

int	Form::getExecute() const
{
	return (this->_rexecute);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form is grade TOO HIGH.\n");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form is grade TOO LOW.\n");
}

bool Form::beSigned(Bureaucrat const &agent)
{
	if (this->_status)
		std::cout << CYAN << "Form : " << this->getName() << " form is Already signed. " <<agent.getName() <<  " cannot sign this form." << DEFAULT << std::endl;
	else if (agent.getGrade() > this->getGrade())
	{
		std::cout << CYAN << "Form : " << this->getName() << " form is require grade " << this->getGrade() << " or Higher to be sign." << DEFAULT << std::endl;
		throw Form::GradeTooLowException();
	}
	else
	{
		std::cout << CYAN << "Form : " << this->getName() << " form is signed by " << agent.getName() << "." << DEFAULT << std::endl;
		this->_status = true;
		return (true);
	}
	return (false);
}

std::ostream	&operator<<(std::ostream &out, const Form &sheet)
{
	out << "Form [" <<sheet.getName() << "] ";
	if (sheet.getStatus())
		out << GREEN << "has been Signed. [✔]" << DEFAULT << std::endl;
	else
		out << RED << "has Not Signed yet. [ ]" << DEFAULT << std::endl;
	out << "	grade required to signed " << sheet.getGrade() << std::endl;
	out << "	grade required to execute " << sheet.getExecute() << DEFAULT << std::endl;
	return (out);
}
