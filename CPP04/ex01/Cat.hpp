#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

private:

	Brain* _brain;

public:

	Cat( void );
	Cat( const Cat& copy );
	virtual ~Cat( void );
	Cat &operator=( const Cat & );

	virtual void	makeSound( void ) const;

	virtual				std::string	getIdea(const int i) const;
	virtual void		setIdea(const int i, std::string idea);
};

#endif