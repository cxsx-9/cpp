#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
    private:
        std::string	type;
	public:
		Weapon( std::string tpye );
		const std::string	&getType( void );
		void				setType( std::string param );
};

#endif