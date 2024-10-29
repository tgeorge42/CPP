#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::srand(std::time(0));
	Intern	newbie;
	AForm	*presid;
	AForm	*invalid = NULL;
	Bureaucrat* arthur = new Bureaucrat("Arthur", 4);
	try
	{

		presid = newbie.makeForm("presidential request", "herve");
		arthur->signForm(*presid);
		arthur->executeForm(*presid);
		std::cout << std::endl;
		invalid = newbie.makeForm("invalid test", "wrong target");
		arthur->signForm(*invalid);
		arthur->executeForm(*invalid);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete arthur;
	delete presid;
	delete invalid;
}
