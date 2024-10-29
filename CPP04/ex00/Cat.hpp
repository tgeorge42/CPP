#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {

public:

	Cat( void );
	Cat( const Cat& copy );
	~Cat( void );
	Cat &operator=( const Cat & );
	virtual void	makeSound( void ) const;
};

#endif