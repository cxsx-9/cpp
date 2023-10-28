#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_status;
		const int			_rgrade;
		const int			_rexecute;
	public:
		Form( void );
		Form( std::string name, int grade, int execute);
		~Form( void );
		Form( const Form &copy );
		Form	&operator=(const Form &copy);
		std::string const	getName() const;
		bool				getStatus() const;
		int					getGrade() const;
		int					getExecute() const;
		bool				beSigned(Bureaucrat const &agent);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

std::ostream	&operator<<(std::ostream &out, const Form &sheet);

#endif