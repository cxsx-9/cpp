#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm( std::string target );
        ~PresidentialPardonForm( void );
        PresidentialPardonForm( const PresidentialPardonForm &copy );
        PresidentialPardonForm   &operator=(const PresidentialPardonForm &copy);

        bool		execute(Bureaucrat const & executor) const;
};

#endif