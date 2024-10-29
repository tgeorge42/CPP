#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

class BitcoinExchange
{
	private:

		std::map<std::string, float>	_data;
		int								_today[3];

	public:

		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & copy);
		BitcoinExchange &operator=(const BitcoinExchange & copyOp);

		bool	verifyRecentDate(const std::string & year, const std::string & month, const std::string & day);
		bool	checkValue(std::string value);
		bool	checkDate(std::string date);
		void	checkInputFile(char *str);
		void	calculAndPrint(std::string date, float value);

};

