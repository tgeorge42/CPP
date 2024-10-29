#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name ( "undefined" ), _grade ( 151 )
{
	// std::cout << "Default Bureaucrat constructor called" << std::endl;

	return ;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name( name ), _grade( 151 )
{
	// std::cout << "String type Bureaucrat constructor called" << std::endl;
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

Bureaucrat::Bureaucrat( const Bureaucrat& copy)
{
	// std::cout << "Copy Bureaucrat constructor called" << std::endl;
	(void)copy;
	this->_grade = copy.getGrade();

	return ;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Destructor Bureaucrat Called" << std::endl;

    return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat & copyOp)
{
	// std::cout << "Copy assignment Bureaucrat operator called" << std::endl;
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

void	Bureaucrat::signForm( AForm & form )
{
	form.beSigned(*this);
	try
	{
		if (!form.getSigned())
			throw std::exception();
		else
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because grade is too low" << std::endl;
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

void	Bureaucrat::executeForm(AForm const & form) const
{

	if (form.execute(*this) == 0)
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
}
