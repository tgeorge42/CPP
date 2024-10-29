#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap bob("Bob");

	bob.takeDamage(5);
	bob.takeDamage(6);
	bob.attack("Patrick");
	bob.beRepaired(10);

	ClapTrap patrick("Patrick");
	patrick.attack("Carlo");
	patrick.takeDamage(3);
	ClapTrap plankton;
	plankton = patrick;
	std::cout << "patrick's hp : " << patrick.getHp() << std::endl;
	std::cout << "plankton's hp : " << plankton.getHp() << std::endl;
	patrick.beRepaired(2);
	std::cout << "patrick's hp : " << patrick.getHp() << std::endl;
	std::cout << "plankton's hp : " << plankton.getHp() << std::endl;
	return (0);
}
