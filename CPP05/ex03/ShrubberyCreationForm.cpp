#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", (std::string &)("undefined"), 145, 137)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{
	(void)copy;
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm & copyOp)
{
	(void)copyOp;
	return (*this);
}

void	ShrubberyCreationForm::validExecute(Bureaucrat const & executor) const
{
	(void)executor;
	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream ofs(filename.c_str());
	if (!ofs.is_open())
	{
		std::cout << filename << " couldn't open properly." << std::endl;
		return;
	}
	else
	{
		ofs << "              _{\\ _{\\{\\/}/}/}__" << std::endl
			<< "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl
			<< "            {/{/\\}{/{/\\}(_)\\}{/{/\\}_" << std::endl
			<< "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\}/\\}" << std::endl
			<< "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl
			<< "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl
			<< "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl
			<< "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl
			<< "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl
			<< "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl
			<< "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl
			<< "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl
			<< "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl
			<< "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl
			<< "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl
			<< "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl
			<< "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl
			<< "              {){/ {\\/}{\\/} \\}\\}" << std::endl
			<< "                   \\.-'.-/" << std::endl
			<< "          __...--- |'-.-'| --...__" << std::endl
			<< "   _...--'   .-'   |'-.-'|  ' -.  ''--..__" << std::endl
			<< " -'    ' .  . '    |.'-._| '  . .  '   " << std::endl
			<< " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl
			<< "          ' ..     |'-_.-|" << std::endl
			<< "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl
			<< "              .'   |'- .-|   '." << std::endl
			<< "  ..-'   ' .  '.   `-._.-'   .'  '  - ." << std::endl
			<< "   .-' '        '-._______.-'     '  ." << std::endl
			<< "        .      ~," << std::endl;
		std::cout << "Thank you for planting this tree" << std::endl;
	}
	ofs.close();
}
