#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:

		std::string const 	_name;
		std::string			_target;
		bool				_signed;
		int	const			_signgrade;
		int	const			_execgrade;

	public:

		typedef void (AForm::*ActionPtr)();
		AForm();
		AForm(std::string const & name, std::string & _target, int signgrade, int execgrade);
		virtual ~AForm();
		AForm(const AForm& copy);
		AForm &operator=(const AForm & copyOp);

		std::string const & getName() const;
		int const & getSignGrade() const;
		int const & getExecGrade() const;
		bool const & getSigned() const;
		std::string const & getTarget() const;
		void	beSigned( const Bureaucrat& bureaucrat );
		bool	execute(Bureaucrat const & executor) const;
		virtual void	validExecute(Bureaucrat const & executor) const = 0;

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
};

std::ostream & operator<<( std::ostream & out, AForm const & rhs );

#endif