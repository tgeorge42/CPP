#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class	RPN
{
	private :

		RPN();
		~RPN();
		RPN(const RPN & copy);
		RPN & operator=(const RPN & copyOp);

	public :

		static void	reverse_polish(char *str);
};

#endif