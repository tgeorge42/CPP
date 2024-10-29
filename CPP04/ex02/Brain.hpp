#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {

private:

	std::string		_ideas[100];

public:

	Brain( void );
	Brain( const Brain& copy);
	~Brain( void );
	Brain &operator=(const Brain &);

	void		setIdea( const int i , std::string idea);
	std::string	getIdea( const int i ) const;
};

#endif