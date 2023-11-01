#include "whatever.hpp"

void test0()
{
    std::cout << MAGENTA << "\n---- TEST 0 ---- int" << DEFAULT << std::endl;
    int a = 2;
    int b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "  [swap]" << std::endl;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min = " << ::min( a, b ) << std::endl;
    std::cout << "max = " << ::max( a, b ) << std::endl;

}

void test1()
{
    std::cout << MAGENTA << "\n---- TEST 1 ---- string" << DEFAULT << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "  [swap]" << std::endl;
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min = " << ::min( c, d ) << std::endl;
    std::cout << "max = " << ::max( c, d ) << std::endl;
}

void test2()
{
    std::cout << MAGENTA << "\n---- TEST 2 ---- float" << DEFAULT << std::endl;
    float a = 3.14;
    float b = 6.022;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "  [swap]" << std::endl;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min = " << ::min( a, b ) << std::endl;
    std::cout << "max = " << ::max( a, b ) << std::endl;
}

int main ()
{
    test0();
    test1();
    test2();
    std::cout << MAGENTA << "\n----------------" << DEFAULT << std::endl;
}
