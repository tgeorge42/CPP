#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

private:

	int	_valFixe;
	static int const	_nbBits = 8;

public:

	Fixed( void );
	Fixed( const Fixed& copy);
	~Fixed( void );
	Fixed &operator=(const Fixed &);
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif