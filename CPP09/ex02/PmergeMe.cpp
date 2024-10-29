#include "PmergeMe.hpp"

bool PmergeMe::isInt(const std::string& str)
{
	size_t	i = 0;
	if (str[i] == '+' or str[i] == '-')
		i++;
	while (isdigit(str[i]))
		i++;
	if (i == str.length() && i)
		return true;
	return false;
}

PmergeMe::PmergeMe(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        if(isInt(av[i]) == true)
        {
            std::istringstream str(av[i]);
            int nb;
            str >> nb;
            if (!(nb < 0 || nb > INT_MAX))
            {
                if (std::find(_vector.begin(), _vector.end(), nb) == _vector.end())
                {
                    _vector.push_back(nb);
                    _deque.push_back(nb);
                }
            }
            else
                throw wrongNumberException();
        }
        else
           throw notIntegerException();
    }
    std::cout << "PmergeMe constructor called" << std::endl;
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
    {
        std::cout << *it << " "; 
    }
    std::cout << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
    (void)rhs;
    std::cout << "PmergeMe copy constructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe& rhs)
{
    (void)rhs;
    std::cout << "PmergeMe assignement operator called" << std::endl;
    return (*this);
}

template< typename T >
void    PmergeMe::sort(T& to_sort)
{
    T main;
    T temp;
    for (size_t i = 0; i < to_sort.size() - 1; i += 2)
    {
        if (to_sort[i] > to_sort[i + 1])
        {
            std::swap(to_sort[i], to_sort[i + 1]);
        }
    }
    if (to_sort.size() > 2)
    {
        for (size_t i = 0; i < to_sort.size(); i+= 2)
        {
            main.push_back(to_sort[i]);
            if (i < to_sort.size() - 1)
                temp.push_back(to_sort[i + 1]);
        }
        sort(temp);
        size_t pendSize = main.size();
        for (size_t i = 0; i < pendSize; i++)
        {
            size_t j = 0;
            size_t sortIndex = 0;
		    for (; _jacobsthal(j) < i; j++) {}
		    if (j)
            {
			    if (_jacobsthal(j) >= pendSize - 1)
				    sortIndex = pendSize - (i - _jacobsthal(j - 1));
			    else
				    sortIndex = _jacobsthal(j) + 1 - (i- _jacobsthal(j - 1));
		    }
            _binarySearchInsert(temp, main[sortIndex]);
        }
        to_sort = temp;
    }
}

unsigned int PmergeMe::_jacobsthal(unsigned int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return _jacobsthal(n - 1) + 2 * _jacobsthal(n - 2);
}

long long int PmergeMe::_getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

template< typename T >
void PmergeMe::_binarySearchInsert(T& container, int value)
{
	int low = 0;
    int high = container.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (container[mid] == value)
            return; 
		else if (container[mid] < value)
            low = mid + 1;
		else
            high = mid - 1;
    }
    container.insert(container.begin() + low, value);
}

void    PmergeMe::process()
{
        unsigned long long time = _getTime();
        sort(_vector);
        time = _getTime() - time;
        std::cout << "After: ";
	    for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
		    std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector<int> : " << time << " us" << std::endl;
        time = _getTime();
        sort(_deque);
        time = _getTime() - time;
        std::cout << "Time to process a range of " << _deque.size()
		<< " elements with std::deque<int> : " << time << " us" << std::endl;
}

const char* PmergeMe::wrongNumberException::what() const throw()
{
    return ("wrong number input");
}

const char* PmergeMe::notIntegerException::what() const throw()
{
    return ("not an integer");
}

PmergeMe::~PmergeMe()
{
    std::cout << "PmergeMe destructor called" << std::endl;
}
