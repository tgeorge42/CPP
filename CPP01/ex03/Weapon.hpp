#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon {

private:

	std::string		_type;

public:

	Weapon( std::string weapon );
	~Weapon( void );
	std::string const &getType( void );
	void	setType( std::string type );
};

#endif