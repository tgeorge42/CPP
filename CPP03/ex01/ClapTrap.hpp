#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap {

protected:

	std::string _name;
	int			_hp;
	int			_ep;
	int			_damage;

public:

	ClapTrap( void );
	ClapTrap( std::string name );
	~ClapTrap();
	ClapTrap( const ClapTrap& copy);
	ClapTrap &operator=(const ClapTrap & copyOp);

	void			attack( const std::string& target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );

	void			setName( std::string name );
	std::string		getName( void ) const;
	void			setHp( int amount );
	int				getHp( void ) const;
	void			setEp( int amount );
	int				getEp( void ) const;
	void			setDamage( int amount );
	int				getDamage( void ) const;
};

#endif