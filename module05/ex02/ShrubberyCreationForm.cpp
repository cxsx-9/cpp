#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", "No target", 145, 137)
{
    std::cout << GRAY << "ShrubberyCreationForm has been created with target [" << this->getTarget() << "]" << DEFAULT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", target, 145, 137)
{
    std::cout << GRAY << "ShrubberyCreationForm has been created with target [" << target << "]" << DEFAULT << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
    std::cout << GRAY << "ShrubberyCreationForm has been deleted with target [" << this->getTarget() << "]" << DEFAULT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &copy ) : AForm(copy)
{
    std::cout << GRAY << "ShrubberyCreationForm COPY has been created with target [" << copy.getTarget() << "]" << DEFAULT << std::endl;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    AForm::operator=(copy);
    std::cout << GRAY << "ShrubberyCreationForm COPY has been created with target [" << copy.getTarget() << "]" << DEFAULT << std::endl;
    return (*this);
}

bool	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
	std::string filename = this->getTarget() + "_target.txt";
	std::ofstream   outfile(filename);
	if (!outfile.is_open())
	{
		std::cout << "Can't open the outfile." <<std::endl;
		return (false);
	} 
	outfile << std::endl;
	outfile <<	"                   * *    " << std::endl;
	outfile <<	"               *    *  *" << std::endl;
	outfile <<	"             *  *    *     *  *" << std::endl;
	outfile <<	"            *     *    *  *    *" << std::endl;
	outfile <<	"         * *   *    *    *    *   *" << std::endl;
	outfile <<	"         *     *  *    * * .#  *   *" << std::endl;
	outfile <<	"         *   *     * #.  .# *   *" << std::endl;
	outfile <<	"          *     '#.  #: #' * *    *" << std::endl;
	outfile <<	"         *   * * '#. ##''       *" << std::endl;
	outfile <<	"           *        '###" << std::endl;
	outfile <<	"                     ;##" << std::endl;
	outfile <<	"                     ##." << std::endl;
	outfile <<	"                     .##:" << std::endl;
	outfile <<	"                     :###" << std::endl;
	outfile <<	"                     ;###    |\\__/,|   " << std::endl;
	outfile <<	"                    ,####. _.|o o  |_  " << std::endl;
	outfile <<	"         /\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\ (`\\" << std::endl;
	outfile <<	"         |     The Tree of life     |  ) )" << std::endl;
	outfile <<  "         +  Executed by   -"<< executor.getName() << "-"<< std::endl;
	outfile <<	"         ----------------------------" << std::endl;
	outfile.close();
	return (true);
}
