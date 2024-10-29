#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm & copyOp);

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

#endif