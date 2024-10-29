#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

private:

	int	_valFixe;
	static int const	_nbBits = 16;

public:

	Fixed( void );
	Fixed( const int n );
	Fixed( const float fl );
	Fixed( const Fixed& copy);
	~Fixed( void );

	Fixed &operator=(const Fixed &);

	int toInt( void ) const;
	float toFloat( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream & operator<<( std::ostream & out, Fixed const & rhs );

#endif