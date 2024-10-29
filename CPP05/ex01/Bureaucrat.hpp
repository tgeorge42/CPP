#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:

		std::string const 	_name;
		int					_grade;

	public:

		Bureaucrat();
		Bureaucrat(std::string const & type, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat &operator=(const Bureaucrat &);

		std::string const & getName() const;
		int const & 		getGrade() const;
		void				upGrade( void );
		void				downGrade( void );
		void				signForm( Form & form );

		class GradeTooHighException : public std::exception
		{
			public:
			
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
			
				virtual const char* what() const throw();
		};

		class InvalidGradeException : public std::exception
		{
			public:
			
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<( std::ostream & out, Bureaucrat const & rhs );

#endif