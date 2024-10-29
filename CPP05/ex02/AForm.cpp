#include "AForm.hpp"

AForm::AForm() : _name ( "undefined" ), _signed( false ), _signgrade ( 0 ), _execgrade( 0 )
{
	// std::cout << "Default AForm constructor called" << std::endl;

	return ;
}

AForm::AForm(std::string const & name, std::string & target, int signgrade, int execgrade) : _name( name ), _target( target ), _signed( false ), _signgrade( signgrade ), _execgrade( execgrade )
{
	// std::cout << "String type AForm constructor called" << std::endl;
	try
	{
		if (signgrade <= 0 || execgrade <= 0)
			throw AForm::GradeTooHighException();
		else if (signgrade > 150 || execgrade > 150)
			throw AForm::GradeTooLowException();
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return ;
}

AForm::AForm( const AForm& copy) : _signgrade( copy.getSignGrade() ), _execgrade( copy.getExecGrade() )
{
	// std::cout << "Copy AForm constructor called" << std::endl;
	this->_signed = copy.getSigned();

	return ;
}

AForm::~AForm()
{
	// std::cout << "Destructor AForm Called" << std::endl;

    return ;
}

AForm &AForm::operator=(const AForm & copyOp)
{
	// std::cout << "Copy assignment AForm operator called" << std::endl;
	this->_signed = copyOp.getSigned();

	return (*this);
}

std::string const &	AForm::getName( void ) const
{
	return ( this->_name );
}

int const &	AForm::getSignGrade( void ) const
{
	return ( this->_signgrade );
}

int const &	AForm::getExecGrade( void ) const
{
	return ( this->_execgrade );
}

bool const &	AForm::getSigned( void ) const
{
	return ( this->_signed );
}

std::string const & AForm::getTarget() const
{
	return ( this->_target );
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Exception Error : Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Exception Error : Grade is too low");
}

void	AForm::beSigned( const Bureaucrat& bureaucrat )
{
	try
	{
		if (bureaucrat.getGrade() > this->getSignGrade())
			throw AForm::GradeTooLowException();
		else
			this->_signed = true;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream& out, const AForm& rhs) 
{
    out << "Form " << rhs.getName() << ", needs a grade of " << rhs.getSignGrade()
		<< " to be signed and a grade of " << rhs.getExecGrade() << " to be executed. "
		<< ((rhs.getSigned() == 0) ? "This form isn't signed yet." : "This form is already signed.");
    return (out);
}

bool	AForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if ( executor.getGrade() <= 0 || executor.getGrade() > 150 || this->_execgrade <= 0 || this->_execgrade > 150)
			throw Bureaucrat::InvalidGradeException();
		if ( this->_signed == true && executor.getGrade() <= this->getExecGrade() )
		{
			validExecute( executor );
			return (0);
		}
		if (this->_signed == false )
			throw std::exception();
		if ( executor.getGrade() > this->getExecGrade() )
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const Bureaucrat::InvalidGradeException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "This form isn't signed yet" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (1);
}
