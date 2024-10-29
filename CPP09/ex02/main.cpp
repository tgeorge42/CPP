#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Error: bad arguments number." << std::endl;
		return (1);
	}
	try
	{
		PmergeMe instance(av);
		instance.process();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}