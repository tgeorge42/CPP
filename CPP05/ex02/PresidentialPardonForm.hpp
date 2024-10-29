#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm & copyOp);

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

std::ostream & operator<<( std::ostream & out, PresidentialPardonForm const & rhs );

#endif