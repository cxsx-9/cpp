#include "Base.hpp"

// Keyword : dynamic cast

int main()
{
	Base	*mysteryClass = generate(); // upcasting
	
	identify(mysteryClass); // attempting downcastint
	identify(*mysteryClass);
}