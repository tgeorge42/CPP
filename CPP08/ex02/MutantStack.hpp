#pragma once

# include <iostream>
# include <algorithm>
# include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
	public :

		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack & copy);
		MutantStack &operator=(const MutantStack & copyOp);

		typedef typename std::deque<T>::iterator iterator;

		iterator	begin();
		iterator	end();
};

#include "MutantStack.tpp"