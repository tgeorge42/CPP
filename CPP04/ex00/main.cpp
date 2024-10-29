// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Dog*	dog = new Dog();
	const Dog	dog2 ( *dog );
	// const Cat*	cat = new Animal();
	// const Cat*	cat = new Dog();
	const Cat*	cat = new Cat();
	const Cat	cat2 = *cat;

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "dog sound : ";
	dog->makeSound();
	std::cout << "dog2 sound : ";
	dog2.makeSound();
	std::cout << "cat sound : ";
	cat->makeSound();
	std::cout << "cat2 sound : ";
	cat2.makeSound();
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	delete dog;
	delete cat;
	std::cout << std::endl;
	std::cout << std::endl;
	const WrongAnimal*	weird = new WrongAnimal();
	const WrongAnimal*	weirdcat = new WrongCat();
	std::cout << std::endl;
	std::cout << weird->getType() << " " << std::endl;
	std::cout << weirdcat->getType() << " " << std::endl;
	weird->makeSound(); //will output the cat sound!
	weirdcat->makeSound();
	((WrongCat *)weirdcat)->makeSound();
	std::cout << std::endl;
	delete weird;
	delete weirdcat;

	return 0;
}