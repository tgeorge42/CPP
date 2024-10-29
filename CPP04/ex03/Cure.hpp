#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:

		Cure( void );
		virtual ~Cure( void );
		Cure(const Cure& copy);
		Cure &operator=(const Cure &);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif