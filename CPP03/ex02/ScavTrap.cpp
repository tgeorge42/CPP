#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	_name = "<undefined>";
	_hp = 100;
	_ep = 50;
	_damage = 20;
	std::cout << "Default ScavTrap constructor called." << std::endl;
	return ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	_name = name;
	_hp = 100;
	_ep = 50;
	_damage = 20;
	std::cout << "ScavTrap constructor called for " << name << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << this->_name << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &src) {

    std::cout << "ScavTrap copy Constructor Called" << std::endl;
    *this = src;
    return ;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const &copyOp) {

	std::cout << "ScavTrap copy Assignement Operator Called" << std::endl;
	if (this != &copyOp)
	{
		this->_name = copyOp.getName();
		this->setHp(copyOp.getHp());
		this->setEp(copyOp.getEp());
		this->setDamage(copyOp.getDamage());
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hp <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead and cannot attack." << std::endl;
		return ;
	}
	if (this->_ep <= 0)
	{
		this->_ep = 0;
		std::cout << "No more Energy points. ScavTrap " << this->_name
		<< " cannot do anything." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target
	<< ", causing " << this->_damage << " points of damage!" << std::endl;
	this->_ep -= 1;

	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is holding the door !" << std::endl;
	return;
}
