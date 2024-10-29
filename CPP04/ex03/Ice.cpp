# include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Default Ice constructor called" << std::endl;
	return ;
}


Ice::Ice( const Ice& copy)
{
	std::cout << "Copy Ice constructor called" << std::endl;
	this->_type = copy._type;

	return ;
}

Ice::~Ice()
{
	std::cout << "Destructor Ice Called" << std::endl;

    return ;
}

Ice &Ice::operator=(const Ice & copyOp)
{
	std::cout << "Copy assignment Ice operator called" << std::endl;
	this->_type = copyOp._type;

	return (*this);
}

std::string const & Ice::getType() const
{
	return (this->_type);
}

AMateria* Ice::clone() const
{
	Ice	*tmp = new Ice();

	return (tmp);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;

	return ;
}
