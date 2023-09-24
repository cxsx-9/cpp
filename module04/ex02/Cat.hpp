#ifndef CAT_HPP
# define CAT

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain* _brain;
	public:
		Cat( void );
		~Cat( void );
		Cat( const Cat &copy );
		Cat const		&operator=(const Cat &copy);
		void	makeSound() const;
		Brain	*getBrain() const;
		void	openTheBrain() const;
};

#endif