#ifndef DOG_HPP
# define DOG

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog( void );
		~Dog( void );
		Dog( const Dog &copy );
		Dog const		&operator=(const Dog &copy);
		void	makeSound() const;
};

#endif