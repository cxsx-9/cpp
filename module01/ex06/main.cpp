#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl h;

    if (ac != 2)
    {
        std::cout << "./harlFilter <complain>" << std::endl;
        return (0);
    }
    h.complain(av[1]);
    return (0);
}