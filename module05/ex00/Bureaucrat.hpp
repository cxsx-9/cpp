#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"
# define RED "\001\033[1;91m\002"
# define GREEN "\001\033[1;92m\002"
# define BLUE "\001\033[1;94m\002"
# define CYAN "\001\033[1;96m\002"
# define MAGENTA "\001\033[1;95m\002"
# define GRAY "\001\033[1;90m\002"

class Bureaucrat
{
	private:
		const std::string	_name;
		int 		_level;
	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, int level );
		~Bureaucrat( void );
		Bureaucrat( const Bureaucrat &copy );
		Bureaucrat	&operator=(const Bureaucrat &copy);

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
	
		std::string const		getName() const;
		int					getGrade() const;

		void incrementGrade(int amount);
		void decrementGrade(int amount);
		// increment or decrement (throw if it is out of range)
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &agent);

#endif