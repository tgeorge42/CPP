#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat* henry = new Bureaucrat("Henry", 60);
	Bureaucrat* jacob = new Bureaucrat("Jacob", 24);
	Form *b42 = new Form("b42", 40, 80);

	std::cout << *b42 << std::endl;
	henry->signForm(*b42);
	std::cout << *b42 << std::endl;
	jacob->signForm(*b42);
	std::cout << *b42 << std::endl;

	delete b42;
	delete henry;
	delete jacob;
}
