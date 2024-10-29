#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string.h>
# include <ctype.h>

template < typename T , typename U >
void    iter(T * array, size_t len,  U (*func))
{
    if (! array || len <= 0 || ! func)
        throw std::exception();
    for (size_t i = 0; i < len; i++)
        func(array[i]);
    return ;
}

#endif