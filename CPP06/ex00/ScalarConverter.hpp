#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip> // std::scientific
# include <string>
# include <limits.h> // INT_MIN/MAX
# include <cmath> // isnan // isinf
# include <stdio.h> // NULL
# include <stdlib.h> //strtof // atoi


class ScalarConverter
{
	private :

		ScalarConverter();
		ScalarConverter(const ScalarConverter & copy);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter & copyOp);

	public :

		static void	convert(const std::string &literal);
};

long	ft_stol(std::string str);

bool	isChar(std::string str);
bool	isInt(std::string str);
bool	isFloat(std::string str);
bool	isDouble(std::string str);

void	printChar(char c);
void	printInt(int integer);
void	printFloat(float f);
void	printDouble(double d);
void	print_error(const std::string &type);

void	convertChar(const std::string &str);
void	convertInt(const std::string &str);
void	convertFloat(const std::string &str);
void	convertDouble(const std::string &str);

#endif