#include "easyfind.hpp"
#include <ctime>
#include <cstdlib>

// extension
template<typename T>
void print(T &container)
{
	typename T::const_iterator it;
	std::cout << "[ ";
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
}

// test case
void test0()
{
    std::cout << MAGENTA << "\n---- TEST 0 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Vector<int> random" << DEFAULT << std::endl;

	std::vector<int> vec;
	std::vector<int>::const_iterator it;

	for (int i = 0; i < 10; i++)
		vec.push_back(std::rand()%10);
	print(vec);
	int target = std::rand() % 10;
	std::cout << BLUE << "find " << target << DEFAULT << std::endl;
    try
    {
		it = easyfind(vec, target);
		std::cout << GREEN << "found : " << *it << DEFAULT << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }
}

void test1()
{
    std::cout << MAGENTA << "\n---- TEST 1 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : List<int> random" << DEFAULT << std::endl;

	std::list<int> lst;
	std::list<int>::const_iterator it;

	for (int i = 0; i < 10; i++)
		lst.push_back(std::rand()%10);
	print(lst);
	int target = std::rand() % 10;
	std::cout << BLUE << "find " << target << DEFAULT << std::endl;
    try
    {
		it = easyfind(lst, target);
		std::cout << GREEN << "found : " << *it << DEFAULT << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }
}

void test2()
{
    std::cout << MAGENTA << "\n---- TEST 2 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : List<int> random" << DEFAULT << std::endl;

	std::list<int> lst;
	std::list<int>::const_iterator it;

	for (int i = 0; i < 10; i++)
		lst.push_back(std::rand()%10);
	print(lst);
	int target = std::rand() % 10;
	std::cout << BLUE << "find " << target << DEFAULT << std::endl;
    try
    {
		it = easyfind(lst, target);
		std::cout << GREEN << "found : " << *it << DEFAULT << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Exception : " << e.what() << std::endl;
    }
} 

int main()
{
	std::srand(std::time(0));
	test0();
	test1();
}