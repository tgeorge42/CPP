#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie bob(name);
	bob.announce();
	return ;
}
