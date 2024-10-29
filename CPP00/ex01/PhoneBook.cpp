#include <iostream>
#include <string>
#include <sstream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {

	this->i = 0;
	this->len = 0;
	return;
}

PhoneBook::~PhoneBook( void ) {

	return;
}

std::string const PhoneBook::writeAdd( std::string const thing )
{	
	std::string buff;

	std::cout << thing << " : ";
	std::getline(std::cin, buff);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return ("");
	}
	while (buff.empty())
	{
		std::cout << thing << " (NOT EMPTY) :";
		std::getline(std::cin, buff);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ("");
		}
	}
	return (buff);
}

int	PhoneBook::Add( void ) {

	std::string buff = "";
	
	buff = this->writeAdd("FIRST NAME");
	if (buff == "")
		return (1);
	this->_contact[this->i].set_first_name(buff);
	buff = this->writeAdd("LAST NAME");
	if (buff == "")
		return (1);
	this->_contact[this->i].set_last_name(buff);
	buff = this->writeAdd("NICKNAME");
	if (buff == "")
		return (1);
	this->_contact[this->i].set_nickname(buff);
	buff = this->writeAdd("PHONE NUMBER");
	if (buff == "")
		return (1);
	this->_contact[this->i].set_phone_number(buff);
	buff = this->writeAdd("DARKEST SECRET");
	if (buff == "")
		return (1);
	this->_contact[this->i].set_darkest_secret(buff);
	this->_contact[this->i].set_id(this->i + 1);
	this->i = (this->i + 1) % 8;
	this->len += this->len < 8;
	return (0);
}

void	PhoneBook::write_thing( std::string const thing ) {

	if (thing.length() > 10)
	{
		for (int k = 0; k < 9; ++k)
			std::cout << thing[k];
		std::cout << ".";
	}
	else
	{
		for (int k = 0; k < 10 - (int)thing.length(); ++k)
			std::cout << " ";
		for (int k = 0; k < (int)thing.length(); ++k)
			std::cout << thing[k];
	}
	std::cout << "|";
}

void	PhoneBook::write_id( int id )
{
	std::cout << "FIRST NAME : " << this->_contact[id - 1].get_first_name() << std::endl;
	std::cout << "LAST NAME : " << this->_contact[id - 1].get_last_name() << std::endl;
	std::cout << "NICKNAME : " << this->_contact[id - 1].get_nickname() << std::endl;
	std::cout << "PHONE NUMBER : " << this->_contact[id - 1].get_phone_number() << std::endl;
	std::cout << "DARKEST SECRET : " << this->_contact[id - 1].get_darkest_secret() << std::endl << std::endl;
}

int PhoneBook::stringToInt(const std::string& str) {
    std::stringstream ss(str);
    int intValue = 0;
    ss >> intValue;

    return intValue;
}

int	PhoneBook::Search( void ) {

	std::string buff;
	int			buff_id = 0;

	if (this->len == 0)
	{
		std::cout << "YOU DON'T HAVE ANY CONTACT YET" << std::endl;
		return (0);
	}
	std::cout << std::endl << "|     INDEX|    F_NAME|    L_NAME|  NICKNAME|" << std::endl << "|          |          |          |          |" << std::endl;
	for (int j = 0 ; j < this->len ; ++j)
	{
		std::cout << "|         " << this->_contact[j].get_id() << "|";
		this->write_thing(this->_contact[j].get_first_name());
		this->write_thing(this->_contact[j].get_last_name());
		this->write_thing(this->_contact[j].get_nickname());
		std::cout << std::endl;
	}
	std::cout << std::endl << "ENTER AN ID TO SEE MORE DETAILS OR PRESS ENTER TO CONTINUE : ";
	std::getline(std::cin, buff);
	if (buff.empty())
		return (0);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return (1);
	}
	buff_id = this->stringToInt(buff);
	while (buff_id < 1 || buff_id > 8)
	{
		std::cout << "ENTER A VALID ID (1-8) OR PRESS ENTER TO CONTINUE : ";
		std::getline(std::cin, buff);
		if (buff.empty())
			return (0);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
		buff_id = this->stringToInt(buff);
	}
	if (this->_contact[buff_id - 1].get_first_name() != "")
		this->write_id(buff_id);
	else
		std::cout << "THIS ID DOESN'T CORRESPOND TO A CONTACT" << std::endl;
	return (0);
}