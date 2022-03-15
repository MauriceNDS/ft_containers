#include <iostream>

#ifdef STL_CONTAINERS
	#include <iterator>
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

template<typename T>
void	displayVect( ft::vector<T> vect, std::string test ) {
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

int	main(void) {
	iteratorTests();
	constIteratorTests();
	reverseIteratorTests();
	constReverseIteratorTests();
	vectorConstructorTests();

	return (0);
}