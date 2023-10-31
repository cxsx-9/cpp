#include "Base.hpp"
#include <ctime>
#include <cstdlib>

Base::~Base( void ){}

Base * generate( void ) // upcast from child (A, B, C) -> parent(Base)
{
	std::srand(std::time(0));
	int key = rand() % 3;
	switch (key)
	{
	case 0:
		std::cout << "Create A" << std::endl;	
		return (new A());
		break;
	case 1:
		std::cout << "Create B" << std::endl;	
		return (new B());
		break;
	case 2:
		std::cout << "Create C" << std::endl;	
		return (new C());
		break;
	default:
		return (NULL);
		break;
	}
}
void identify(Base* p) // if OK, it will not return NULL
{
	if (dynamic_cast<A *>(p))
		std::cout << "Detect A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Detect B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Detect C" << std::endl;
}

void identify(Base& p) // if not OK, it will throw the Exception
{
	try
	{
		A &d = dynamic_cast<A &>(p);
		(void) d;
		std::cout << "Detect A" << std::endl;
	}
	catch( std::exception &e)
	{
		try
		{
			B &d = dynamic_cast<B &>(p);
			(void) d;
			std::cout << "Detect B" << std::endl;
		}
		catch( std::exception &e)
		{
			try
			{
				C &d = dynamic_cast<C &>(p);
				(void) d;
				std::cout << "Detect C" << std::endl;
			}
			catch( std::exception &e)
			{
			}
		}
	}
}