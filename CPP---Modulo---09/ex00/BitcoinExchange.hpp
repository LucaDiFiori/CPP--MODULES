#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> data;

		bool isValidDate(const std::string& date);
		bool isValidValue(const float value);
		std::string getClosestDate(const std::string& date);
		void trimWhitespace(std::string& str);

	public:
		BitcoinExchange();
		~BitcoinExchange();

		void loadDatabase(const std::string& filename);
		void processInputFile(const std::string& filename);
};

#endif
