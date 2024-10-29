#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

private:

	Brain* _brain;

public:

	Dog( void );
	Dog( const Dog& copy );
	virtual ~Dog( void );
	Dog &operator=( const Dog & );
	
	virtual void	makeSound( void ) const;

	virtual 			std::string	getIdea(const int i) const;
	virtual void		setIdea(const int i, std::string idea);
};

#endif