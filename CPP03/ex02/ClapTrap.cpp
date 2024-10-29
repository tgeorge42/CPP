#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name( "<undefined>" ), _hp( 10 ), _ep( 10 ), _damage( 0 )
{
	std::cout << "Default ClapTrap constructor called." << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name( name ), _hp( 10 ), _ep( 10 ), _damage( 0 )
{
	std::cout << "ClapTrap constructor called for " << name << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &src) {

    std::cout << "ClapTrap copy Constructor Called" << std::endl;
    *this = src;
    return ;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &copyOp) {

	std::cout << "ClapTrap copy Assignement Operator Called" << std::endl;
	if (this != &copyOp)
	{
		this->_name = copyOp.getName();
		this->setHp(copyOp.getHp());
		this->setEp(copyOp.getEp());
		this->setDamage(copyOp.getDamage());
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack." << std::endl;
		return ;
	}
	if (this->_ep <= 0)
	{
		this->_ep = 0;
		std::cout << "No more Energy points. ClapTrap " << this->_name
		<< " cannot do anything." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target
	<< ", causing " << this->_damage << " points of damage!" << std::endl;
	this->_ep -= 1;

	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " was hit and took "
	<< amount << " damage." << std::endl;
	if (this->_hp - (int)amount <= 0)
	{
		this->_hp = 0;
		return ;
	}
	else
		this->_hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot repair itself." << std::endl;
		return ;
	}
	if (this->_ep <= 0)
	{
		this->_ep = 0;
		std::cout << "No more Energy points. ClapTrap " << this->_name
		<< " cannot do anything." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " repaired itself and gained "
	<< amount << " hp back." << std::endl;
	this->_hp += amount;
	this->_ep -= 1;

	return ;
}

void	ClapTrap::setName( std::string name )
{
	this->_name = name;
}

std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}

void	ClapTrap::setHp( int amount )
{
	this->_hp = amount;
}

int	ClapTrap::getHp( void ) const
{
	return (this->_hp);
}

void	ClapTrap::setEp( int amount )
{
	this->_ep = amount;
}

int	ClapTrap::getEp( void ) const
{
	return (this->_ep);
}

void	ClapTrap::setDamage( int amount )
{
	this->_damage = amount;
}

int	ClapTrap::getDamage( void ) const
{
	return (this->_damage);
}
