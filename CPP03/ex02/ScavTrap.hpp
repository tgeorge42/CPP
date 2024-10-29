#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap( void );
	ScavTrap( std::string name );
	~ScavTrap();
	ScavTrap( const ScavTrap& copy);
	ScavTrap &operator=(const ScavTrap & copyOp);

	void	attack( const std::string& target );
	void	guardGate(void);
};

#endif