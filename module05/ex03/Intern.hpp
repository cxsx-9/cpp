#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    public:
        Intern( void );
        ~Intern( void );
        Intern( const Intern &copy );
        Intern	&operator=(const Intern &copy);

        AForm* makeForm(const std::string name, const std::string target);
        class UnknowFormException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif