#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm( void );
        RobotomyRequestForm( std::string target );
        ~RobotomyRequestForm( void );
        RobotomyRequestForm( const RobotomyRequestForm &copy );
        RobotomyRequestForm   &operator=(const RobotomyRequestForm &copy);

        bool		execute(Bureaucrat const & executor) const;
};

#endif