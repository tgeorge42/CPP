#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	_name = "<undefined>";
	_hp = 100;
	_ep = 100;
	_damage = 30;
	std::cout << "Default FragTrap constructor called." << std::endl;
	return ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	_name = name;
	_hp = 100;
	_ep = 100;
	_damage = 30;
	std::cout << "FragTrap constructor called for " << name << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << this->_name << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &src) {

    std::cout << "FragTrap copy Constructor Called" << std::endl;
    *this = src;
    return ;
}

FragTrap&	FragTrap::operator=(FragTrap const &copyOp) {

	std::cout << "FragTrap copy Assignement Operator Called" << std::endl;
	if (this != &copyOp)
	{
		this->_name = copyOp.getName();
		this->setHp(copyOp.getHp());
		this->setEp(copyOp.getEp());
		this->setDamage(copyOp.getDamage());
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " makes a high five !" << std::endl;
	return;
}
