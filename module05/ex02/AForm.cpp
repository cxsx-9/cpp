#include "AForm.hpp"

AForm::AForm( void ) : _name("Untitle"), _status(false), _rgrade(150), _rexecute(150)
{
		std::cout << GRAY << "Form [" << this->_name << "] has been created with " << std::endl
		<< "	grade required to signed " << this->_rgrade << std::endl
		<< "	grade required to execute " << this->_rexecute << std::endl
		<< "	target [" << this->_target << "]" << DEFAULT << std::endl;
}

AForm::~AForm( void )
{
	std::cout << GRAY << "Form [" << this->_name << "] has been deleted" << DEFAULT << std::endl;
}

AForm::AForm( std::string name, std::string target, int grade, int execute ) : _name(name), _target(target), _status(false), _rgrade(grade), _rexecute(execute)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
	else if (execute < 1)
		throw AForm::GradeTooHighException();
	else if (execute > 150)
		throw AForm::GradeTooLowException();
	std::cout << GRAY << "Form [" << this->_name << "] has been created with " << std::endl
		<< "	grade required to signed " << this->_rgrade << std::endl
		<< "	grade required to execute " << this->_rexecute << std::endl
		<< "	target [" << this->_target << "]" << DEFAULT << std::endl;
	return ;
}

AForm::AForm( const AForm &copy ) : _status(copy._status), _rgrade(copy._rgrade), _rexecute(copy._rexecute)
{
	const_cast<std::string&>(this->_name) = copy._name + " COPY";
	const_cast<std::string&>(this->_target) = copy._target;
	this->_status = copy._status;
	std::cout << GRAY << "Form [" << this->_name << "] has been created with " << std::endl
	<< "	grade required to signed " << this->_rgrade << std::endl
	<< "	grade required to execute " << this->_rexecute << std::endl
	<< "	target [" << this->_target << "]" << DEFAULT << std::endl;
}

AForm	&AForm::operator=(const AForm &copy)
{
	const_cast<std::string&>(this->_name) = copy._name + " COPY";
	const_cast<std::string&>(this->_target) = copy._target;
	const_cast<int&>(this->_rgrade) = copy._rgrade;
	const_cast<int&>(this->_rexecute) = copy._rexecute;
	this->_status = copy._status;
	std::cout << GRAY << "Form [" << copy._name << "] has been created with " << std::endl
	<< "	grade required to signed " << copy._rgrade << std::endl
	<< "	grade required to execute " << this->_rexecute << std::endl
	<< "	target [" << this->_target << "]" << DEFAULT << std::endl;
	return (*this);
}

std::string	const AForm::getName() const
{
	return (this->_name);
}

std::string	const AForm::getTarget() const
{
	return (this->_target);
}

bool AForm::getStatus() const
{
	return (this->_status);
}

int	AForm::getGrade() const
{
	return (this->_rgrade);
}

int	AForm::getExecute() const
{
	return (this->_rexecute);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form is grade TOO HIGH.\n");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form is grade TOO LOW.\n");
}

bool AForm::beSigned(Bureaucrat const &agent)
{
	if (this->_status)
		std::cout << CYAN << "Form : " << this->getName() << " form is Already signed. " <<agent.getName() <<  " cannot sign this form." << DEFAULT << std::endl;
	else if (agent.getGrade() > this->getGrade())
	{
		std::cout << CYAN << "Form : " << this->getName() << " form is require grade " << this->getGrade() << " or Higher to be sign." << DEFAULT << std::endl;
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::cout << CYAN << "Form : " << this->getName() << " form is signed by " << agent.getName() << "." << DEFAULT << std::endl;
		this->_status = true;
		return (true);
	}
	return (false);
}

std::ostream	&operator<<(std::ostream &out, const AForm &sheet)
{
	out << "Form [" <<sheet.getName() << "] ";
	if (sheet.getStatus())
		out << GREEN << "has been Signed. [✔]" << DEFAULT << std::endl;
	else
		out << RED << "has Not Signed yet. [ ]" << DEFAULT << std::endl;
	out << "	grade required to signed " << sheet.getGrade() << std::endl;
	out << "	grade required to execute " << sheet.getExecute() << std::endl;
	out	<< "	target [" << sheet.getTarget() << "]" << DEFAULT << std::endl;
	return (out);
}
