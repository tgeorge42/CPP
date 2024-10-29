#include "Zombie.hpp"

Zombie::Zombie( void ) {

	std::cout << "Constructor Zombie called" << std::endl;
	return;
}

Zombie::~Zombie( void ) {

	std::cout << "Destructor Zombie called for : \"" << this->_name << "\"" << std::endl;
	return;
}

void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->_name = name;
}
