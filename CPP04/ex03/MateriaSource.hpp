#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	private:

		AMateria* 	_inventory[4];

	public:

		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(const IMateriaSource& copy);
		MateriaSource &operator=(const IMateriaSource &);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};

#endif