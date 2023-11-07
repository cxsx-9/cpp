#include "BitcoinExchange.hpp"

static bool validDate(std::string time);
static bool validPrice(std::string price);
static bool validRangePrice(double price);

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	dataFile("data.csv");
	if (!dataFile.is_open())
		throw BitcoinExchange::ErrFileFailed();
	std::string rawData;
	while (std::getline(dataFile, rawData))
	{
		if (rawData == "date,exchange_rate")
			continue;
		size_t pos = rawData.find(",");
		if (pos == std::string::npos)
		{
			std::cout << "Error: Invalid format in Database." << std::endl;
			continue;
		}
		std::string date = rawData.substr(0, pos);
		std::string stringValue = rawData.substr(pos + 1, rawData.size());
		if (!validDate(date) || !validPrice(stringValue))
			continue;
		double value = atof(stringValue.c_str());
		_dataBase.insert(std::make_pair(date, value));
	}
	dataFile.close();
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &copy ) : _dataBase(copy._dataBase){}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	_dataBase = copy._dataBase;
	return (*this);
}

void BitcoinExchange::exchange(std::string fileName)
{
	std::ifstream	inputFile(fileName);
	if (!inputFile.is_open())
		throw BitcoinExchange::ErrFileFailed();
	std::string rawData;
	while (std::getline(inputFile, rawData))
	{
		if (rawData == "date | value")
			continue;
		size_t pos = rawData.find(" | ");
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << rawData << std::endl;
			continue;
		}
		std::string date = rawData.substr(0, pos);
		std::string stringValue = rawData.substr(pos + 3, rawData.size());
		if (!validDate(date) || !validPrice(stringValue))
			continue;
		double value = atof(stringValue.c_str());
		if (!validRangePrice(value))
			continue;

		std::multimap<std::string, double>::const_iterator it_dataBase = _dataBase.begin();
		for (;it_dataBase != _dataBase.end() && it_dataBase->first < date; it_dataBase++) {}
		if (it_dataBase->first > date)
			it_dataBase--;
		std::cout << date << " => " << value << " = " << it_dataBase->second * value << std::endl;

		//debug
		// std::cout << "get:" << it_dataBase->first << "    " << it_dataBase->second << " * " << value << " = " << it_dataBase->second * value << "\n\n"; // debug
	}
	inputFile.close();
}

bool BitcoinExchange::validDate(std::string time)
{
	if (time.size() == 10)
	{
		if (time[4] == '-' && time[7] == '-')
		{
			std::istringstream yearStream(time.substr(0, 4));
			std::istringstream monthStream(time.substr(5, 2));
			std::istringstream dateStream(time.substr(8, 2));
			int year, day, month;
			if (yearStream >> year && dateStream >> day && monthStream >> month)
				if (year >= 0 && day >= 1 && day <= 31 && month >= 1 && month <= 12)
					return (true);
		}
	}
	std::cout << "Error: bad input => " << time << std::endl;
	return (false);
}

bool BitcoinExchange::validPrice(std::string price)
{
	std::string::const_iterator it = price.begin();
	bool run = true;
	while (it != price.end() && run)
	{
		if ((!isdigit(*it) && *it != '.' && *it != '-' && *it != '+') || 
			(*it == '.' && (it == price.begin() || it == price.end())))
			run = false;
		it++;
	}
	if (run)
		return (true);
	std::cout << "Error: Invalid number." << std::endl;
	return (false);
}

bool BitcoinExchange::validRangePrice(double price)
{
	if (price < 0 || price > 1000)
	{
		if (price < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (price > 1000)
			std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}
