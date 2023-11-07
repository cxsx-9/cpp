#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw BitcoinExchange::ErrFileFailed();
        BitcoinExchange btc;

        btc.exchange(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: "<< e.what() << '\n';
    }
    
    return (0);
}