#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( std::string target );
        ~ShrubberyCreationForm( void );
        ShrubberyCreationForm( const ShrubberyCreationForm &copy );
        ShrubberyCreationForm   &operator=(const ShrubberyCreationForm &copy);

        bool		execute(Bureaucrat const & executor) const;
};

#endif