#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <stdlib.h>

# define TYPE_EMPTY		0
# define TYPE_CHAR		1
# define TYPE_INT		2
# define TYPE_FLOAT		3
# define TYPE_DOUBLE	4
# define TYPE_IMPOSIBLE	5
# define TYPE_UNKNOW	6

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"
# define RED "\001\033[1;91m\002"
# define BLUE "\001\033[1;94m\002"
# define GREEN "\001\033[1;92m\002"

class ScalarConverter
{
	public:
		static std::string	_value;
		static int	_type;
		static int	_prec;
		static int	_intValue;
		static char	_charValue;
		static float	_floatValue;
		static double	_doubleValue;

		ScalarConverter( void );
		~ScalarConverter( void );
		ScalarConverter( const ScalarConverter &copy );
		ScalarConverter	&operator=(const ScalarConverter &copy);

		static void	typeCheck(const std::string &value);
		static void	convert(char *value);
		static void	displayValue();

		class UnknowTypeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class BadInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif