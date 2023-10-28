#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", "No target", 72, 45)
{
    std::cout << GRAY << "RobotomyRequestForm has been created with target [" << this->getTarget() << "]" << DEFAULT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", target, 72, 45)
{
    std::cout << GRAY << "RobotomyRequestForm has been created with target [" << target << "]" << DEFAULT << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
    std::cout << GRAY << "RobotomyRequestForm has been deleted with target [" << this->getTarget() << "]" << DEFAULT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &copy ) : AForm(copy)
{
    std::cout << GRAY << "RobotomyRequestForm COPY has been created with target [" << copy.getTarget() << "]" << DEFAULT << std::endl;
}

RobotomyRequestForm   &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    AForm::operator=(copy);
    std::cout << GRAY << "RobotomyRequestForm COPY has been created with target [" << copy.getTarget() << "]" << DEFAULT << std::endl;
    return (*this);
}

bool	RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
    std::srand(std::time(0));
    int random_int = rand();
    std::cout << YELLOW << "bzzzzzz bzzzzzz * Drilligng Noise * bzzzzzz bzzzzzz" << DEFAULT << std::endl;
    if (random_int % 2 == 1)
    {
        std::cout << GREEN << "Execute " << this->getTarget() << " is SUCCESS!" << DEFAULT << std::endl;
    }
    else
    {
        std::cout << RED << "Execute " << this->getTarget() << " is FAILED!" << DEFAULT << std::endl;
    }
    return (true);
}