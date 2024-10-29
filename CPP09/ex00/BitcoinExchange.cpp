#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    time_t        rawtime;
    struct tm    *timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    _today[0] = timeinfo->tm_year + 1900;
    _today[1] = timeinfo->tm_mon + 1;
    _today[2] = timeinfo->tm_mday;

	std::ifstream data_stream("data.csv");
	if (!(data_stream.is_open()))
		throw std::ios_base::failure("Error: could not open file.");

	std::string line;
    while(getline(data_stream, line))
    {
        size_t   commaPos = line.find(',');
        if (commaPos != std::string::npos)
        {
            std::string date = line.substr(0, commaPos);
            float value = strtof((line.substr(commaPos + 1)).c_str(), NULL);
            _data.insert(std::make_pair(date, value));
        }
		else
			throw std::runtime_error("Character ',' not found in the data file.");
    }
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & copy)
{
	(void)copy;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & copyOp)
{
	(void)copyOp;
	return (*this);
}

bool	isNumeric(const std::string & str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
        if (!std::isdigit(*it))
            return false;
    }
    return true;
}

bool	verifyLatestDate(const std::string & year, const std::string & month, const std::string & day)
{
	if (atoi(year.c_str()) < 2009)
		return false;
	else if (atoi(year.c_str()) == 2009 && atoi(month.c_str()) == 01 && atoi(day.c_str()) < 02)
			return false;
	return true;
}

bool	BitcoinExchange::verifyRecentDate(const std::string & year, const std::string & month, const std::string & day)
{
	if (atoi(year.c_str()) > _today[0])
		return false;
	else if (atoi(year.c_str()) == _today[0] && atoi(month.c_str()) > _today[1])
		return false;
	else if (atoi(year.c_str()) == _today[0] && atoi(month.c_str()) == _today[1] && atoi(day.c_str()) > _today[2])
			return false;
	return true;
}

bool	isLeap(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	return false;
}

bool	dateOverflow(const std::string & year, const std::string & month, const std::string & day)
{
	char		*endPtr;
	long int	year_str = strtol(year.c_str(), &endPtr, 10);
	if (*endPtr != '\0')
	{
        std::cout << "Error: Conversion failed: Not a valid number." << std::endl;
		return false;
	}
	long int	month_str = strtol(month.c_str(), &endPtr, 10);
	if (*endPtr != '\0')
	{
        std::cout << "Error: Conversion failed: Not a valid number." << std::endl;
		return false;
	}
	long int	day_str = strtol(day.c_str(), &endPtr, 10);
	if (*endPtr != '\0')
	{
        std::cout << "Error: Conversion failed: Not a valid number." << std::endl;
		return false;
	}

	if (month_str == 0 || day_str == 0 || month_str > 12)
		return false;
	if (month_str == 02)
	{
		if ((isLeap(year_str) && day_str > 29) || (!isLeap(year_str) && day_str > 28))
		{
			return false;
		}
	}
	else if (month_str <= 7)
	{
		if ((month_str % 2 == 0 && day_str > 30) || (month_str % 2 == 1 && day_str > 31))
			return false;
	}
	else if (month_str <= 12)
	{
		if ((month_str % 2 == 0 && day_str > 31) || (month_str % 2 == 1 && day_str > 30))
			return false;
	}
	return true;
}

bool	BitcoinExchange::checkDate(std::string date)
{
	std::string year;
	std::string month;
	std::string day;

	if (date.size() == 11)
	{
		if (date[4] == '-' && date[7] == '-' && date[10] == ' ')
		{
			year = date.substr(0, 4);
			month = date.substr(5, 2);
			day = date.substr(8, 2);
			if (isNumeric(year) && isNumeric(month) && isNumeric(day))
			{
				if (dateOverflow(year, month, day))
				{
					if (verifyLatestDate(year, month, day))
					{
						if (verifyRecentDate(year, month, day))
							return true;
						else
							std::cout << "Error: date posterior to today's date => " << date << std::endl;
					}
					else
						std::cout << "Error: date prior to oldest known date => " << date << std::endl;
				}
				else
					std::cout << "Error: date is invalid => " << date << std::endl;
			}
			else
				std::cout << "Error: bad input => " << date << std::endl;
		}
		else
			std::cout << "Error: bad input => " << date << std::endl;
	}
	else
		std::cout << "Error: bad input => " << date << std::endl;
	return false;
}

bool	isFloat(const std::string & value)
{
	int		point = 0;
	std::string		value_to_float = value.substr(1, value.size());
    for (std::string::const_iterator it = value_to_float.begin(); it != value_to_float.end(); ++it)
	{
        if (!std::isdigit(*it) && *it != '.')
            return false;
		if (*it == '.')
		{
			if (point == 0)
				point++;
			else
				return false;
		}
    }
	return true;
}

bool	BitcoinExchange::checkValue(std::string value)
{
	char		*endPtr;

	float		value_str = strtof(value.c_str(), &endPtr);
	if (*endPtr != '\0')
	{
		std::cout << "Error: Conversion failed: Not a valid floating number." << std::endl;
		return false;
	}
	if (value[0] == ' ')
	{
		if (isFloat(value))
		{
			if (value_str <= 1000)
			{
				if (value_str >= 0)
					return true;
				else
					std::cout << "Error: not a positive number." << std::endl;
			}
			else
				std::cout << "Error: too large a number." << std::endl;
		}
		else
			std::cout << "Error: bad input => " << value << std::endl;
	}
	else
		std::cout << "Error: bad input => " << value << std::endl;
	return false;
}

void	BitcoinExchange::checkInputFile(char *str)
{
	std::ifstream	input_stream(str);
	if (!(input_stream.is_open()))
		throw std::ios_base::failure("Error: could not open file.");

	std::string 					line;
	std::string 					date;
	std::string 					value;
	size_t							pipePos;
	bool							first_line = true;

    while(getline(input_stream, line))
    {
		if (first_line == true && line != "date | value")
			std::cout << "Error: Wrong format" << std::endl;
		if (first_line == false)
		{
			if (!line.empty())
			{
				pipePos = line.find('|');
				if (pipePos != std::string::npos)
				{
					date = line.substr(0, pipePos);
					value = line.substr(pipePos + 1, line.size());
					if (checkDate(date) && checkValue(value))
					{
						float valueF = strtof((line.substr(pipePos + 1)).c_str(), NULL);
						calculAndPrint(date, valueF);
					}
				}
				else
					std::cout << "Error: no pipe found." << std::endl;
			}
			else
				std::cout << "Error: line is empty." << std::endl;
		}
		else
			first_line = false;
    }
}

void	BitcoinExchange::calculAndPrint(std::string date, float value)
{
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    if (it != _data.end() && it->first == date)
    {
        float result = value * it->second;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    else
    {
        if (it != _data.begin())
        {
            --it;
            float result = value * it->second;
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
    }
}