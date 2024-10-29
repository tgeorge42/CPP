#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat* marc = new Bureaucrat("Marc", 160);
	Bureaucrat* philippe = new Bureaucrat("Philippe", 148);

	std::cout << *marc << std::endl;
	marc->downGrade();

	std::cout << *philippe << std::endl;
	philippe->downGrade();
	philippe->downGrade();
	philippe->downGrade();
	std::cout << *philippe << std::endl;
	philippe->upGrade();
	std::cout << *philippe << std::endl;

	delete marc;
	delete philippe;
}
