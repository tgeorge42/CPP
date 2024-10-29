#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include "Contact.hpp"

class PhoneBook {

private:
	int		i;
	int		len;
	Contact _contact[8];
public:

	PhoneBook( void );
	~PhoneBook( void );
	int Add( void );
	int Search( void );
	void write_thing ( std::string const thing );
	void write_id( int id );
	int	stringToInt(const std::string& str);
	std::string const writeAdd( std::string const thing );
};

#endif