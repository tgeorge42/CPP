#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::Cat( const Cat& copy )
{
	std::cout << "Copy Cat constructor called" << std::endl;
	this->_type = copy._type;
}

Cat::~Cat()
{
	std::cout << "Destructor Cat Called" << std::endl;
    return ;
}

Cat &Cat::operator=( const Cat & copyOp )
{
	std::cout << "Copy assignment Cat operator called" << std::endl;
	this->_type = copyOp._type;
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meoowwww" << std::endl;
	return ;
}
