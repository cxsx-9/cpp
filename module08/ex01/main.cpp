#include "Span.hpp"
#include <ctime>
#include <cstdlib>

void test0()
{
    std::cout << MAGENTA << "\n---- TEST 0 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : random" << DEFAULT << std::endl;
    try
    {
        std::srand(std::time(0));
        unsigned int max = 10 + (rand() % 5);
        Span arr(max);
        for (unsigned int i = 0; i < max; i++)
            arr.addNumber(rand() % 1000);
        arr.print();
        std::cout << "Longest Span  : "<< arr.longestSpan() << std::endl;
        std::cout << "Shortest Span : "<< arr.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }
}

void test1()
{
    std::cout << MAGENTA << "\n---- TEST 1 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : random and addRange" << DEFAULT << std::endl;
    try
    {
        std::srand(std::time(0));
        unsigned int max = 30;
        int size = 15; // for add more by range
        Span arr(max);
        for (unsigned int i = 0; i < max - size; i++)
            arr.addNumber(rand() % 1000);
        arr.print();
        
        std::vector<int> newArr(size);
        for (int i = 0; i < size; i++)
            newArr[i] = rand() % 1000;
        arr.addRange(newArr.begin(), newArr.end());
        arr.print();
        std::cout << "Longest Span  : "<< arr.longestSpan() << std::endl;
        std::cout << "Shortest Span : "<< arr.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }
}

void test2()
{
    std::cout << MAGENTA << "\n---- TEST 2 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : error" << DEFAULT << std::endl;
    try
    {
        Span arr(0);
        arr.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }

    try
    {
        Span arr(0);
        std::cout << arr.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }

    try
    {
        Span arr(0);
        std::cout << arr.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }

    try
    {
        Span arr(10);
        for (int i = 0; i < 5; i++)
            arr.addNumber(i);
                std::vector<int> newArr(6);
        for (int i = 0; i < 6; i++)
            newArr[i] = i;
        arr.addRange(newArr.begin(), newArr.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }
}

void test3()
{
    std::cout << MAGENTA << "\n---- TEST 3 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : error with 0 size array" << DEFAULT << std::endl;
    try
    {
        Span arr(0);
        arr.addNumber(1);
        arr.print();
        std::cout << "Longest Span  : "<< arr.longestSpan() << std::endl;
        std::cout << "Shortest Span : "<< arr.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }
}

int main()
{
    test0();
    test1();
    test2();
}