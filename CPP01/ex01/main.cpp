#include "Zombie.hpp"

int	main(void)
{
	int	i = 0;
	int	N = 5;

	Zombie	*horde = zombieHorde(N, "Clone");
	while (i < N)
		horde[i++].announce();
	delete [] horde;
	return (0);
}
