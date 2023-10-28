#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", "No target", 25, 5)
{
    std::cout << GRAY << "PresidentialPardonForm has been created with target [" << this->getTarget() << "]" << DEFAULT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", target, 25, 5)
{
    std::cout << GRAY << "PresidentialPardonForm has been created with target [" << target << "]" << DEFAULT << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
    std::cout << GRAY << "PresidentialPardonForm has been deleted with target [" << this->getTarget() << "]" << DEFAULT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &copy ) : AForm(copy)
{
    std::cout << GRAY << "PresidentialPardonForm COPY has been created with target [" << copy.getTarget() << "]" << DEFAULT << std::endl;
}

PresidentialPardonForm   &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    AForm::operator=(copy);
    std::cout << GRAY << "PresidentialPardonForm COPY has been created with target [" << copy.getTarget() << "]" << DEFAULT << std::endl;
    return (*this);
}

bool	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getStatus())
	{
		std::cout << CYAN << "Form : " << this->getName() << " form is Not signed yet. " <<executor.getName() <<  " cannot execute this form." << DEFAULT << std::endl;
		return (false);
	}
	else if (executor.getGrade() > this->getExecute())
	{
		std::cout << CYAN << "Form : " << this->getName() << " form is require grade " << this->getExecute() << " or Higher to be execute." << DEFAULT << std::endl;
		throw AForm::GradeTooLowException();
	}
	std::cout << CYAN << "Form : " << this->getName() << " form is executed by " << executor.getName() << "." << DEFAULT << std::endl;
	std::cout << GREEN << "[" << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.]" << DEFAULT << std::endl;
	return (true);
}