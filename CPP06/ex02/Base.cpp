#include "Base.hpp"

Base* generate(void)
{
	unsigned int random = rand() % 3;
	switch(random)
	{
		case 0:
			std::cout << "Class A created" << std::endl;
			return (new A);
		case 1:
			std::cout << "Class B created" << std::endl;
			return (new B);
		case 2:
			std::cout << "Class C created" << std::endl;
			return (new C);
		default:
			return (NULL);
 	}
}

void	identify(Base* p)
{
	A *ptr_A = dynamic_cast<A*>(p);
	if (!ptr_A)
	{
		B *ptr_B = dynamic_cast<B*>(p);
		if (!ptr_B)
		{
			C *ptr_C = dynamic_cast<C*>(p);
			if (!ptr_C)
				std::cout << "Type of p is undefined" << std::endl;
			else
				std::cout << "Type of p is C" << std::endl;
		}
		else
			std::cout << "Type of p is B" << std::endl;
	}
	else
		std::cout << "Type of p is A" << std::endl;
}

void	identify(Base& p)
{
	Base tmp;
	try
	{
		tmp =  dynamic_cast<A&>(p);
		std::cout << "Type of p is A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {(void)e; }
	try
	{
		tmp =  dynamic_cast<B&>(p);
		std::cout << "Type of p is B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {(void)e; }
	try
	{
		tmp =  dynamic_cast<C&>(p);
		std::cout << "Type of p is C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {(void)e; }
	std::cout << "Type of p is undefined" << std::endl;
}
