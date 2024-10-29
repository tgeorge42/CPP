#include "Serializer.hpp"

int main(void)
{

	Data*		data;
	uintptr_t	ptrData = 0;
	Data*		newData = NULL;

	data = new Data;
	data->value = 42;

	std::cout << "data:\t\t" << data << std::endl;
	std::cout << "data->value:\t" << data->value << std::endl;

	std::cout << "Calling serialize on data" << std::endl;

	ptrData = Serializer::serialize(data);

	std::cout << "ptrdata:\t" << ptrData << std::endl;

	std::cout << "Calling deserialize on newData" << std::endl;

	newData = Serializer::deserialize(ptrData);
	std::cout << "newData:\t" << newData << std::endl;
	std::cout << "newData->value:\t" << newData->value <<std::endl;

	delete data;

}