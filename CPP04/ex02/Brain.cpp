#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0 ; i < 100 ; i++)
		this->_ideas[i] = "default idea";
	std::cout << "Default Brain constructor called" << std::endl;
	return ;
}

Brain::Brain( const Brain& copy)
{
	std::cout << "Copy Brain constructor called" << std::endl;
	for (int i = 0 ; i < 100 ; i++)
		this->setIdea(i, copy.getIdea(i));
}

Brain::~Brain()
{
	std::cout << "Destructor Brain Called" << std::endl;
    return ;
}

Brain &Brain::operator=(const Brain & copyOp)
{
	std::cout << "Copy assignment Brain operator called" << std::endl;
	for (int i = 0 ; i < 100 ; i++)
		this->setIdea(i, copyOp.getIdea(i));
	return (*this);
}


void	Brain::setIdea( const int i , std::string idea)
{
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << "Animals are not overthinkers" << std::endl;
	return ;
}

std::string	Brain::getIdea( const int i ) const
{
	if (i < 100)
		return this->_ideas[i];
	return ("Animals are not overthinkers");
}
