#include "easyfind.hpp"

void	print_content(int i)
{
	std::cout << i << " ";
}

int	main(void)
{
	try
	{
		std::list<int> my_list;

		for (int i = 0 ; i < 10 ; i++)
			my_list.push_back((i % 3 == 0 ? i * 3 + 10 : i * 2 + 5));
		std::cout << "Content of my_list : ";
		for_each(my_list.begin(), my_list.end(), print_content);
		std::cout << std::endl;
		std::cout << "Test with 15 : " << std::endl;
		std::list<int>::iterator it = easyfind(my_list, 15);
		std::cout << "Return value of easyfind : " << std::distance(my_list.begin(), it) << std::endl;
		std::cout << "Test with 20 : " << std::endl;
		it = easyfind(my_list, 20);
	}
	catch(const notFoundException& e)
	{
		std::cerr << e.what() << '\n';
	}
}
