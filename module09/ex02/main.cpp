#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac == 1)
            throw PmergeMe::ErrInput();
        PmergeMe pme(ac, av);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: "<< e.what() << '\n';
    }
    
    return (0);
}
