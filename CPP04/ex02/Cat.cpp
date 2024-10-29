#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->_brain = new Brain();
	this->_type = "Cat";
	return ;
}

Cat::Cat( const Cat& copy )
{
	std::cout << "Copy Cat constructor called" << std::endl;
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
}

Cat::~Cat()
{
	std::cout << "Destructor Cat Called" << std::endl;
	delete this->_brain;
	
    return ;
}

Cat &Cat::operator=( const Cat & copyOp )
{
	std::cout << "Copy assignment Cat operator called" << std::endl;
	this->_type = copyOp._type;
	delete this->_brain;
	this->_brain = new Brain(*copyOp._brain);
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meoowwww" << std::endl;
	return ;
}

std::string		Cat::getIdea(const int i) const
{
	if (i < 100)
		return this->_brain->getIdea(i);
	else
		return ("Animals are not overthinkers");
}

void		Cat::setIdea(const int i, std::string idea)
{
	this->_brain->setIdea(i, idea);

	return ;
}
