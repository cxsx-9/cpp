#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    private:
    	std::string	name_;
		Weapon*		weapon_;
    public:
		HumanB( std::string name );
    	void		attack( void );
		void		setWeapon(Weapon &weapon);
};

#endif