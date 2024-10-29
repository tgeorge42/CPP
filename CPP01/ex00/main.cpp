#include "Zombie.hpp"

int	main()
{
	Zombie *foo = newZombie("Foo");	
	foo->announce();
	delete foo;
	randomChump("Bob");
	randomChump("Sam");
	return (0);
}
