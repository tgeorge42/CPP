#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <climits>
#include <algorithm>
#include <sys/time.h>

typedef struct	s_pair
{
	int		value;
	int		index;
	int		id;
}				t_pair;

class PmergeMe
{
    public:
        PmergeMe(char **av);
        PmergeMe(const PmergeMe& rhs);
        PmergeMe &operator=(const PmergeMe& rhs);
        void process();
        template<typename T>
        void sort(T& to_sort);
        unsigned int _jacobsthal(unsigned int n);
        template<typename T>
        void _binarySearchInsert(T& container, t_pair pair);
        long long int _getTime();
        bool isInt(const std::string& str);
        class wrongNumberException : public std::exception
        {
	        public:
		        virtual const char* what() const throw();
	    };
        class notIntegerException : public std::exception
        {
	        public:
		        virtual const char* what() const throw();
	    };
        ~PmergeMe();
        
    private:
        std::deque<t_pair> _deque;
	    std::vector<t_pair> _vector;
};