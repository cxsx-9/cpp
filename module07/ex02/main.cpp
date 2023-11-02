#include "Array.hpp"
#include "Array.tpp"

#include "ctime"
#include "cstdlib"

void test0()
{
    std::cout << MAGENTA << "\n---- TEST 0 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Create int array" << DEFAULT << std::endl;
    int sizeBox = 5;
    Array<int>   Box(sizeBox);

    // random part        
    std::srand(std::time(0));
    for (int i = 0; i < sizeBox; i++)
    {
        Box[i] = std::rand();
    }        

    std::cout << "size = " << Box.size() << std::endl;
    std::cout << YELLOW << "Show all" << DEFAULT << std::endl;
    std::cout << Box;
    std::cout << YELLOW << "Show first and last" << DEFAULT << std::endl;
    std::cout << Box[0] << std::endl;
    std::cout << Box[Box.size() - 1] << std::endl;
    std::cout << YELLOW << "Try out of bounds" << DEFAULT << std::endl;
    try
    {
        std::cout << Box[-1] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }
    try
    {
        std::cout << Box[Box.size()] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }
}

void test1()
{
    std::cout << MAGENTA << "\n---- TEST 1 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Create char array" << DEFAULT << std::endl;
    int sizeBox = 5;
    Array<char>   Box(sizeBox);


    // random part        
    std::srand(std::time(0));
    for (int i = 0; i < sizeBox; i++)
    {
        Box[i] = (std::rand() % 93) + 33; // range of printable character
    }        

    std::cout << "size = " << Box.size() << std::endl;
    std::cout << YELLOW << "Show all" << DEFAULT << std::endl;
    std::cout << Box;
    std::cout << YELLOW << "Show first and last" << DEFAULT << std::endl;
    std::cout << Box[0] << std::endl;
    std::cout << Box[Box.size() - 1] << std::endl;
    std::cout << YELLOW << "Try out of bounds" << DEFAULT << std::endl;
    try
    {
        std::cout << Box[-1] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }
    try
    {
        std::cout << Box[Box.size()] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }
}

void test2()
{
    std::cout << MAGENTA << "\n---- TEST 2 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : create empty array and Bad access" << DEFAULT << std::endl;

    Array<float>   Box;

    std::cout << "size = " << Box.size() << std::endl;
    std::cout << YELLOW << "Try to access" << DEFAULT << std::endl;
    try
    {
        std::cout << Box[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }
}

void test3()
{
    std::cout << MAGENTA << "\n---- TEST 3 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : copy from normal" << DEFAULT << std::endl;

    Array<int>   Box1;
    Array<int>   Box2(5);

    std::cout << "size Box1 = " << Box1.size() << std::endl;
    std::cout << "size Box2 = " << Box2.size() << std::endl;
    std::srand(std::time(0));


    std::cout << "Fill something in Box2" << std::endl;
    for (unsigned int i = 0; i < Box2.size(); i++)
    {
        Box2[i] = std::rand();
    }

    std::cout << YELLOW << "Show all in Box2" << DEFAULT << std::endl;
    std::cout << Box2;

    std::cout << YELLOW << "Box1 = Box2" << DEFAULT << std::endl;
    Box1 = Box2;
    std::cout << YELLOW << "Show all in Box2" << DEFAULT << std::endl;
    std::cout << Box2;
}

void test4()
{
    std::cout << MAGENTA << "\n---- TEST 4 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : copy from empty" << DEFAULT << std::endl;

    Array<int>   Box1;
    Array<int>   Box2(5);

    std::cout << "size Box1 = " << Box1.size() << std::endl;
    std::cout << "size Box2 = " << Box2.size() << std::endl;
    std::srand(std::time(0));


    std::cout << "Fill something in Box2" << std::endl;
    for (unsigned int i = 0; i < Box2.size(); i++)
    {
        Box2[i] = std::rand();
    }

    std::cout << YELLOW << "Show all in Box2" << DEFAULT << std::endl;
    std::cout << Box2;

    std::cout << YELLOW << "Box2 = Box1" << DEFAULT << std::endl;
    Box2 = Box1;
    std::cout << YELLOW << "Show all in Box2" << DEFAULT << std::endl;
    std::cout << Box2;
}


int main()
{
    test0();
    test1();
    test2();
    test3();
    test4();
}