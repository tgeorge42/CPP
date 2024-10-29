#include "Span.hpp"

void	print_content(int i)
{
	std::cout << i << " ";
}

int	main( void )
{
	try
	{
		unsigned int nb = 10;
		Span	test_span(nb);

		std::cout << "Basic tests : " << std::endl << "Numbers in the span : ";
		for (unsigned int i = 0 ; i < nb ; i++)
		{
			test_span.addNumber((i % 3 == 0 ? i * 3 + 10 : i * 2 + 5));
			std::cout << (i % 3 == 0 ? i * 3 + 10 : i * 2 + 5) << " ";
		}
		std::cout << std::endl;
		std::cout << "longest span : " << test_span.longestSpan() << std::endl;
		std::cout << "shortest span : " << test_span.shortestSpan() << std::endl;

		Span	empty_span;
		empty_span.longestSpan();
	}
	catch(Span::DistanceFailed& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "Iterator range tests : " << std::endl;

		Span test_span2 = Span(5);
		std::list<int> numbersToAdd;
		numbersToAdd.push_back(6);
		numbersToAdd.push_back(3);
		numbersToAdd.push_back(9);
		numbersToAdd.push_back(17);
		numbersToAdd.push_back(23);
		test_span2.addNumber(numbersToAdd.begin(), numbersToAdd.end());
		
		std::cout << test_span2.shortestSpan() << std::endl;
		std::cout << test_span2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "Trying to put too much numbers : " << std::endl;
		unsigned int nb = 10;
		Span	short_span;
		for (unsigned int i = 0 ; i < nb ; i++)
			short_span.addNumber((i % 3 == 0 ? i * 3 + 10 : i * 2 + 5));
	}
	catch(Span::ListFull& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "Tests from the subject : " << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
