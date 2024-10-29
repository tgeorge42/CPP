#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap bob("Bob");

	std::cout << std::endl;
	bob.takeDamage(5);
	bob.takeDamage(6);
	bob.attack("Patrick");
	bob.beRepaired(10);
	std::cout << std::endl;

	FragTrap krabs("Mr Krabs");

	std::cout << std::endl;
	krabs.takeDamage(60);
	krabs.highFivesGuys();
	krabs.attack("Bob");
	std::cout << "FragTrap " << krabs.getName() << " has " << krabs.getHp() << " Hp left." << std::endl;
	std::cout << std::endl;

	FragTrap sandy;
	sandy.attack("nobody");
	std::cout << std::endl;

	return (0);
}
