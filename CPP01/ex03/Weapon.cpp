#include "Weapon.hpp"

Weapon::Weapon( std::string weapon ) : _type( weapon )
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

std::string const &Weapon::getType( void )
{
	return (this->_type);
}

void Weapon::setType( std::string type )
{
	this->_type = type;
}
