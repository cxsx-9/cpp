#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <map>
# include <stdlib.h>

class BitcoinExchange
{
    private:
        std::multimap<std::string, double> _dataBase;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange( const BitcoinExchange &copy );
		BitcoinExchange	&operator=(const BitcoinExchange &copy);

        void exchange(std::string fileName); // fix here
        bool validDate(std::string time); // fix here
        bool validPrice(std::string price);
        bool validRangePrice(double price);
    
		class ErrFileFailed: public std::exception
		{
			public:
				virtual const char* what() const throw(){ return ("could not open file."); }
		};
};

#endif



/*
    note:

    map -> { key, value }

    -- database --
    Year-Month-Day,<float>

    -- input data --
    data | value
    Year-Month-Day | <float/positive int> (in range 0 - 1000)

    -- output --

    Error: not a positive number.
    Error: bad input => 2001-42-42
    Year-Month-Day => value = value * rate

    example
        2012-01-11 => 1 = 7.1


• The program name is btc.
• Your program must take a file as argument.
• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer, between 0 and 1000.

You must use at least one container in your code to validate this
exercise.  You should handle possible errors with an appropriate
error message.


map         > collection of key-value pairs, sorted by keys, keys are unique
multimap    > collection of key-value pairs, sorted by keys

std::multimap is an associative container that contains a sorted list of 
key-value pairs, while permitting multiple entries with the same key. 
Sorting is done according to the comparison function Compare, applied to the keys. 
Search, insertion, and removal operations have logarithmic complexity.

[std::istringstrem] use space to sepperate and concern about type to cast
*/