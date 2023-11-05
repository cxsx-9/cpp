# include "MutantStack.hpp"

void test0()
{
	std::cout << MAGENTA << "\n---- TEST 0 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : 42 main" << DEFAULT << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...] mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void test1()
{
	std::cout << MAGENTA << "\n---- TEST 1 ----" << DEFAULT << std::endl;
	std::cout << YELLOW << "case : Normal" << DEFAULT << std::endl;

	MutantStack<int> mstack;
	for (int i = 0; i < 10; i++)
	{
		mstack.push(i);
		std::cout << "push : " << mstack.top() << std::endl;
	}
	std::cout << "-- size : "<< mstack.size() << std::endl;

	MutantStack<int> newstack(mstack);
	std::cout << "\nusing new stack by Copy constructor\n"; 

	for (int i = 0; i < 5; i++)
	{
		std::cout << "pop  : " << newstack.top() << std::endl;
		newstack.pop();
	}
	std::cout << "-- size : "<< newstack.size() << std::endl;

	mstack = newstack;
	std::cout << "\nusing new stack by Copy assignment operator\n"; 

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	std::cout << "-- display : by using iterator" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	test0();
	test1();
}