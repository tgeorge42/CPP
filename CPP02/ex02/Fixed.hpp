#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

private:

	int	_valFixe;
	static int const	_nbBits = 8;

public:

	Fixed( void );
	Fixed( const int n );
	Fixed( const float fl );
	Fixed( const Fixed& copy);
	~Fixed( void );

	Fixed &operator=(const Fixed & copyOp);

	bool operator>(const Fixed & copyOp) const;
	bool operator<(const Fixed & copyOp) const;
	bool operator>=(const Fixed & copyOp) const;
	bool operator<=(const Fixed & copyOp) const;
	bool operator==(const Fixed & copyOp) const;
	bool operator!=(const Fixed & copyOp) const;
	
	Fixed operator+(const Fixed & copyOp) const;
	Fixed operator-(const Fixed & copyOp) const;
	Fixed operator*(const Fixed & copyOp) const;
	Fixed operator/(const Fixed & copyOp) const;

	Fixed operator++(int);
	Fixed&	operator++(void);
	Fixed	operator--(int);
	Fixed&	operator--(void);

	static Fixed&		min(Fixed &n1, Fixed &n2);
	static const Fixed&	min(const Fixed &n1, const Fixed &n2);
	static Fixed&		max(Fixed &n1, Fixed &n2);
	static const Fixed&	max(const Fixed &n1, const Fixed &n2);

	int toInt( void ) const;
	float toFloat( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream & operator<<( std::ostream & out, Fixed const & rhs );

#endif