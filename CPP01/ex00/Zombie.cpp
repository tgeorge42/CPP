#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {

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
