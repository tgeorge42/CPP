#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->_brain = new Brain();
	this->_type = "Dog";
	return ;
}

Dog::Dog( const Dog& copy )
{
	std::cout << "Copy Dog constructor called" << std::endl;
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);

	return ;
}

Dog::~Dog()
{
	std::cout << "Destructor Dog Called" << std::endl;
	delete this->_brain;

    return ;
}

Dog &Dog::operator=( const Dog & copyOp )
{
	std::cout << "Copy assignment Dog operator called" << std::endl;
	this->_type = copyOp._type;
	delete this->_brain;
	this->_brain = new Brain(*copyOp._brain);

	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << "Wafff" << std::endl;

	return ;
}

std::string		Dog::getIdea(const int i) const
{
	if (i < 100)
		return this->_brain->getIdea(i);
	else
		return ("Animals are not overthinkers");
}

void		Dog::setIdea(const int i, std::string idea)
{
	this->_brain->setIdea(i, idea);

	return ;
}
