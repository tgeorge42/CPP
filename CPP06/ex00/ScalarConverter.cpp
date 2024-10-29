#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter & copy)
{
	*this = copy;

	return ;
}

ScalarConverter::~ScalarConverter()
{
	return ;
}

	
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter & copyOp)
{
	(void)copyOp;

	return (*this);
}

bool	isChar(std::string str)
{
	if (str.length() == 1 && static_cast<int>((str.c_str())[0]) > 31 && static_cast<int>((str.c_str())[0]) < 127)
		return (true);
	return (false);
}

long	ft_stol(std::string str)
{
	const char	*tab = str.c_str();
	int			i = 0;
	int			len = 0;
	long		atol = 0;
	int			sign = 1;

	while (tab[i])
	{
		if ((static_cast<int>(tab[i]) < 47 || static_cast<int>(tab[i]) > 58) && (static_cast<int>(tab[i]) != '+') && static_cast<int>(tab[i]) != '-')
			return (2147483648);
		i++;
	}
	i = 0;
	if (tab[i] == '+' || tab[i] == '-')
	{
		if (tab[i] == '-')
			sign = -1;
		i++;
		len++;
	}
	while (tab[i] == '0')
		i++;
	while (static_cast<int>(tab[i]) > 47 && static_cast<int>(tab[i]) < 58)
	{
		atol = atol * 10 + static_cast<int>(tab[i]) - 48;
		i++;
		len++;
	}
	if (len > 11 || static_cast<size_t>(i) != str.length())
		return (2147483648);
	return (sign * atol);
}

bool	isInt(std::string str)
{
	if (ft_stol(str) < -2147483648 || ft_stol(str) > 2147483647)
		return (false);
	return (true);
}

bool	isFloat(std::string str)
{

	size_t strLength = str.length();
	size_t i;
	for (i = 0; i < strLength; i++)
	{
		str[i] = std::tolower(str[i]);
	}
	
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	i = 0;
	bool decimalPoint = false;
	if (str[i] == '+' || str[i] == '-')
		i++;
 	while (isdigit(str[i]) || (str[i] == '.' && !decimalPoint)) 
	{
        if (str[i] == '.')
            decimalPoint = true;
        i++;
    }
    return (str[i] == 'f' && i + 1 == str.length() && decimalPoint == true);
}

bool	isDouble(std::string str)
{
	size_t strLength = str.length();
	size_t i;
	for (i = 0; i < strLength; i++)
	{
		str[i] = std::tolower(str[i]);
	}
	
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
			
	i = 0;
	bool decimalPoint = false;
	if (str[i] == '+' || str[i] == '-')
		i++;
 	while (isdigit(str[i]) || (str[i] == '.' && !decimalPoint)) 
	{
        if (str[i] == '.')
            decimalPoint = true;
        i++;
    }
	return (i == str.length() && decimalPoint == true);
}

void printChar(char c)
{
	std::cout << "char : '" << c << "'" << std::endl;
}

void printInt(int integer)
{	
	std::cout << "int : " << integer << std::endl;
}

void printFloat(float f)
{	
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void printDouble(double d)
{	
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	print_error(const std::string &type)
{
	std::cout << type << " : impossible" << std::endl;
}

void	convertChar(const std::string &str)
{
	char c = str[0];
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void	convertInt(const std::string &str)
{
	int integer = static_cast<int>(strtod(str.c_str(), NULL));

	if (integer >= (INT_MIN + 1) && integer <= INT_MAX)
	{
		if ((integer < 127 && integer >= -128) && isprint(integer))
		{
			printChar(integer);
		}
		else if (integer > 255 || integer < 0)
			print_error("char");
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
		printInt(static_cast<int>(integer));
		printFloat(static_cast<float>(integer));
		printDouble(static_cast<double>(integer));
	}
	else
	{
		print_error("char OVERFLOW");
		print_error("int OVERFLOW");
		print_error("float OVERFLOW");
		print_error("double OVERFLOW");
	}
}

void	convertFloat(const std::string &str)
{
	double	d = strtod(str.c_str(), NULL);
	float	f = static_cast<float>(d);

	if (std::isinf(f) || std::isnan(f))
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;	
	}
	else
	{
		if ((static_cast<int>(f) < 127 && static_cast<int>(f) >= -128) && isprint(static_cast<int>(f)))
    		printChar(static_cast<char>(f));
		else if (static_cast<int>(f) > 255 || static_cast<int>(f) < 0)
			print_error("char");
		else
			std::cout << "char: Non displayable" << std::endl;
		if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
			print_error("int");
		else
		{
			if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
				print_error("int");
			else
				printInt(static_cast<int>(d));
		}
    	printFloat(f);
    	printDouble(static_cast<double>(f));
	}
}

void	convertDouble(const std::string &str)
{
	double d = strtod(str.c_str(), NULL);

	if (std::isinf(static_cast<float>(d)) || std::isnan(static_cast<float>(d)))
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float: " << str + 'f' << std::endl;
		std::cout << "double: " << str << std::endl;
	}
	else
	{	
		if ((static_cast<int>(d) < 127 && static_cast<int>(d) >= -128) && isprint(static_cast<int>(d)))
    		printChar(static_cast<char>(d));
		else if (static_cast<int>(d) > 255 || static_cast<int>(d) < 0)
			print_error("char");
		else
			std::cout << "char: Non displayable" << std::endl;
		if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
			print_error("int");
		else
    		printInt(static_cast<int>(d));
    	printFloat(static_cast<float>(d));
    	printDouble(d);
	}
}

void	ScalarConverter::convert(const std::string &str)
{
	bool(*type[4])(std::string) = {isChar, isInt, isFloat, isDouble};
	void(*ptr[4])(const std::string &) = {&convertChar, &convertInt, &convertFloat, &convertDouble};

	for (int i = 0; i < 4; i++)
	{
		if (type[i](str))
		{	
			ptr[i](str);
			break;
		}
	}
}