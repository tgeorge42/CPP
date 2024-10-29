#include "Span.hpp"

Span::Span( void ) : _nb( 2 ), _current_nb ( 0 )
{	
	return ;
}

Span::Span( unsigned int nb ) : _nb( nb ), _current_nb ( 0 )
{
	return ;
}

Span::Span( const Span & copy )
{
	(void)copy;
	return ;
}

Span::~Span( void )
{
	return ;
}

Span	&Span::operator=(const Span & copyOp)
{
	(void)copyOp;
	return *this;
}

void	Span::addNumber( int value )
{
	if (this->_current_nb < this->_nb)
	{
		_my_list.push_back(value);
		this->_current_nb++;
	}
	else
		throw Span::ListFull();
}

void	Span::addNumber(std::list<int>::iterator begin, std::list<int>::iterator end)
{

	if (_my_list.size() + std::distance(begin, end) > _nb)
		throw std::runtime_error("Adding these numbers exceeds Span capacity.");
	_my_list.insert(_my_list.end(), begin, end);
	_current_nb += std::distance(begin, end);
}

unsigned int	Span::shortestSpan( void )
{
	unsigned int	shortest;
	std::list<int>::iterator itj;
	std::list<int>::iterator ite;

	if (this->_current_nb > 1)
	{
		shortest = this->longestSpan();
		this->_my_list.sort();
		ite = this->_my_list.end();
		for (std::list<int>::iterator iti = this->_my_list.begin() ; iti != ite ; iti++)
		{
			itj = iti;
			itj++;
			if (static_cast<unsigned int>(abs(*iti - *itj)) < shortest)
				shortest = static_cast<unsigned int>(abs(*iti - *itj));
		}
		return (shortest);
	}
	else
		throw Span::DistanceFailed();
}

unsigned int	Span::longestSpan( void )
{
	std::list<int>::iterator it = this->_my_list.begin();
	std::list<int>::iterator ite = this->_my_list.end();
	if (this->_current_nb > 1)
	{
		return (*std::max_element(it, ite) - *std::min_element(it, ite));
	}
	else
		throw Span::DistanceFailed();
}

const char *Span::ListFull::what() const throw()
{
	return("The span is full");
}

const char *Span::DistanceFailed::what() const throw()
{
	return("Can't calculate the distance");
}