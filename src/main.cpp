#include <vector>
#include <iostream>
#include "vector.hpp"

int main( void ) {

	std::vector<int> a(10, 5);

	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	a.insert(a.begin(), 23, 42);
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	std::cout << a[12] << std::endl;
}