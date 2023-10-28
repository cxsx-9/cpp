#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const std::string	_target;
		bool				_status;
		const int			_rgrade;
		const int			_rexecute;
	public:
		AForm( void );
		AForm( std::string name, std::string target, int grade, int execute);
		virtual ~AForm( void );
		AForm( const AForm &copy );
		virtual AForm	&operator=(const AForm &copy);
		
		const std::string	getName() const;
		const std::string	getTarget() const;
		bool				getStatus() const;
		int					getGrade() const;
		int					getExecute() const;

		bool				beSigned(Bureaucrat const &agent);
		virtual bool		execute(Bureaucrat const & executor) const = 0;

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

std::ostream	&operator<<(std::ostream &out, const AForm &sheet);

#endif