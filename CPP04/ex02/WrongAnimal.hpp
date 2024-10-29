#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {

protected:

	std::string _type;

public:

	WrongAnimal( void );
	WrongAnimal( const WrongAnimal& copy);
	~WrongAnimal( void );
	WrongAnimal &operator=(const WrongAnimal &);

	std::string		getType( void ) const;
	void	makeSound( void ) const;
};

#endif