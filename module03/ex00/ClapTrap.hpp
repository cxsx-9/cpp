#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <string>

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define MAGENTA "\001\033[1;95m\002"
# define GRAY "\001\033[1;90m\002"

class ClapTrap
{
	private:
		std::string	_name;
		int		_hit_point;
		int		_energy_point;
		int		_attack_damage;
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &copy );
		~ClapTrap( void );
		ClapTrap	&operator=( const ClapTrap &copy );
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		// getter
		std::string	getName( void ) const;
		int	getHitPoint( void ) const;
		int	getEnergyPoint( void ) const;
		int	getAttackDamage( void ) const;
		// setter
		void setName( std::string name);
		void setHitPoint( int hit_point);
		void setEnergyPoint( int energy_point);
		void setAttackDamage( int attack_damage );
};

#endif 