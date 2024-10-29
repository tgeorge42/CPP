#include "Array.hpp"

int		main(void)
{
    try 
	{
        // Test de la classe Array avec des entiers
        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 10;
        }
		std::cout << "Size of intArray: " << intArray.size() << std::endl;
		std::cout << "" << std::endl;
		
        std::cout << "Printing intArray:" << std::endl;
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " ";
        }

	    Array<int> emptyArray;
		try 
		{
        	// Test de la création d'un Array vide
        	std::cout << std::endl << "\nCreating an empty Array:" << std::endl;
	
        	// Affichage de la taille de l'Array vide
			// Test de l'exception pour size NULL
        	std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;
		}
		catch (const Array<int>::EmptySize &e)
		{
			std::cerr << "Caught Exception : " << e.what() << std::endl;
		}
		try
		{
        	// Test de l'exception pour un index hors limites
        	std::cout << "\nTrying to access out-of-bounds element:" << std::endl;
        	std::cout << intArray[10] << std::endl; 
		}
		catch(const Array<int>::WrongIndex &e)
		{
			std::cerr << "Caught Exception : " << e.what() <<std::endl;
		}
		std::cout << "" << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}

    return (0);
}

