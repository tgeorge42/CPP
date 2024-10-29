#include "Animal.hpp"

Animal::Animal() : _type("Random animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
	return ;
}

Animal::Animal( const Animal& copy)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	this->_type = copy._type;
}

Animal::~Animal()
{
	std::cout << "Destructor Animal Called" << std::endl;
    return ;
}

Animal &Animal::operator=(const Animal & copyOp)
{
	std::cout << "Copy assignment Animal operator called" << std::endl;
	this->_type = copyOp._type;
	return (*this);
}

std::string		Animal::getType( void ) const
{
	return (this->_type);
}
