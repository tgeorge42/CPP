#include "Base.hpp"

int main(void)
{
	srand((time(NULL)));
	std ::cout << "class identification creation"  << std::endl;
	Base *p[10];
	for (int i = 0; i < 10; i++)
	{
		std::cout << "p" << i << ": ";
		p[i] = generate();
	}

	std::cout << std::endl << "class identification via pointer function:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "p" << i << ": ";
		identify(p[i]);
	}

	std::cout << std::endl << "class identification via reference function:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "p" << i << ": ";
		identify(*p[i]);
	}

	std::cout << std::endl << "undefined type via pointer and reference :" << std::endl;

	Base p10;	
	identify(p10);
	identify(&p10);
	
	for (int i = 0; i < 10; i++)
	{
		delete p[i];
	}
	
	return (0);
}