#ifndef CAT_HPP
# define CAT

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat( void );
		~Cat( void );
		void	makeSound() const;
};

#endif