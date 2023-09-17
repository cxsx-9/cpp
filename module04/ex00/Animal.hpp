#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define MAGENTA "\001\033[1;95m\002"
# define GRAY "\001\033[1;90m\002"
class Animal
{
	protected:
		std::string	_type;
	public:
		Animal( void );
		virtual ~Animal( void );
		std::string	const	getType( void ) const;
		void				setType( std::string const type );
		Animal const		&operator=(const Animal &copy);
		virtual void		makeSound() const;
};

#endif