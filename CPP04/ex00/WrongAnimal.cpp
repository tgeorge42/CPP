#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Random WrongAnimal")
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy)
{
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
	this->_type = copy._type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor WrongAnimal Called" << std::endl;
    return ;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal & copyOp)
{
	std::cout << "Copy assignment WrongAnimal operator called" << std::endl;
	this->_type = copyOp._type;
	return (*this);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "Wrong and unaudible sound ..." << std::endl;
	return ;
}

std::string		WrongAnimal::getType( void ) const
{
	return (this->_type);
}
