#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat( const WrongCat& copy )
{
	std::cout << "Copy WrongCat constructor called" << std::endl;
	this->_type = copy._type;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor WrongCat Called" << std::endl;
    return ;
}

WrongCat &WrongCat::operator=( const WrongCat & copyOp )
{
	std::cout << "Copy assignment WrongCat operator called" << std::endl;
	this->_type = copyOp._type;
	return (*this);
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Meoowwww" << std::endl;
	return ;
}
