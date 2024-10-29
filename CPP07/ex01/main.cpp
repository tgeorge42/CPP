#include "iter.hpp"

template<typename T>
void	plusOne(T & elem)
{
	elem += 1;

	return ;
}

template<typename T>
void	ft_toupper(T & c)
{
	if (c > 96 && c < 123)
		c -= 32;
}

int	main(void)
{
	int array[] = {0, 1, 2, 3, 4, 5};

	std::cout << "BEFORE ITER :" << std::endl;
	for (int i = 0; i < 6 ; i++)
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	
	iter(array, 6, plusOne<int>);
	std::cout << std::endl << "AFTER ITER :" << std::endl;

	for (int i = 0; i < 6 ; i++)
		std::cout << "array[" << i << "] = " << array[i] << std::endl;

	char str[] = "salut 42 HeLlo";
	std::cout << std::endl << "TO UPPER :" << std::endl;
	std::cout << str << std::endl;
	iter(str, static_cast<int>(strlen(str)), ft_toupper<char>);
	std::cout << str << std::endl;

}

// class Awesome
// {
// 	private :
// 		int _n;
// 	public :
// 		Awesome(void):_n(42)
// 		{
// 			return;
// 		}
// 		int get(void) const
// 		{
// 			return this->_n;
// 		}
// };

// std::ostream & operator<<(std::ostream & o, Awesome const & rhs)
// {
// 	o << rhs.get();
// 	return o;
// }

// template<typename T>
// void print(T const & x)
// {
// 	std::cout << x << std::endl;
// 	return;
// }

// int main(void)
// {
// 	int tab[] = {0, 1, 2, 3, 4};
// 	Awesome tab2[5];

// 	iter(tab, 5, print<const int>);
// 	iter(tab2, 5, print<const Awesome>);

// 	return (0);

// }