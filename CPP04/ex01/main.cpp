// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal*		zoo[4];

	for (int i = 0 ; i < 2 ; i++)
		zoo[i] = new Cat();
	for (int i = 2 ; i < 4 ; i++)
		zoo[i] = new Dog();
	std::cout << std::endl;

	zoo[0]->makeSound();
	zoo[2]->makeSound();
	std::cout << "idea 0 of the cat zoo[0] : " << ((Cat *)zoo[0])->getIdea(0) << std::endl;
	((Cat *)zoo[0])->setIdea(0, "This dog is annoying");
	std::cout << "idea 0 of the cat zoo[0] : " << ((Cat *)zoo[0])->getIdea(0) << std::endl;
	std::cout << "idea 0 of the cat zoo[0] : " << ((Cat *)zoo[0])->getIdea(200) << std::endl;
	std::cout << std::endl;



	for (int i = 0 ; i < 4 ; i++)
		delete zoo[i];
	std::cout << std::endl;

	Cat*	cat1 = new Cat();
	cat1->setIdea(0, "I want to sleep ...");
	Cat* cat2 = new Cat(*cat1);
	std::cout << std::endl;

	delete cat1;
	std::cout << std::endl;

	std::cout << cat2->getIdea(0) << std::endl << std::endl;
	delete cat2;
	std::cout << std::endl;

	Dog basic;
	Dog tmp = basic;
	std::cout << std::endl;

	basic.setIdea(0, "MANGER");
	std::cout << "basic.getIdea(0): " << basic.getIdea(0) << std::endl;
	std::cout << "tmp.getIdea(0): " << tmp.getIdea(0) << std::endl;

	return 0;
}