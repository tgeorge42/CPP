#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

typedef struct s_Data 
{
	int			value;
}				Data;

class Serializer
{
	private :
	
		Serializer();
		Serializer(Serializer const &src);
		~Serializer();
		Serializer& operator=(Serializer const &rhs);

	public:

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

};

#endif