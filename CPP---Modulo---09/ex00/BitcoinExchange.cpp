#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::trimWhitespace(std::string& str) {
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");
    if (first != std::string::npos && last != std::string::npos)
        str = str.substr(first, last - first + 1);
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open data file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t separator = line.find(',');
        if (separator != std::string::npos) {
            std::string date = line.substr(0, separator);
            float rate;
            std::istringstream(line.substr(separator + 1)) >> rate;
            data[date] = rate;
        }
    }
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t separator = line.find('|');
        if (separator == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, separator);
        std::string valueStr = line.substr(separator + 1);
        trimWhitespace(date);
        trimWhitespace(valueStr);

        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        std::istringstream(valueStr) >> value;

        if (value <= 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        if (!isValidValue(value)) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        std::string closestDate = getClosestDate(date);
        float exchangeRate = data[closestDate];
        float result = value * exchangeRate;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    int y, m, d;
    std::istringstream(year) >> y;
    std::istringstream(month) >> m;
    std::istringstream(day) >> d;

    if (m < 1 || m > 12) return false;
    if (d < 1 || d > 31) return false;

    return true;
}

bool BitcoinExchange::isValidValue(const float value)
{
    if (value <= 1000)
        return true;
    return false;
}

std::string BitcoinExchange::getClosestDate(const std::string &date) {
    std::map<std::string, float>::iterator it = data.lower_bound(date);
    if (it == data.begin())
        return it->first;
    if (it == data.end() || it->first != date)
        --it;
    return it->first;
}
