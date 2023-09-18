#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define MAGENTA "\001\033[1;95m\002"
# define GRAY "\001\033[1;90m\002"

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain( std::string type );
		~Brain( void );
		void	ExpressTheIdea( void ) const;
};

#endif