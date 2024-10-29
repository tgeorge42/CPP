#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

		std::string const 	_name;
		bool				_signed;
		int	const			_signgrade;
		int	const			_execgrade;

	public:

		Form();
		Form(std::string const & type, int signgrade, int execgrade);
		~Form();
		Form(const Form& copy);
		Form &operator=(const Form &);

		std::string const & getName() const;
		int const & getSignGrade() const;
		int const & getExecGrade() const;
		bool const & getSigned() const;
		void	beSigned( const Bureaucrat& bureaucrat );

		class GradeTooHighException
		{
			public:
			
				virtual const char* what() const throw();
		};
		class GradeTooLowException
		{
			public:
			
				virtual const char* what() const throw();
		};
		class InvalidGradeException
		{
			public:
			
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<( std::ostream & out, Form const & rhs );

#endif