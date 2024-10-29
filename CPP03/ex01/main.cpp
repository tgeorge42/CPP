#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap bob("Bob");

	std::cout << std::endl;
	bob.takeDamage(5);
	bob.takeDamage(6);
	bob.attack("Patrick");
	bob.beRepaired(10);
	std::cout << std::endl;

	ScavTrap plankton("Plankton");

	std::cout << std::endl;
	plankton.takeDamage(10);
	plankton.guardGate();
	plankton.attack("Bob");
	std::cout << "ScavTrap " << plankton.getName() << " has " << plankton.getHp() << " Hp left." << std::endl;
	std::cout << std::endl;
	return (0);
}
