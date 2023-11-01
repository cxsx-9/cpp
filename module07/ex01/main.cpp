#include "iter.hpp"

void test0()
{
    std::cout << MAGENTA << "\n---- TEST 0 ---- int array" << DEFAULT << std::endl;

    int array[] = {3, 2, 1, 0, 9};
    int size = 5;
    ::iter(array, size, &print);
}

void test1()
{
    std::cout << MAGENTA << "\n---- TEST 1 ---- char array" << DEFAULT << std::endl;

    char array[] = "Hello";
    int size = 5;
    ::iter(array, size, &print);
}

void test2()
{
    std::cout << MAGENTA << "\n---- TEST 2 ---- string array" << DEFAULT << std::endl;

    std::string array[] = {"Hello World!", "Here is 42", "Goodluck!"};
    int size = 3;
    ::iter(array, size, &print);
}

void test3()
{
    std::cout << MAGENTA << "\n---- TEST 3 ---- float array" << DEFAULT << std::endl;

    float array[] = {3.14, 331.06, 1.66, 6.022};
    int size = 4;
    ::iter(array, size, &print);
}

int main ()
{
    test0();
    test1();
    test2();
    test3();
    std::cout << MAGENTA << "\n----------------" << DEFAULT << std::endl;
}
