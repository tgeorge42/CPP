# include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Default Cure constructor called" << std::endl;
	return ;
}

Cure::Cure( const Cure& copy)
{
	std::cout << "Copy Cure constructor called" << std::endl;
	this->_type = copy._type;

	return ;
}

Cure::~Cure()
{
	std::cout << "Destructor Cure Called" << std::endl;

    return ;
}

Cure &Cure::operator=(const Cure & copyOp)
{
	std::cout << "Copy assignment Cure operator called" << std::endl;
	this->_type = copyOp._type;

	return (*this);
}

std::string const & Cure::getType() const
{
	return (this->_type);
}

// Cure* Cure::clone() const
// {
// 	//Cure	*tmp = new Cure();
// 	return (new Cure());
// }

AMateria* Cure::clone() const
{
	Cure	*tmp = new Cure();
	return (tmp);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;

	return ;
}
