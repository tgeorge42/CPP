#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template< typename T >

class Array
{
	private :

		T				*_array;
		unsigned long	_size;

	public :

		Array<T>( void )
		{
			this->_array = NULL;
			this->_size = 0;
			return ;
		}

		Array<T>( unsigned int const &n ) : _size( n )
		{
			this->_array = new T[n];
			if (!this->_array)
				throw std::exception();
		}

		~Array<T>( void )
		{

			if (this->_array)
				delete [] this->_array;
		}

		Array<T>(const Array<T> & copy)
		{
			this->_size = copy.size();
			this->_array = new T[this->_size];
			if (!this->_array)
				throw std::exception();
			for (unsigned long i = 0 ; i < this->_size ; i++)
				this->_array[i] = copy.getContent[i];

			return ;
		}

		Array<T>	&operator=(const Array<T> & copyOp)
		{
			this->_size = copyOp.size();
			if (this->_array)
				delete this->_array;
			this->_array = new T[this->_size];
			if (!this->_array)
				throw std::exception();
			for (unsigned long i = 0 ; i < this->_size ; i++)
				this->_array[i] = copyOp[i];

			return *this;
		}

		T	&operator[](unsigned long i) const
		{
			if (i < this->_size)
				return (this->_array[i]);
			throw Array<T>::WrongIndex();
		}

		unsigned long	size( void ) const
		{
			if (this->_size > 0)
				return this->_size;
			throw Array<T>::EmptySize();
		}

		class WrongIndex : public std::exception
		{
			public :
				virtual const char *what() const throw()
				{
					return ("Invalid index");
				}
		};
		class EmptySize : public std::exception
		{
			public :
				virtual const char *what() const throw()
				{
					return ("Invalid size");
				}
		};
};

#endif