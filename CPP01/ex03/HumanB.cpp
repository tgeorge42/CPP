#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name( name ), _weapon( NULL )
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void HumanB::attack()
{
	if (!(this->_weapon))
		std::cout << this->_name << " attacks with their bare hands" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}

void HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
	return ;
}
