#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw RPN::ErrBadInput();
        RPN rpn(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: "<< e.what() << '\n';
    }
    
    return (0);
}