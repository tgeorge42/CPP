#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::srand(std::time(0));
	Bureaucrat* marc = new Bureaucrat("Marc", 160);
	Bureaucrat* henry = new Bureaucrat("Henry", 4);

	AForm* shrub = new ShrubberyCreationForm("Jose");
	AForm* robot = new RobotomyRequestForm("Paul");
	AForm* president = new PresidentialPardonForm("Luc");
	std::cout << std::endl;

	std::cout << *shrub << std::endl;
	std::cout << std::endl;
	henry->signForm(*shrub);
	henry->executeForm(*shrub);
	std::cout << std::endl;
	
	henry->signForm(*robot);
	std::cout << "Marc : " << std::endl;
	marc->executeForm(*robot);
	std::cout << "Henry : " << std::endl;
	henry->executeForm(*robot);
	henry->executeForm(*robot);
	henry->executeForm(*robot);
	std::cout << std::endl;

	henry->signForm(*president);
	henry->executeForm(*president);

	delete henry;
	delete marc;
	delete shrub;
	delete robot;
	delete president;
}
