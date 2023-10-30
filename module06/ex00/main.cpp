#include "ScalarConverter.hpp"
#include <iostream>

int main (int ac, char** av)
{
    try
    {
        if (ac == 2 && av[1][0])
            ScalarConverter value(av[1]);
        else
            throw ScalarConverter::BadInputException();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error :" << e.what() << DEFAULT << std::endl;
    }
    return (0);
}