# include "Character.hpp"

Character::Character() : _name ( "undefined" )
{
	std::cout << "Default Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;

	return ;
}

Character::Character(std::string const & name) : _name( name )
{
	std::cout << "String type Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;

	return ;
}

Character::Character( const Character& copy)
{
	std::cout << "Copy Character constructor called" << std::endl;
	this->_name = copy.getName();
	for (int i = 0; i < 4; i++)
	{
		if ((copy)._inventory[i])
			this->_inventory[i] = (copy)._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}

	return ;
}

Character::~Character()
{
	std::cout << "Destructor Character Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}

    return ;
}

Character &Character::operator=(const Character & copyOp)
{
	std::cout << "Copy assignment Character operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		if ((copyOp)._inventory[i])
			this->_inventory[i] = (copyOp)._inventory[i]->clone();
	}
	return (*this);
}

std::string const &	Character::getName( void ) const
{
	return ( this->_name );
}

void Character::equip(AMateria* m)
{
	int i = 0;
	while (i < 4)
	{
		if (!(this->_inventory[i]))
		{
			this->_inventory[i] = m;
			std::cout << "Materia of type " << m->getType() << " equiped on " << this->getName() << " on slot " << i << std::endl;
			return ;
		}
		i++;
	}
	delete m;
	std::cout << "Inventory is full, Materia was destroyed" << std::endl;
	return ;
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "This slot does not exist" << std::endl;
		return ;
	}
	if (this->_inventory[idx])
	{
		std::cout << "Materia of type " << this->_inventory[idx]->getType() << " was removed from slot number " << idx << std::endl;
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << "This slot is empty" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "This slot does not exist" << std::endl;
		return ;
	}
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "This slot is empty" << std::endl;
}
