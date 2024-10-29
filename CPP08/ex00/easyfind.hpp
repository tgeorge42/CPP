#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <map>
# include <vector>
# include <list>
# include <algorithm>

class notFoundException : public std::exception
{
	public :

		virtual const char *what() const throw()
		{
			return("Integer not found in the container");
		}
};

template< typename T >

typename T::iterator	easyfind(T &cont, int to_find)
{
	typename T::iterator it = find(cont.begin(), cont.end(), to_find);
	if (it == cont.end())
		throw notFoundException();
	else
		return (it);
}

#endif