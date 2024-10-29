#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap( void );
	FragTrap( std::string name );
	~FragTrap();
	FragTrap( const FragTrap& copy);
	FragTrap &operator=(const FragTrap & copyOp);

	void	highFivesGuys(void);
};

#endif