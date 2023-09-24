#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define MAGENTA "\001\033[1;95m\002"
# define GRAY "\001\033[1;90m\002"

class AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal( void );
		virtual ~AAnimal( void );
		AAnimal( const AAnimal &copy );
		AAnimal const		&operator=(const AAnimal &copy);
		std::string	const	getType( void ) const;
		void				setType( std::string const type );
		virtual void		makeSound() const = 0;
};

#endif