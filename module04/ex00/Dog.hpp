#ifndef DOG_HPP
# define DOG

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog( void );
		~Dog( void );
		void	makeSound() const;
};

#endif