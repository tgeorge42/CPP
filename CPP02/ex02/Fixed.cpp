#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_valFixe = 0;
	return ;
}

Fixed::Fixed(const int n)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_valFixe = n << this->_nbBits;
	return ;
}

Fixed::Fixed(const float fl) : _valFixe(roundf(fl * (1 << _nbBits)))
{
	// std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed& copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_valFixe = copy.getRawBits();
}

Fixed::~Fixed()
{
	// std::cout << "Destructor Called" << std::endl;
    return ;
}

Fixed &Fixed::operator=(const Fixed & copyOp)
{
	this->_valFixe = copyOp.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed & copyOp) const
{
	return ((this->toFloat()) > (copyOp.toFloat()));
}

bool Fixed::operator<(const Fixed & copyOp) const
{
	return ((this->toFloat()) < (copyOp.toFloat()));
}

bool Fixed::operator>=(const Fixed & copyOp) const
{
	return ((this->toFloat()) >= (copyOp.toFloat()));
}

bool Fixed::operator<=(const Fixed & copyOp) const
{
	return ((this->toFloat()) <= (copyOp.toFloat()));
}

bool Fixed::operator==(const Fixed & copyOp) const
{
	return ((this->toFloat()) == (copyOp.toFloat()));
}

bool Fixed::operator!=(const Fixed & copyOp) const
{
	return ((this->toFloat()) != (copyOp.toFloat()));
}

Fixed Fixed::operator+(const Fixed & copyOp) const
{
	return Fixed(this->toFloat() + copyOp.toFloat());
}

Fixed Fixed::operator-(const Fixed & copyOp) const
{
	return Fixed(this->toFloat() - copyOp.toFloat());
}

Fixed Fixed::operator*(const Fixed & copyOp) const
{
	return Fixed(this->toFloat() * copyOp.toFloat());
}

Fixed Fixed::operator/(const Fixed & copyOp) const
{
	return Fixed(this->toFloat() / copyOp.toFloat());
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	_valFixe++;
	return(tmp);	
}

Fixed& Fixed::operator++(void)
{
	_valFixe++;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	_valFixe--;
	return(tmp);	
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2) {
	
	return((n1 < n2) ? n1 : n2);
}

Fixed const &Fixed::min(const Fixed &n1, const Fixed &n2) {
	
	return((n1 < n2) ? n1 : n2);	
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2) {
	
	return((n1 > n2) ? n1 : n2);	
}

Fixed const &Fixed::max(const Fixed &n1, const Fixed &n2) {
	
	return((n1 > n2) ? n1 : n2);
}

Fixed& Fixed::operator--(void)
{
	_valFixe--;
	return(*this);
}

void Fixed::setRawBits( int const raw )
{
	this->_valFixe = raw;
}


int Fixed::getRawBits( void ) const
{
	return (this->_valFixe);
}

int 	Fixed::toInt( void ) const
{
	return ((this->getRawBits()) >> this->_nbBits);
}

float Fixed ::toFloat( void ) const
{
	return (static_cast<float> (this->getRawBits()) / (1 << this->_nbBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& rhs) 
{
    out << rhs.toFloat();
    return (out);
}
