#include "Intern.hpp"

Intern::Intern()
{
	// std::cout << "Default Intern constructor called" << std::endl;

	return ;
}


Intern::Intern( const Intern& copy)
{
	// std::cout << "Copy Intern constructor called" << std::endl;
	(void)copy;
	return ;
}

Intern::~Intern()
{
	// std::cout << "Destructor Intern Called" << std::endl;

    return ;
}

Intern &Intern::operator=(const Intern & copyOp)
{
	// std::cout << "Copy assignment Intern operator called" << std::endl;
	(void)copyOp;
	return (*this);
}

AForm *Intern::createShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
    AForm *(Intern::*ptr[])(std::string target) = {&Intern::createShrubberyForm, &Intern::createRobotomyForm, &Intern::createPresidentialForm};
    std::string array[] = {"shrubbery request", "robotomy request", "presidential request"};
    int i = 0;
    while (i < 3)
    {
        if(form_name == array[i])
        {
            return ((this->*ptr[i])(target));
            break;
        }
        i++;
    }
	throw Intern::InvalidForm();
}

const char *	Intern::InvalidForm::what() const throw()
{
	return("Form is invalid");
}