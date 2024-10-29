#ifndef CONTACT_H
# define CONTACT_H

class Contact {
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
	int 		_id;
	
public:

	Contact( void );
	~Contact( void );
	void set_first_name( std::string const buff );
	std::string get_first_name( void ) const;
	void set_last_name( std::string const buff );
	std::string get_last_name( void ) const;
	void set_nickname( std::string const buff );
	std::string get_nickname( void ) const;
	void set_phone_number( std::string const buff );
	std::string get_phone_number( void ) const;
	void set_darkest_secret( std::string const buff );
	std::string get_darkest_secret( void ) const;
	void set_id( int const buff );
	int get_id( void ) const;
};

#endif