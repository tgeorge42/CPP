# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;

	return ;
}

MateriaSource::MateriaSource( const IMateriaSource& copy)
{
	std::cout << "Copy MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (((MateriaSource)copy)._inventory[i])
			this->_inventory[i] = ((MateriaSource)copy)._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}

	return ;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor MateriaSource Called" << std::endl;
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

MateriaSource &MateriaSource::operator=(const IMateriaSource & copyOp)
{
	std::cout << "Copy assignment MateriaSource operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (((MateriaSource)copyOp)._inventory[i])
			this->_inventory[i] = ((MateriaSource)copyOp)._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}

	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	while (i < 4)
	{
		if (!(this->_inventory[i]))
		{
			this->_inventory[i] = m;
			std::cout << "Materia of type " << m->getType() << " stored in MateriaSource" << std::endl;
			return ;
		}
		i++;
	}
	std::cout << "Inventory is full" << std::endl;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 3;

	if (type == "ice" || type == "cure")
	{
		while (i >= 0)
		{
			if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			{
				return (this->_inventory[i]->clone());
			}
			i--;
		}
		std::cout << "No corresponding Materia currently in the MateriaSource" << std::endl;
		return ( 0 );
	}
	else
		return ( 0 );
}
