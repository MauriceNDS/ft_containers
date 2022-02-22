#include <vector>
#include <iostream>


int main( void ) {

	std::vector<int> a(1);

	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	a.resize(100);
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
}