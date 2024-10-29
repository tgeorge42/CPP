# include "AMateria.hpp"

AMateria::AMateria(): _type( "None" )
{
	std::cout << "Default AMateria constructor called" << std::endl;

	return ;
}

AMateria::AMateria(std::string const & type) : _type( type )
{
	std::cout << "String type AMateria constructor called" << std::endl;

	return ;
}

AMateria::AMateria( const AMateria& copy)
{
	std::cout << "Copy AMateria constructor called" << std::endl;
	this->_type = copy._type;

	return ;
}

AMateria::~AMateria()
{
	std::cout << "Destructor AMateria Called" << std::endl;

    return ;
}

AMateria &AMateria::operator=(const AMateria & copyOp)
{
	std::cout << "Copy assignment AMateria operator called" << std::endl;
	this->_type = copyOp._type;

	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Nothing happens here with " << target.getName() << std::endl;

	return ;
}

