#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain* _brain;
	public:
		Dog( void );
		~Dog( void );
		Dog( const Dog &copy );
		Dog const		&operator=(const Dog &copy);
		void	makeSound() const;
		Brain	*getBrain() const;
		void	openTheBrain() const;
};

#endif