#include <iostream>
#include "Contact.hpp"

Contact::Contact( void ) {

	// std::cout << "Constructor contact called" << std::endl;
	return;
}

Contact::~Contact( void ) {

	// std::cout << "Destructor contact called" << std::endl;
	return;
}

void Contact::set_first_name( std::string const buff )
{
	this->_first_name = buff;
}

std::string Contact::get_first_name( void ) const
{
	return (this->_first_name);
}

void Contact::set_last_name( std::string const buff )
{
	this->_last_name = buff;
}

std::string Contact::get_last_name( void ) const
{
	return (this->_last_name);
}

void Contact::set_nickname( std::string const buff )
{
	this->_nickname = buff;
}

std::string Contact::get_nickname( void ) const
{
	return (this->_nickname);
}

void Contact::set_phone_number( std::string const buff )
{
	this->_phone_number = buff;
}

std::string Contact::get_phone_number( void ) const
{
	return (this->_phone_number);
}

void Contact::set_darkest_secret( std::string const buff )
{
	this->_darkest_secret = buff;
}

std::string Contact::get_darkest_secret( void ) const
{
	return (this->_darkest_secret);
}

void Contact::set_id( int const id )
{
	this->_id = id;
}
int Contact::get_id( void ) const
{
	return (this->_id);
}