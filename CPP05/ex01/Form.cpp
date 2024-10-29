#include "Form.hpp"

Form::Form() : _name ( "undefined" ), _signed( false ), _signgrade ( 0 ), _execgrade( 0 )
{
	std::cout << "Default Form constructor called" << std::endl;
	return ;
}

Form::Form(std::string const & name, int signgrade, int execgrade) : _name( name ), _signed( false ), _signgrade( signgrade ), _execgrade( execgrade )
{
	std::cout << "String type Form constructor called" << std::endl;
	try
	{
		if (signgrade <= 0 || execgrade <= 0)
			throw Form::GradeTooHighException();
		else if (signgrade > 150 || execgrade > 150)
			throw Form::GradeTooLowException();
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ;
}

Form::Form( const Form& copy) : _signed( false ), _signgrade( copy.getSignGrade() ), _execgrade( copy.getExecGrade() )
{
	std::cout << "Copy Form constructor called" << std::endl;

	return ;
}

Form::~Form()
{
	std::cout << "Destructor Form Called" << std::endl;

    return ;
}

Form &Form::operator=(const Form & copyOp)
{
	std::cout << "Copy assignment Form operator called" << std::endl;
	(void)copyOp;

	return (*this);
}

std::string const &	Form::getName( void ) const
{
	return ( this->_name );
}

int const &	Form::getSignGrade( void ) const
{
	return ( this->_signgrade );
}

int const &	Form::getExecGrade( void ) const
{
	return ( this->_execgrade );
}

bool const &	Form::getSigned( void ) const
{
	return ( this->_signed );
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Exception Error : Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Exception Error : Grade is too low");
}

const char* Form::InvalidGradeException::what() const throw()
{
	return ("Exception Error : Grade is invalid");
}

void	Form::beSigned( const Bureaucrat& bureaucrat )
{
	try
	{
		if (this->_execgrade > 150 || this->_execgrade <= 0 || this->_signgrade > 150 || this->_signgrade <= 0)
			throw Form::InvalidGradeException();
		if (bureaucrat.getGrade() > this->getSignGrade())
			throw Form::GradeTooLowException();
		else
			this->_signed = true;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const Form::InvalidGradeException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Form& rhs) 
{
    out << "Form " << rhs.getName() << ", needs a grade of " << rhs.getSignGrade()
		<< " to be signed and a grade of " << rhs.getExecGrade() << " to be executed. "
		<< ((rhs.getSigned() == 0) ? "This form isn't signed yet." : "This form is already signed.");
    return (out);
}
