#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:

		Intern();
		virtual ~Intern();
		Intern(const Intern& copy);
		Intern &operator=(const Intern & copyOp);
		AForm *makeForm(std::string form, std::string target);
		AForm *createShrubberyForm(std::string target);
		AForm *createRobotomyForm(std::string target);
		AForm *createPresidentialForm(std::string target);

		class InvalidForm : public std::exception
		{
			public :

				virtual const char * what() const throw();
		};
};

#endif