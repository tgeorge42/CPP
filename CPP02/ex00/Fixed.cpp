#include "Fixed.hpp"

Fixed::Fixed() : _valFixe( 0 )
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed& copy)
{ 	
	std::cout << "Copy constructor called" << std::endl;
	this->_valFixe = copy.getRawBits();
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed & copyOp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_valFixe = copyOp.getRawBits();
	return (*this);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_valFixe = raw;
	return ;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_valFixe);
}
