#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define MAGENTA "\001\033[1;95m\002"
# define GRAY "\001\033[1;90m\002"
class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal( void );
		virtual ~WrongAnimal( void );
		WrongAnimal( const WrongAnimal &copy );
		WrongAnimal const		&operator=(const WrongAnimal &copy);
		std::string	const	getType( void ) const;
		void				setType( std::string const type );
		virtual void		makeSound() const;
};

#endif