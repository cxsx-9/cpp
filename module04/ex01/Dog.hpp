#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;
	public:
		Dog( void );
		~Dog( void );
		Dog( const Dog &copy );
		Dog const		&operator=(const Dog &copy);
		void	makeSound() const;
		void	openTheBrain() const;
};

#endif