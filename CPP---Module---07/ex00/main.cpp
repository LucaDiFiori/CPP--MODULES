#include "whatever.hpp"
#include <iostream>

int main( void ) {
    int a = 2;
    int b = 3;
    std::cout << "Start int: " << std::endl;
    std::cout << "a = " << a << ", b = " << b << "\n" << std::endl;

    ::swap( a, b );
    std::cout << "Swap: " << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "Max & Min: " << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << "\n" <<  std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "Start char: " << std::endl;
    std::cout << "c = " << c << ", d = " << d << "\n" << std::endl;
    
    ::swap(c, d);
    std::cout << "Swap: " << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "Max & Min: " << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << "\n" << std::endl;
    
    return 0;
}