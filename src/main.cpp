#include <iostream>

#ifdef STL_CONTAINERS
	#include <iterator>
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

template<typename T>
void	displayVect( ft::vector<T> &vect, std::string test ) {
	std::cout << "=======================================================" << std::endl;
	std::cout << test << std::endl;
	for ( size_t i = 0; i < vect.size(); i++ ) {
		std::cout << vect[i] << ' ';
	}
	
	std::cout << std::endl << "size = " << vect.size() << std::endl;
	std::cout << "capacity = " << vect.capacity() << std::endl << std::endl;
}

void iteratorTests( void ) {
	std::cout << "ITERATOR TESTS:" << std::endl << std::endl;

	{
		std::cout << "Constructors:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::iterator a;
		ft::vector<int>::iterator b = vec.begin();
		std::cout << *b << std::endl;
		ft::vector<int>::iterator c( b );
		std::cout << *c << std::endl;
		*b += 10;
		std::cout << *b << " " << *c << std::endl;
		a = b;
		std::cout << *a << " " << *b << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Equality operators:" << std::endl;
		ft::vector<std::string> vec;
		ft::vector<int> x;
		std::cout << std::boolalpha << ( x.begin() != x.end() ) << std::endl;
		vec.push_back( "Hello" );
		vec.push_back( "HellO" );
		ft::vector<std::string>::iterator a = vec.begin();
		ft::vector<std::string>::iterator b = vec.begin() + 1;
		std::cout << (a == b) << std::endl;
		std::cout << (a != b) << std::endl;
		std::cout << (a != a) << std::endl;
		std::cout << (a == a) << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Dereferenable:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::iterator a = vec.begin();
		std::cout << *a << std::endl;
		*a = -42;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Incrementation:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::iterator a = vec.begin();
		std::cout << *a << std::endl;
		a++;
		std::cout << *a << std::endl;
		++a;
		std::cout << *a << std::endl;
		std::cout << *a++ << std::endl;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Decrementation:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::iterator a = vec.end() - 1;
		std::cout << *a << std::endl;
		a--;
		std::cout << *a << std::endl;
		--a;
		std::cout << *a << std::endl;
		std::cout << *a-- << std::endl;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Arithmetic operators:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::iterator a = vec.begin();
		std::cout << *(a + 2) << std::endl;
		std::cout << *(1 + a) << std::endl;
		a += 3;
		std::cout << *(a - 2) << std::endl;
		std::cout << *a << std::endl;
		a -= 3;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Comparison operators:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 10 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::iterator a = vec.begin();
		ft::vector<int>::iterator b = vec.begin() + 1;
		std::cout << *a << " " << *b << std::endl << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << (a <= b) << std::endl;
		*b = 5;
		std::cout << *a << " " << *b << std::endl << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << (a <= b) << std::endl;
		*b = 0;
		std::cout << *a << " " << *b << std::endl << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Offset dereference operator []:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::iterator a = vec.begin();
		for ( size_t i = 0; i < vec.size(); i++ )
			std::cout << a[i] << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
}

void constIteratorTests( void ) {
	std::cout << "CONST ITERATOR TESTS:" << std::endl << std::endl;

	{
		std::cout << "Constructors:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::const_iterator a;
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_iterator b = cvec.begin();
		std::cout << *b << std::endl;
		ft::vector<int>::const_iterator c( b );
		std::cout << *c << std::endl;
		std::cout << *b << " " << *c << std::endl;
		a = b;
		std::cout << *a << " " << *b << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Equality operators:" << std::endl;
		ft::vector<std::string> vec;
		vec.push_back( "Hello" );
		vec.push_back( "HellO" );
		const ft::vector<std::string> cvec( vec );
		ft::vector<std::string>::const_iterator a = cvec.begin();
		ft::vector<std::string>::const_iterator b = cvec.begin() + 1;
		std::cout << (a == b) << std::endl;
		std::cout << (a != b) << std::endl;
		std::cout << (a != a) << std::endl;
		std::cout << (a == a) << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Dereferenable:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_iterator a = cvec.begin();
		std::cout << *a << std::endl;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Incrementation:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_iterator a = cvec.begin();
		std::cout << *a << std::endl;
		a++;
		std::cout << *a << std::endl;
		++a;
		std::cout << *a << std::endl;
		std::cout << *a++ << std::endl;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Decrementation:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_iterator a = cvec.end() - 1;
		std::cout << *a << std::endl;
		a--;
		std::cout << *a << std::endl;
		--a;
		std::cout << *a << std::endl;
		std::cout << *a-- << std::endl;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Arithmetic operators:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_iterator a = cvec.begin();
		std::cout << *(a + 2) << std::endl;
		std::cout << *(1 + a) << std::endl;
		a += 3;
		std::cout << *(a - 2) << std::endl;
		std::cout << *a << std::endl;
		a -= 3;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Comparison operators:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 10 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_iterator a = cvec.begin();
		ft::vector<int>::const_iterator b = cvec.begin() + 1;
		std::cout << *a << " " << *b << std::endl << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Offset dereference operator []:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_iterator a = cvec.begin();
		for ( size_t i = 0; i < cvec.size(); i++ )
			std::cout << a[i] << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
}

void reverseIteratorTests( void ) {
	std::cout << "REVERSE ITERATOR TESTS:" << std::endl << std::endl;

	{
		std::cout << "Constructors:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::reverse_iterator a;
		ft::vector<int>::reverse_iterator b = vec.rbegin();
		std::cout << *b << std::endl;
		ft::vector<int>::reverse_iterator c( b );
		std::cout << *c << std::endl;
		*b += 10;
		std::cout << *b << " " << *c << std::endl;
		a = b;
		std::cout << *a << " " << *b << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Equality operators:" << std::endl;
		ft::vector<std::string> vec;
		vec.push_back( "Hello" );
		vec.push_back( "HellO" );
		ft::vector<std::string>::reverse_iterator a = vec.rbegin();
		ft::vector<std::string>::reverse_iterator b = vec.rbegin() + 1;
		std::cout << (a == b) << std::endl;
		std::cout << (a != b) << std::endl;
		std::cout << (a != a) << std::endl;
		std::cout << (a == a) << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Dereferenable:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::reverse_iterator a = vec.rbegin();
		std::cout << *a << std::endl;
		*a = -42;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Incrementation:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::reverse_iterator a = vec.rbegin();
		std::cout << *a << std::endl;
		a++;
		std::cout << *a << std::endl;
		++a;
		std::cout << *a << std::endl;
		std::cout << *a++ << std::endl;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Decrementation:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::reverse_iterator a = vec.rend() - 1;
		std::cout << *a << std::endl;
		a--;
		std::cout << *a << std::endl;
		--a;
		std::cout << *a << std::endl;
		std::cout << *a-- << std::endl;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Arithmetic operators:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::reverse_iterator a = vec.rbegin();
		std::cout << *(a + 2) << std::endl;
		std::cout << *(1 + a) << std::endl;
		a += 3;
		std::cout << *(a - 2) << std::endl;
		std::cout << *a << std::endl;
		a -= 3;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Comparison operators:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 10 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::reverse_iterator a = vec.rbegin();
		ft::vector<int>::reverse_iterator b = vec.rbegin() + 1;
		std::cout << *a << " " << *b << std::endl << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << (a <= b) << std::endl;
		*b = 5;
		std::cout << *a << " " << *b << std::endl << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << (a <= b) << std::endl;
		*b = 0;
		std::cout << *a << " " << *b << std::endl << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Offset dereference operator []:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::reverse_iterator a = vec.rbegin();
		for ( size_t i = 0; i < vec.size(); i++ )
			std::cout << a[i] << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
}

void constReverseIteratorTests( void ) {
	std::cout << "CONST REVERSE ITERATOR TESTS:" << std::endl << std::endl;

	{
		std::cout << "Constructors:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		ft::vector<int>::const_reverse_iterator a;
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_reverse_iterator b = cvec.rbegin();
		std::cout << *b << std::endl;
		ft::vector<int>::const_reverse_iterator c( b );
		std::cout << *c << std::endl;
		std::cout << *b << " " << *c << std::endl;
		a = b;
		std::cout << *a << " " << *b << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Equality operators:" << std::endl;
		ft::vector<std::string> vec;
		vec.push_back( "Hello" );
		vec.push_back( "HellO" );
		const ft::vector<std::string> cvec( vec );
		ft::vector<std::string>::const_reverse_iterator a = cvec.rbegin();
		ft::vector<std::string>::const_reverse_iterator b = cvec.rbegin() + 1;
		std::cout << (a == b) << std::endl;
		std::cout << (a != b) << std::endl;
		std::cout << (a != a) << std::endl;
		std::cout << (a == a) << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Dereferenable:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_reverse_iterator a = cvec.rbegin();
		std::cout << *a << std::endl;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Incrementation:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_reverse_iterator a = cvec.rbegin();
		std::cout << *a << std::endl;
		a++;
		std::cout << *a << std::endl;
		++a;
		std::cout << *a << std::endl;
		std::cout << *a++ << std::endl;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Decrementation:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_reverse_iterator a = cvec.rend() - 1;
		std::cout << *a << std::endl;
		a--;
		std::cout << *a << std::endl;
		--a;
		std::cout << *a << std::endl;
		std::cout << *a-- << std::endl;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Arithmetic operators:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_reverse_iterator a = cvec.rbegin();
		std::cout << *(a + 2) << std::endl;
		std::cout << *(1 + a) << std::endl;
		a += 3;
		std::cout << *(a - 2) << std::endl;
		std::cout << *a << std::endl;
		a -= 3;
		std::cout << *a << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Comparison operators:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 10 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_reverse_iterator a = cvec.rbegin();
		ft::vector<int>::const_reverse_iterator b = cvec.rbegin() + 1;
		std::cout << *a << " " << *b << std::endl << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << *a << " " << *b << std::endl << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << *a << " " << *b << std::endl << std::endl;
		std::cout << (a > b) << std::endl;
		std::cout << (a < b) << std::endl;
		std::cout << (a >= b) << std::endl;
		std::cout << (a <= b) << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Offset dereference operator []:" << std::endl;
		ft::vector<int> vec;
		vec.push_back( 5 );
		vec.push_back( 15 );
		vec.push_back( 25 );
		vec.push_back( 35 );
		const ft::vector<int> cvec( vec );
		ft::vector<int>::const_reverse_iterator a = cvec.rbegin();
		for ( size_t i = 0; i < vec.size(); i++ )
			std::cout << a[i] << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
}

void vectorConstructorTests( void ) {
	std::cout << "VECTOR CONSTRUCTOR TESTS:" << std::endl << std::endl;

	{
		ft::vector<int> a;
		displayVect( a, "Default constructor" );
	}
	{
		ft::vector<int> a( 5 );
		displayVect( a, "Constructor with one argument" );
		ft::vector<int> b( 10, 42 );
		displayVect( b, "Constructor with two arguments ( Not iterators )" );
	}
	{
		ft::vector<int> a;
		a.push_back( 5 );
		a.push_back( 15 );
		a.push_back( 25 );
		a.push_back( 35 );
		ft::vector<int> b( a.begin(), a.end() );
		displayVect( b, "Iterator constructor" );
		ft::vector<int> c( b );
		displayVect( c, "Copy constructor" );
		ft::vector<int> d = a;
		displayVect( d, "Operator = lhs");
		displayVect( a, "Operator = rhs");
	}
}

void vectorIteratorTests( void ) {
	std::cout << "VECTOR ITERATOR TESTS:" << std::endl << std::endl;

	{
		ft::vector<int> a;
		a.push_back( 5 );
		a.push_back( 15 );
		a.push_back( 25 );
		a.push_back( 35 );
		std::cout << *a.begin() << std::endl;
		std::cout << *( a.begin() + 1 ) << std::endl;
		std::cout << *( a.end() - 1 ) << std::endl;
		std::cout << *( a.end() - 2 ) << std::endl;
		std::cout << *( a.rend() - 2 ) << std::endl;
		std::cout << *( a.rend() - 1 ) << std::endl;
		std::cout << *a.rbegin() << std::endl;
		std::cout << *( a.rbegin() + 1 ) << std::endl;
	}
}

void vectorCapacityTests( void ) {
	std::cout << "VECTOR CAPACITY TESTS:" << std::endl << std::endl;

	{
		ft::vector<int> a;
		displayVect( a, "Size'n'capacity test 1" );
		a.push_back( 5 );
		displayVect( a, "Size'n'capacity test 2" );
		a.push_back( 15 );
		displayVect( a, "Size'n'capacity test 3" );
		a.push_back( 25 );
		displayVect( a, "Size'n'capacity test 4" );
		a.push_back( 35 );
		displayVect( a, "Size'n'capacity test 5" );
		ft::vector<int> b( 3 );
		displayVect( b, "Size'n'capacity test 6" );
		ft::vector<int> c( 5, 42 );
		displayVect( c, "Size'n'capacity test 7" );
		std::cout << a.max_size() << std::endl;
		std::cout << b.max_size() << std::endl;
		std::cout << c.max_size() << std::endl;
		displayVect( c, "Max_size test" );
	}
	{
		ft::vector<int> a( 5, 42 );
		a.resize( 2 );
		displayVect( a, "Resize test 1" );
	}
	{
		ft::vector<int> a( 5, 42 );
		a.resize( 2, 3 );
		displayVect( a, "Resize test 2" );
	}
	{
		ft::vector<int> a( 5, 42 );
		a.resize( 9 );
		displayVect( a, "Resize test 3" );
	}
	{
		ft::vector<int> a( 5, 42 );
		a.resize( 9, 11 );
		displayVect( a, "Resize test 4" );
	}
	{
		ft::vector<int> a( 5, 42 );
		a.resize( 23 );
		displayVect( a, "Resize test 5" );
	}
	{
		ft::vector<int> a( 5, 42 );
		a.resize( 23, 11 );
		displayVect( a, "Resize test 6" );
	}
	{
		ft::vector<int> a;
		a.resize( 5 );
		displayVect( a, "Resize test 7" );
	}
	{
		ft::vector<int> a;
		a.resize( 5, 13 );
		displayVect( a, "Resize test 8" );
	}
	{
		ft::vector<int> a;
		std::cout << a.empty() << std::endl;
		a.push_back( 1 );
		std::cout << a.empty() << std::endl;
	}
	{
		ft::vector<int> a( 5 );
		std::cout << a.empty() << std::endl;
		a.resize( 0 );
		std::cout << a.empty() << std::endl;
	}
	{
		ft::vector<int> a;
		a.reserve( 3 );
		displayVect( a, "Reserve test 1" );
	}
	{
		ft::vector<int> a( 2 );
		a.reserve( 5 );
		displayVect( a, "Reserve test 2" );
	}
	{
		ft::vector<int> a( 2, 4 );
		a.reserve( 5 );
		displayVect( a, "Reserve test 3" );
	}
	{
		ft::vector<int> a( 8 );
		a.reserve( 5 );
		displayVect( a, "Reserve test 4" );
	}
	{
		ft::vector<int> a( 8, 4 );
		a.reserve( 3 );
		displayVect( a, "Reserve test 5" );
	}
}

void vectorElementAccessTests( void ) {
	std::cout << "VECTOR ELEMENT ACCESS TESTS:" << std::endl << std::endl;

	{
		ft::vector<int> a;
		a.push_back( 5 );
		a.push_back( 15 );
		a.push_back( 25 );
		a.push_back( 35 );
		for ( size_t i = 0; i < a.size(); i++ )
			std::cout << a[i] << std::endl;
		std::cout << a.at( 1 ) << std::endl;
		std::cout << a.at( 2 ) << std::endl;
		try {
			std::cout << a.at( 10 ) << std::endl;
		}
		catch ( std::out_of_range & e ) {
			std::cout << e.what() << std::endl;
		}
		std::cout << a.front() << std::endl;
		std::cout << a.back() << std::endl;
	}
}

void vectorModifiersTests( void ) {
	std::cout << "VECTOR MODIFIERS TESTS:" << std::endl << std::endl;

	{
		ft::vector<int> a( 10, 42 );
		a.assign( 4, 113 );
		displayVect( a, "Assign test 1" );
	}
	{
		ft::vector<int> a( 10, 42 );
		a.assign( 21, 111 );
		displayVect( a, "Assign test 2" );
	}
	{
		ft::vector<int> a( 10, 42 );
		a.assign( 0, 0 );
		displayVect( a, "Assign test 3" );
	}
	{
		ft::vector<int> a;
		ft::vector<int> b( 10, 42 );
		a.push_back( 5 );
		a.push_back( 15 );
		a.push_back( 25 );
		a.push_back( 35 );
		b.assign( a.begin(), a.end() );
		displayVect( b, "Assign test 4" );
	}
	{
		ft::vector<int> a( 20, 7 );
		ft::vector<int> b( 10, 42 );
		b.assign( a.begin(), a.end() );
		displayVect( b, "Assign test 5" );
	}
	{
		ft::vector<int> a;
		ft::vector<int> b( 10, 42 );
		a.push_back( 5 );
		a.push_back( 15 );
		a.push_back( 25 );
		a.push_back( 35 );
		a.push_back( 5 );
		a.push_back( 15 );
		a.push_back( 25 );
		a.push_back( 35 );
		a.push_back( 5 );
		a.push_back( 15 );
		a.push_back( 25 );
		a.push_back( 35 );
		b.assign( a.begin(), a.end() );
		displayVect( b, "Assign test 6" );
	}
	{
		ft::vector<int> a( 5, 7 );
		a.push_back( 5 );
		displayVect( a, "Push back test 1" );
		a.push_back( 15 );
		displayVect( a, "Push back test 2" );
		a.push_back( 25 );
		displayVect( a, "Push back test 3" );
		a.push_back( 35 );
		displayVect( a, "Push back test 4" );
		a.push_back( 5 );
		displayVect( a, "Push back test 5" );
		a.push_back( 15 );
		displayVect( a, "Push back test 6" );
		a.push_back( 25 );
		displayVect( a, "Push back test 7" );
		a.push_back( 35 );
		displayVect( a, "Push back test 8" );
		a.pop_back();
		displayVect( a, "Pop back test 1" );
		a.pop_back();
		displayVect( a, "Pop back test 2" );
		a.pop_back();
		displayVect( a, "Pop back test 3" );
		a.pop_back();
		displayVect( a, "Pop back test 4" );
		a.pop_back();
		displayVect( a, "Pop back test 5" );
		a.pop_back();
		displayVect( a, "Pop back test 6" );
		a.pop_back();
		displayVect( a, "Pop back test 7" );
		a.pop_back();
		displayVect( a, "Pop back test 8" );
		a.pop_back();
		displayVect( a, "Pop back test 9" );
		a.pop_back();
		displayVect( a, "Pop back test 10" );
		a.pop_back();
		displayVect( a, "Pop back test 11" );
		a.pop_back();
		displayVect( a, "Pop back test 12" );
		a.pop_back();
		displayVect( a, "Pop back test 13" );
	}
	{
		ft::vector<int> a;
		a.insert( a.begin(), 12 );
		displayVect( a, "Insert test 1" );
	}
	{
		ft::vector<int> a( 4, 9 );
		a.insert( a.begin(), 12 );
		displayVect( a, "Insert test 2" );
	}
	{
		ft::vector<int> a( 4, 9 );
		a.insert( a.begin() + 2, 12 );
		displayVect( a, "Insert test 3" );
	}
	{
		ft::vector<int> a( 4, 9 );
		a.insert( a.end() - 1, 12 );
		displayVect( a, "Insert test 4" );
	}
	{
		ft::vector<int> a( 4, 9 );
		a.insert( a.end() - 1, 12 );
		a.insert( a.end() - 1, 12 );
		a.insert( a.end() - 1, 12 );
		a.insert( a.end() - 1, 12 );
		displayVect( a, "Insert test 5" );
	}
	// {
	// 	ft::vector<int> a;
	// 	a.insert( a.begin(), 4, 12 );
	// 	displayVect( a, "Insert test 6" );
	// }
	// {
	// 	ft::vector<int> a( 4, 9 );
	// 	a.insert( a.begin(), 2, 12 );
	// 	displayVect( a, "Insert test 7" );
	// }
	// {
	// 	ft::vector<int> a( 4, 9 );
	// 	a.insert( a.begin() + 2, 6, 12 );
	// 	displayVect( a, "Insert test 8" );
	// }
	// {
	// 	ft::vector<int> a( 4, 9 );
	// 	a.insert( a.end() - 1, 7, 12 );
	// 	displayVect( a, "Insert test 9" );
	// }
	// {
	// 	ft::vector<int> a( 4, 9 );
	// 	a.insert( a.end() - 1, 2, 12 );
	// 	displayVect( a, "Insert test 10" );
	// 	a.insert( a.end() - 1, 3, 12 );
	// 	displayVect( a, "Insert test 11" );
	// 	a.insert( a.end() - 1, 1, 12 );
	// 	displayVect( a, "Insert test 12" );
	// 	a.insert( a.end() - 1, 4, 12 );
	// 	displayVect( a, "Insert test 13" );
	// }
	// {
	// 	ft::vector<int> a;
	// 	a.insert( a.begin(), 0, 12 );
	// 	displayVect( a, "Insert test 14" );
	// }
	// {
	// 	ft::vector<int> a;
	// 	ft::vector<int> b;
	// 	b.push_back( 5 );
	// 	b.push_back( 15 );
	// 	b.push_back( 25 );
	// 	b.push_back( 35 );
	// 	a.insert( a.begin(), b.begin(), b.end() );
	// 	displayVect( a, "Insert test 15" );
	// }
	// {
	// 	ft::vector<int> a;
	// 	ft::vector<int> b;
	// 	a.insert( a.begin(), b.begin(), b.end() );
	// 	displayVect( a, "Insert test 16" );
	// }
	// {
	// 	ft::vector<int> a( 4, 9 );
	// 	ft::vector<int> b;
	// 	b.push_back( 5 );
	// 	b.push_back( 15 );
	// 	b.push_back( 25 );
	// 	b.push_back( 35 );
	// 	a.insert( a.begin(), b.begin(), b.end() );
	// 	displayVect( a, "Insert test 17" );
	// }
	// {
	// 	ft::vector<int> a( 4, 9 );
	// 	ft::vector<int> b;
	// 	b.push_back( 5 );
	// 	b.push_back( 15 );
	// 	b.push_back( 25 );
	// 	b.push_back( 35 );
	// 	a.insert( a.begin() + 2, b.begin(), b.end() );
	// 	displayVect( a, "Insert test 18" );
	// }
	// {
	// 	ft::vector<int> a( 4, 9 );
	// 	ft::vector<int> b;
	// 	b.push_back( 5 );
	// 	b.push_back( 15 );
	// 	b.push_back( 25 );
	// 	b.push_back( 35 );
	// 	a.insert( a.end() - 1, b.begin(), b.end() );
	// 	displayVect( a, "Insert test 19" );
	// }
	// {
	// 	ft::vector<int> a( 4, 9 );
	// 	ft::vector<int> b;
	// 	b.push_back( 5 );
	// 	b.push_back( 15 );
	// 	b.push_back( 25 );
	// 	b.push_back( 35 );
	// 	a.insert( a.end() - 1, b.begin(), b.end() );
	// 	displayVect( a, "Insert test 20" );
	// 	a.insert( a.end() - 1, b.begin(), b.end() );
	// 	displayVect( a, "Insert test 21" );
	// 	a.insert( a.end() - 1, b.begin(), b.end() );
	// 	displayVect( a, "Insert test 22" );
	// 	a.insert( a.end() - 1, b.begin(), b.end() );
	// 	displayVect( a, "Insert test 23" );
	// }
	// {
	// 	ft::vector<int> a( 9, 17 );
	// 	a.erase( a.begin() + 4 );
	// 	displayVect( a, "Erase test 1" );
	// }
	// {
	// 	ft::vector<int> b;
	// 	b.push_back( 5 );
	// 	b.push_back( 15 );
	// 	b.push_back( 25 );
	// 	b.push_back( 35 );
	// 	b.erase( b.begin() );
	// 	displayVect( b, "Erase test 2" );
	// 	b.erase( b.end() - 1 );
	// 	displayVect( b, "Erase test 3" );
	// 	b.erase( b.begin() );
	// 	displayVect( b, "Erase test 4" );
	// 	b.erase( b.begin() );
	// 	displayVect( b, "Erase test 5" );
	// }
	// {
	// 	ft::vector<int> a( 3, 18 );
	// 	ft::vector<int> b( 18, 3 );
	// 	a.swap( b );
	// 	displayVect( a, "Swap test 1" );
	// 	displayVect( b, "Swap test 2" );
	// }
	// {
	// 	ft::vector<int> a;
	// 	ft::vector<int> b;
	// 	b.push_back( 5 );
	// 	b.push_back( 15 );
	// 	b.push_back( 25 );
	// 	b.push_back( 35 );
	// 	a.swap( b );
	// 	displayVect( a, "Swap test 3" );
	// 	displayVect( b, "Swap test 4" );
	// }
	// {
	// 	ft::vector<int> a( 7, 77 );
	// 	ft::vector<int> b;
	// 	b.push_back( 5 );
	// 	b.push_back( 15 );
	// 	b.push_back( 25 );
	// 	b.push_back( 35 );
	// 	a.swap( b );
	// 	displayVect( a, "Swap test 5" );
	// 	displayVect( b, "Swap test 6" );
	// }
	// {
	// 	ft::vector<int> a;
	// 	a.clear();
	// 	displayVect( a, "Clear test 1" );
	// }
	// {
	// 	ft::vector<int> a( 3, 9 );
	// 	a.clear();
	// 	displayVect( a, "Clear test 2" );
	// }
	// {
	// 	ft::vector<int> a;
	// 	a.push_back( 5 );
	// 	a.push_back( 15 );
	// 	a.push_back( 25 );
	// 	a.push_back( 35 );
	// 	a.clear();
	// 	displayVect( a, "Clear test 3" );
	// }
}

int	main(void) {
	// Iterator Tests
	iteratorTests();
	constIteratorTests();
	reverseIteratorTests();
	constReverseIteratorTests();

	// Vector Tests
	vectorConstructorTests();
	vectorIteratorTests();
	vectorCapacityTests();
	vectorElementAccessTests();
	vectorModifiersTests();

	return (0);
}