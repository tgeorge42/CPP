#include <iostream>
#include <fstream>

int replace(char **av)
{
	std::string buff;
	if (((std::string)av[2]).empty())
		return (std::cout << "You need to enter a non empty parameter." << std::endl, 1);
	std::ifstream ifs(av[1]);
	ifs.seekg(0, std::ios::end);
	if (ifs.tellg() == 0)
	{
		ifs.close();
		return (std::cout << "File " << av[1] << " is empty." << std::endl, 1);
	}
	else
		ifs.seekg(0, std::ios::beg);
	if (!ifs.is_open())
		return (std::cout << "File " << av[1] << " couldn't open properly." << std::endl, 1);
	std::getline(ifs, buff, '\0');
	std::string outfile = (std::string)av[1] + ".replace";
	std::ofstream ofs(outfile.c_str());
	if (!ofs.is_open())
		return (std::cout << "File " << av[1] << ".replace" << " couldn't open properly." << std::endl, 1);
	if ((std::string)av[2] != (std::string)av[3])\
	{
		std::size_t posLecture = 0;
		while ((posLecture = buff.find(av[2])) != std::string::npos)
		{
			buff.erase(posLecture, ((std::string)av[2]).length());
			buff.insert(posLecture, av[3]);
		}
	}
	ofs << buff;
	ifs.close();
	ofs.close();
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "Wrong number of parameters." << std::endl, 1);
	if (replace(av) == 1)
		return (1);
	return (0);
}
