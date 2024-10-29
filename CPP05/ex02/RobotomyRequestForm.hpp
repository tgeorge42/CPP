#ifndef ROBOTOMYREQUESTFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm & copyOp);

		virtual void	validExecute(Bureaucrat const & executor) const;

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

std::ostream & operator<<( std::ostream & out, RobotomyRequestForm const & rhs );

#endif