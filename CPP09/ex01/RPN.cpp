#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN & copy)
{
	(void)copy;
}

RPN::~RPN()
{

}

RPN & RPN::operator=(const RPN & copyOp)
{
	(void)copyOp;
	return (*this);
}

bool	is_digit(char c)
{
	if (c < 48 || c > 57)
		return (false);
	// this->_nb_int++;
	return (true);
}

bool	is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
	{
		// this->_nb_op++;
		return (true);
	}
	return (false);
}

bool	skip_spaces(char *str, int *i)
{
	int j = *i;

	while (str && str[*i] && str[*i] == ' ')
		(*i)++;
	if (j != *i || str[j] == '\0')
		return (true);
	else
		return (false);
}

void	fast_skip_spaces(char *str, int *i)
{
	while (str && str[*i] && str[*i] == ' ')
		(*i)++;
}

void	parsing(char *str)
{
	int	i = 0;
	int	nb_int = 0;
	int nb_op = 0;

	fast_skip_spaces(str, &i);
	if (!is_digit(str[i]))
		throw(static_cast<std::string>("First two inputs must be digits"));
	i++;
	if (!skip_spaces(str, &i))
		throw(static_cast<std::string>("Need space between inputs"));
	if (!is_digit(str[i]))
		throw(static_cast<std::string>("First two inputs must be digits"));
	i++;
	nb_int = 2;
	if (!skip_spaces(str, &i))
		throw(static_cast<std::string>("Need space between inputs"));
	while (str && str[i])
	{
		if (is_digit(str[i]))
			nb_int++;
		else
		{
			if (is_operator(str[i]))
				nb_op++;
			else
				throw(static_cast<std::string>("Invalid syntax"));
		}
		i++;
		if (!skip_spaces(str, &i))
			throw(static_cast<std::string>("Need space between inputs"));
	}
	if (nb_op != nb_int - 1)
		throw(static_cast<std::string>("Invalid syntax (operator number doesn't match int number)"));
	i = 0;
	while (str[i])
		i++;
	i--;
	while (i > 0 && str[i] == ' ')
		i--;
	if (!is_operator(str[i]))
		throw(static_cast<std::string>("Need an operator at the end"));
	// std::cout << "Parsing ok" << std::endl;
}


void	check_overflow(int a, int b, char c)
{
	switch (c)
	{
		case ('+') :
		{
			if (static_cast<long>(a) + static_cast<long>(b) > 2147483647
				|| static_cast<long>(a) + static_cast<long>(b) < -2147483648)
				throw(static_cast<std::string>("Int overflow"));
			break;
		}
		case ('-') :
		{
			if (static_cast<long>(a) - static_cast<long>(b) > 2147483647
				|| static_cast<long>(a) - static_cast<long>(b) < -2147483648)
				throw(static_cast<std::string>("Int overflow"));
			break;
		}
		case ('*') :
		{
			if (static_cast<long>(a) * static_cast<long>(b) > 2147483647
				|| static_cast<long>(a) * static_cast<long>(b) < -2147483648)
				throw(static_cast<std::string>("Int overflow"));
			break;
		}
	}
}

void	top_pop(int *a, int *b, std::stack<int> *my_stack, char c)
{
	*a = my_stack->top();
	my_stack->pop();
	*b = my_stack->top();
	my_stack->pop();
	check_overflow(*a, *b, c);
}

void	calculate(char c, std::stack<int> *my_stack)
{
	int a = 0;
	int b = 0;
	
	top_pop(&a, &b, my_stack, c);
	switch(c)
	{	
		case ('+') :
		{
			my_stack->push(b + a);
			break;
		}
		case ('-') :
		{
			my_stack->push(b - a);
			break;
		}
		case ('*') :
		{
			my_stack->push(b * a);
			break;
		}
		case ('/') :
		{
			if (a == 0)
				throw(static_cast<std::string>("Division by zero not allowed"));
			my_stack->push(b / a);
			break;
		}
	}
}

void	RPN::reverse_polish(char *str)
{
	std::stack<int> my_stack;
	int	i = 0;

	if (str)
		parsing(str);
	fast_skip_spaces(str, &i);
	while (str && str[i])
	{
		if (is_digit(str[i]))
			my_stack.push(static_cast<int>(str[i] - 48));
		else if (is_operator(str[i]))
			calculate(str[i], &my_stack);
		i++;
		fast_skip_spaces(str, &i);
	}
	std::cout << my_stack.top() << std::endl;
}
