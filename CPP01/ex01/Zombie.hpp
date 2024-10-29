#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie {

private:

	std::string		_name;

public:

	Zombie( void );
	~Zombie( void );
	void	setName( std::string name );
	void	announce( void );
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );
Zombie*	zombieHorde( int N, std::string name );
#endif