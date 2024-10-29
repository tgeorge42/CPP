#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:

		std::string const 	_name;
		int					_grade;

	public:

		Bureaucrat();
		Bureaucrat(std::string const & type, int grade);
		virtual ~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat &operator=(const Bureaucrat & copyOp);

		std::string const & getName() const;
		int const & getGrade() const;
		void	upGrade( void );
		void	downGrade( void );
		void	signForm( AForm & form );
		void	executeForm(AForm const & form) const;

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

std::ostream & operator<<( std::ostream & out, Bureaucrat const & rhs );

#endif