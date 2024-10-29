#include <iostream>
#include <stdio.h>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(int ac, char **av)
{
	// (void)ac;
	(void)av;
	std::string buff = "";
	if (ac != 1)
	{
		std::cout << "DO NOT ENTER ARGUMENTS." << std::endl;
		return (1);
	}
	PhoneBook repertory;
	std::cout << "WELCOME IN YOUR PHONEBOOK" << std::endl;
	while (42)
	{
		std::cout << "TYPE 'ADD' TO ADD A NEW CONTACT, 'SEARCH' TO SEE YOUR CURRENT CONTACTS OR 'EXIT' TO QUIT" << std::endl;
		std::getline(std::cin, buff);
		if (std::cin.eof())
			return (1);
		if (buff == "ADD" && repertory.Add() == 1)
			return (1);
		if (buff == "SEARCH")
			repertory.Search();
		if (buff == "EXIT")
			return (0);
	}
}
