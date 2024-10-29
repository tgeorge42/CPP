#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog( const Dog& copy )
{
	std::cout << "Copy Dog constructor called" << std::endl;
	this->_type = copy._type;
}

Dog::~Dog()
{
	std::cout << "Destructor Dog Called" << std::endl;
    return ;
}

Dog &Dog::operator=( const Dog & copyOp )
{
	std::cout << "Copy assignment Dog operator called" << std::endl;
	this->_type = copyOp._type;
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << "Wafff" << std::endl;
	return ;
}
