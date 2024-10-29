#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <algorithm>
class Span
{
	private :

		std::list<int>	_my_list;
		unsigned int	_nb;
		unsigned int	_current_nb;

	public :

		Span();
		Span(unsigned int nb);
		Span(const Span & copy);
		~Span();
		Span	&operator=(const Span & copyOp);

		void			addNumber( int value );
		void			addNumber(std::list<int>::iterator begin, std::list<int>::iterator end);
		unsigned int	shortestSpan( void );
		unsigned int	longestSpan( void );


		class ListFull : public std::exception
		{
			public :

				virtual const char *what() const throw();
		};
		class DistanceFailed : public std::exception
		{
			public :
			
				virtual const char *what() const throw();
		};
};

#endif