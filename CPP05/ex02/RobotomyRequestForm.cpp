#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", (std::string &)("undefined"), 72, 45)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{
	return;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
{
	(void)copy;
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm & copyOp)
{
	(void)copyOp;
	return (*this);
}

void	RobotomyRequestForm::validExecute(Bureaucrat const & executor) const
{
	(void)executor;
	int randomNumber = std::rand();
	if (randomNumber % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy on " << this->getTarget() << " failed" << std::endl;
}

