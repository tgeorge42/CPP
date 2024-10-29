#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
	private:

		AMateria* 	_inventory[4];
		std::string _name;

	public:

		Character();
		Character(std::string const & type);
		virtual ~Character();
		Character(const Character& copy);
		Character &operator=(const Character &);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif