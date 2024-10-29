#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name ( "undefined" ), _grade ( 0 )
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;

	return ;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name( name ), _grade( 0 )
{
	std::cout << "String type Bureaucrat constructor called" << std::endl;
	try
	{
		if (grade < 0)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy) : _name( copy.getName() ), _grade( copy.getGrade() )
{
	std::cout << "Copy Bureaucrat constructor called" << std::endl;

	return ;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Bureaucrat Called" << std::endl;

    return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat & copyOp)
{
	std::cout << "Copy assignment Bureaucrat operator called" << std::endl;
	this->_grade = copyOp.getGrade();

	return (*this);
}

std::string const &	Bureaucrat::getName( void ) const
{
	return ( this->_name );
}

int const &	Bureaucrat::getGrade( void ) const
{
	return ( this->_grade );
}

void	Bureaucrat::upGrade( void )
{
	try
	{
		if (this->_grade - 1 <= 0)
			throw Bureaucrat::GradeTooHighException();
		else if (this->_grade > 150)
			throw Bureaucrat::InvalidGradeException();
		else
		{
			this->_grade--;
			std::cout << this->getName() << "'s grade has been upgraded to " << this->getGrade() << std::endl;
		}
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const Bureaucrat::InvalidGradeException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::downGrade( void )
{
	try
	{
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (this->_grade <= 0)
			throw Bureaucrat::InvalidGradeException();
		else
		{
			this->_grade++;
			std::cout << this->getName() << "'s grade has been downgraded to " << this->getGrade() << std::endl;
		}
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const Bureaucrat::InvalidGradeException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception Error : Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception Error : Grade is too low");
}

const char* Bureaucrat::InvalidGradeException::what() const throw()
{
	return ("Exception Error : Grade is invalid");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs) 
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return (out);
}
