#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <climits>
#include <algorithm>
#include <sys/time.h>

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
        void _binarySearchInsert(T& container, int value);
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
        std::deque<int> _deque;
	    std::vector<int> _vector;
};