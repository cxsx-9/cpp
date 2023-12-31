#ifndef CAT_HPP
# define CAT

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat( void );
		~Cat( void );
		Cat( const Cat &copy );
		Cat const		&operator=(const Cat &copy);
		void	makeSound() const;
};

#endif