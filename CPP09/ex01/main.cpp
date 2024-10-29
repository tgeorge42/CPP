#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			RPN::reverse_polish(av[1]);
		}
		catch(std::string& str)
		{
			std::cout << "Error : " << str << std::endl;
		}
	}
}