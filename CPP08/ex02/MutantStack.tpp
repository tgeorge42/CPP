#include "MutantStack.hpp"

template<typename T>

MutantStack<T>::MutantStack()
{
	return ;
}

template<typename T>

MutantStack<T>::~MutantStack()
{
	return ;
}

template<typename T>

MutantStack<T>::MutantStack(const MutantStack & copy)
{
	(void)copy;

	return ;
}

template<typename T>

MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> & copyOp)
{
	(void)copyOp;
	
	return ;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}