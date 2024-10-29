#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:

		Ice( void );
		virtual ~Ice( void );
		Ice(const Ice& copy);
		Ice &operator=(const Ice &);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif