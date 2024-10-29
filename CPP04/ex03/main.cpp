// #include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main( void )
{
	AMateria *icespell = new Ice();
	AMateria *icespell2 = new Ice();
	AMateria *curespell = new Cure();
	ICharacter *gandalf = new Character("Gandalf");
	ICharacter *saroumane = new Character("Saroumane");
	IMateriaSource *source = new MateriaSource();
	source->learnMateria(icespell);
	std::cout << std::endl;

	std::cout << "BASIC TESTS : " << std::endl;
	gandalf->equip(icespell);
	gandalf->equip(curespell);
	gandalf->unequip(0);
	gandalf->unequip(1);
	// gandalf->equip(icespell);
	gandalf->equip(source->createMateria("ice"));
	std::cout << gandalf->getName() << " : ";
	gandalf->use(0, *saroumane);
	std::cout << std::endl;

	std::cout << "COPY CONSTRUCTOR : " << std::endl;
	ICharacter *gandalfleblanc = new Character(dynamic_cast<Character &>(*gandalf));
	std::cout << gandalfleblanc->getName() << " : ";
	gandalfleblanc->use(0, *saroumane);
	std::cout << gandalfleblanc->getName() << " : ";
	gandalf->use(0, *saroumane);
	std::cout << std::endl;

	std::cout << "OPERATOR = : " << std::endl;
	ICharacter *galadriel = new Character("Galadriel");
	galadriel->equip(icespell2);
	std::cout << galadriel->getName() << " : ";
	galadriel->use(0, *gandalf);
	saroumane->equip(curespell);
	dynamic_cast<Character &>(*galadriel) = dynamic_cast<Character &>(*saroumane);
	std::cout << galadriel->getName() << " : ";
	galadriel->use(0, *gandalf);
	std::cout << saroumane->getName() << " : ";
	saroumane->use(0, *gandalf);
	std::cout << std::endl;
	std::cout << std::endl;

	delete gandalf;
	delete saroumane;
	delete galadriel;
	delete gandalfleblanc;
	delete source;

	std::cout << std::endl;
	std::cout << "SUBJECT TESTS :" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* patrick = new Character("patrick");
	std::cout << std::endl;
	me->use(0, *patrick);
	me->use(1, *patrick);
	std::cout << std::endl;
	delete patrick;
	delete me;
	delete src;
	std::cout << std::endl;


	std::cout << "OTHER TESTS :" << std::endl;
	IMateriaSource* src1 = new MateriaSource();
    IMateriaSource* src2 = new MateriaSource();
    IMateriaSource* src_test = new MateriaSource();
    //std::cout << "//    Learn materia part" << std::endl;
    src1->learnMateria(new Ice());
    src1->learnMateria(new Cure());
    src1->learnMateria(new Ice());
    src1->learnMateria(new Cure());

    src_test->learnMateria(new Cure());
    src2->learnMateria(new Cure());
    src2->learnMateria(new Ice());
    //std::cout << "//    Finish try to learn materia\n\n" << std::endl;

    //std::cout << "//    Create materia part" << std::endl;
    AMateria* Jimmy_ice_staff = src1->createMateria("ice");
    AMateria* Jimmy_ice_staff_2 = src1->createMateria("ice");
    AMateria* Jimmy_cure_staff = src1->createMateria("cure");
    AMateria* Jimmy_cure_staff_2 = src1->createMateria("cure");
    //std::cout << "\n//    Overflow test create" << std::endl;
    AMateria* Jimmy_overflow_test_staff = src_test->createMateria("cure");
    //std::cout << "//    Overflow test finish\n" << std::endl;
    AMateria* Bob_cure_staff = src2->createMateria("cure");
    //std::cout << "//    Finish try to create materia\n\n" << std::endl;

    //std::cout << "//    Create characters part" << std::endl;
    ICharacter* Jimmy = new Character("Jimmy");
    ICharacter* bob = new Character("bob");
    //ICharacter* Gandalf = new Character("gandalf");
    //*Gandalf = *Jimmy;
    //std::cout << "//    Finish create characters part\n\n" << std::endl;
    Jimmy->equip(Jimmy_ice_staff);
    Jimmy->equip(Jimmy_ice_staff_2);
    Jimmy->equip(Jimmy_cure_staff);
    Jimmy->equip(Jimmy_cure_staff_2);
    Jimmy->equip(Jimmy_overflow_test_staff);

    bob->equip(Bob_cure_staff);

    Jimmy->use(1, *bob);
    Jimmy->use(2, *bob);

    delete bob;
    delete Jimmy;
    delete src1;
    delete src2;
    delete src_test;
	return (0);
}