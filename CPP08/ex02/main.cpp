#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int> tab;
	MutantStack<int>::iterator it;

	tab.push(2);
	tab.push(3);
	tab.push(5);
	tab.push(2);
	std::cout << "Before pop :" << std::endl;
	for (it = tab.begin() ; it < tab.end(); it++)
		std::cout << *it << std::endl;
	tab.pop();
	std::cout << std::endl << "After pop :" << std::endl;
	for (it = tab.begin() ; it < tab.end(); it++)
		std::cout << *it << std::endl;
}

// int	main(void)
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }