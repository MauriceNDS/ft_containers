#include <iostream>
#include <deque>

#ifdef STL_CONTAINERS
	#include <iterator>
	#include <vector>
	#include <stack>
	#include <map>
	#include <set>
	namespace ft = std;
#else
	#include "vector.hpp"
	#include "stack.hpp"
	#include "map.hpp"
	#include "set.hpp"
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

template< typename K, typename V, typename Comp >
void displayMap( ft::map<K, V, Comp> &m, std::string test ) {
	std::cout << "=======================================================" << std::endl;
	std::cout << test << std::endl;
	for ( typename ft::map<K, V, Comp>::iterator it = m.begin(); it != m.end(); it++ )
		std::cout << it->first << " " << it->second << std::endl;
	// m.printBT();
	std::cout << std::endl << "size = " << m.size() << std::endl << std::endl;
}

template< typename V, typename Comp >
void displaySet( ft::set<V, Comp> &m, std::string test ) {
	std::cout << "=======================================================" << std::endl;
	std::cout << test << std::endl;
	for ( typename ft::set<V, Comp>::iterator it = m.begin(); it != m.end(); it++ )
		std::cout << *it << std::endl;
	// m.printBT();
	std::cout << std::endl << "size = " << m.size() << std::endl << std::endl;
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

void treeIteratorTests( void ) {
	std::cout << "TREE ITERATOR TESTS:" << std::endl << std::endl;

	{
		std::cout << "Constructors:" << std::endl;
		ft::map<int, int> m;
		m[5] = 5;
		m[15] = 15;
		m[25] = 25;
		m[35] = 35;
		ft::map<int, int>::iterator a;
		ft::map<int, int>::iterator b = m.begin();
		std::cout << b->first << " " << b->second << std::endl;;
		ft::map<int, int>::iterator c( b );
		std::cout << c->first << " " << c->second << std::endl;
		b->second += 10;
		std::cout << b->second << " " << c->second << std::endl;
		a = b;
		std::cout << a->second << " " << b->second << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Equality operators:" << std::endl;
		ft::map<int, std::string> m;
		ft::map<int, int> x;
		std::cout << std::boolalpha << ( x.begin() != x.end() ) << std::endl;
		m[42] = "Hello";
		m[21] = "HellO";
		ft::map<int, std::string>::iterator a = m.begin();
		ft::map<int, std::string>::iterator b = a;
		b++;
		std::cout << (a == b) << std::endl;
		std::cout << (a != b) << std::endl;
		std::cout << (a != a) << std::endl;
		std::cout << (a == a) << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Dereferenable:" << std::endl;
		ft::map<int, int> m;
		m[15] = 15;
		m[5] = 5;
		m[25] = 25;
		m[35] = 35;
		ft::map<int, int>::iterator a = m.begin();
		std::cout << a->first << " " << a->second << std::endl;
		a->second += 42;
		std::cout << a->first << " " << a->second << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Incrementation:" << std::endl;
		ft::map<int, int> m;
		m[5] = 5;
		m[15] = 15;
		m[35] = 35;
		m[25] = 25;
		ft::map<int, int>::iterator a = m.begin();
		std::cout << a->first << " " << a->second << std::endl;
		a++;
		std::cout << a->first << " " << a->second << std::endl;
		++a;
		std::cout << a->first << " " << a->second << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Decrementation:" << std::endl;
		ft::map<int, int> m;
		m[35] = 35;
		m[5] = 5;
		m[15] = 15;
		m[25] = 25;
		ft::map<int, int>::iterator a = m.begin();
		a++;
		a++;
		a++;
		std::cout << a->first << " " << a->second << std::endl;
		a--;
		std::cout << a->first << " " << a->second << std::endl;
		--a;
		std::cout << a->first << " " << a->second << std::endl;
		for ( ft::map<int, int>::iterator it = --m.end(); it != m.begin(); --it )
			std::cout << it->first << " " << it->second << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
}

void constTreeIteratorTests( void ) {
	std::cout << "CONST TREE ITERATOR TESTS:" << std::endl << std::endl;

	{
		std::cout << "Constructors:" << std::endl;
		ft::map<int, int> m;
		m[5] = 5;
		m[15] = 15;
		m[25] = 25;
		m[35] = 35;
		ft::map<int, int>::const_iterator a;
		const ft::map<int, int> cm( m );
		ft::map<int, int>::const_iterator b = cm.begin();
		std::cout << b->first << " " << b->second << std::endl;;
		ft::map<int, int>::const_iterator c( b );
		std::cout << c->first << " " << c->second << std::endl;
		std::cout << b->second << " " << c->second << std::endl;
		a = b;
		std::cout << a->second << " " << b->second << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Equality operators:" << std::endl;
		ft::map<int, std::string> m;
		ft::map<int, int> x;
		std::cout << std::boolalpha << ( x.begin() != x.end() ) << std::endl;
		m[42] = "Hello";
		m[21] = "HellO";
		const ft::map<int, std::string> cm( m );
		ft::map<int, std::string>::const_iterator a = cm.begin();
		ft::map<int, std::string>::const_iterator b = a;
		b++;
		std::cout << (a == b) << std::endl;
		std::cout << (a != b) << std::endl;
		std::cout << (a != a) << std::endl;
		std::cout << (a == a) << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Dereferenable:" << std::endl;
		ft::map<int, int> m;
		m[15] = 15;
		m[5] = 5;
		m[25] = 25;
		m[35] = 35;
		const ft::map<int, int> cm( m );
		ft::map<int, int>::const_iterator a = cm.begin();
		std::cout << a->first << " " << a->second << std::endl;
		std::cout << a->first << " " << a->second << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Incrementation:" << std::endl;
		ft::map<int, int> m;
		m[5] = 5;
		m[15] = 15;
		m[35] = 35;
		m[25] = 25;
		const ft::map<int, int> cm( m );
		ft::map<int, int>::const_iterator a = cm.begin();
		std::cout << a->first << " " << a->second << std::endl;
		a++;
		std::cout << a->first << " " << a->second << std::endl;
		++a;
		std::cout << a->first << " " << a->second << std::endl;
		std::cout << "=======================================================" << std::endl;
	}
	{
		std::cout << "Decrementation:" << std::endl;
		ft::map<int, int> m;
		m[35] = 35;
		m[5] = 5;
		m[15] = 15;
		m[25] = 25;
		const ft::map<int, int> cm( m );
		ft::map<int, int>::const_iterator a = cm.begin();
		a++;
		a++;
		a++;
		std::cout << a->first << " " << a->second << std::endl;
		a--;
		std::cout << a->first << " " << a->second << std::endl;
		--a;
		std::cout << a->first << " " << a->second << std::endl;
		for ( ft::map<int, int>::iterator it = --m.end(); it != --m.begin(); it-- )
			std::cout << it->first << " " << it->second << std::endl;
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
	{
		ft::vector<int> a;
		a.insert( a.begin(), 4, 12 );
		displayVect( a, "Insert test 6" );
	}
	{
		ft::vector<int> a( 4, 9 );
		a.insert( a.begin(), 2, 12 );
		displayVect( a, "Insert test 7" );
	}
	{
		ft::vector<int> a( 4, 9 );
		a.insert( a.begin() + 2, 6, 12 );
		displayVect( a, "Insert test 8" );
	}
	{
		ft::vector<int> a( 4, 9 );
		a.insert( a.end() - 1, 7, 12 );
		displayVect( a, "Insert test 9" );
	}
	{
		ft::vector<int> a( 4, 9 );
		a.insert( a.end() - 1, 2, 12 );
		displayVect( a, "Insert test 10" );
		a.insert( a.end() - 1, 3, 12 );
		displayVect( a, "Insert test 11" );
		a.insert( a.end() - 1, 1, 12 );
		displayVect( a, "Insert test 12" );
		a.insert( a.end() - 1, 4, 12 );
		displayVect( a, "Insert test 13" );
	}
	{
		ft::vector<int> a;
		a.insert( a.begin(), 0, 12 );
		displayVect( a, "Insert test 14" );
	}
	{
		ft::vector<int> a;
		ft::vector<int> b;
		b.push_back( 5 );
		b.push_back( 15 );
		b.push_back( 25 );
		b.push_back( 35 );
		a.insert( a.begin(), b.begin(), b.end() );
		displayVect( a, "Insert test 15" );
	}
	{
		ft::vector<int> a;
		ft::vector<int> b;
		a.insert( a.begin(), b.begin(), b.end() );
		displayVect( a, "Insert test 16" );
	}
	{
		ft::vector<int> a( 4, 9 );
		ft::vector<int> b;
		b.push_back( 5 );
		b.push_back( 15 );
		b.push_back( 25 );
		b.push_back( 35 );
		a.insert( a.begin(), b.begin(), b.end() );
		displayVect( a, "Insert test 17" );
	}
	{
		ft::vector<int> a( 4, 9 );
		ft::vector<int> b;
		b.push_back( 5 );
		b.push_back( 15 );
		b.push_back( 25 );
		b.push_back( 35 );
		a.insert( a.begin() + 2, b.begin(), b.end() );
		displayVect( a, "Insert test 18" );
	}
	{
		ft::vector<int> a( 4, 9 );
		ft::vector<int> b;
		b.push_back( 5 );
		b.push_back( 15 );
		b.push_back( 25 );
		b.push_back( 35 );
		a.insert( a.end() - 1, b.begin(), b.end() );
		displayVect( a, "Insert test 19" );
	}
	{
		ft::vector<int> a( 4, 9 );
		ft::vector<int> b;
		b.push_back( 5 );
		b.push_back( 15 );
		b.push_back( 25 );
		b.push_back( 35 );
		a.insert( a.end() - 1, b.begin(), b.end() );
		displayVect( a, "Insert test 20" );
		a.insert( a.end() - 1, b.begin(), b.end() );
		displayVect( a, "Insert test 21" );
		a.insert( a.end() - 1, b.begin(), b.end() );
		displayVect( a, "Insert test 22" );
		a.insert( a.end() - 1, b.begin(), b.end() );
		displayVect( a, "Insert test 23" );
	}
	{
		ft::vector<int> a( 9, 17 );
		a.erase( a.begin() + 4 );
		displayVect( a, "Erase test 1" );
	}
	{
		ft::vector<int> b;
		b.push_back( 5 );
		b.push_back( 15 );
		b.push_back( 25 );
		b.push_back( 35 );
		b.erase( b.begin() );
		displayVect( b, "Erase test 2" );
		b.erase( b.end() - 1 );
		displayVect( b, "Erase test 3" );
		b.erase( b.begin() );
		displayVect( b, "Erase test 4" );
		b.erase( b.begin() );
		displayVect( b, "Erase test 5" );
	}
	{
		ft::vector<int> a( 3, 18 );
		ft::vector<int> b( 18, 3 );
		a.swap( b );
		displayVect( a, "Swap test 1" );
		displayVect( b, "Swap test 2" );
	}
	{
		ft::vector<int> a;
		ft::vector<int> b;
		b.push_back( 5 );
		b.push_back( 15 );
		b.push_back( 25 );
		b.push_back( 35 );
		a.swap( b );
		displayVect( a, "Swap test 3" );
		displayVect( b, "Swap test 4" );
	}
	{
		ft::vector<int> a( 7, 77 );
		ft::vector<int> b;
		b.push_back( 5 );
		b.push_back( 15 );
		b.push_back( 25 );
		b.push_back( 35 );
		a.swap( b );
		displayVect( a, "Swap test 5" );
		displayVect( b, "Swap test 6" );
	}
	{
		ft::vector<int> a;
		a.clear();
		displayVect( a, "Clear test 1" );
	}
	{
		ft::vector<int> a( 3, 9 );
		a.clear();
		displayVect( a, "Clear test 2" );
	}
	{
		ft::vector<int> a;
		a.push_back( 5 );
		a.push_back( 15 );
		a.push_back( 25 );
		a.push_back( 35 );
		a.clear();
		displayVect( a, "Clear test 3" );
	}
	{
		ft::vector<int> a;
		a.push_back( 5 );
		a.push_back( 15 );
		a.push_back( 25 );
		a.push_back( 35 );
		a.clear();
		a.clear();
		displayVect( a, "Clear test 4" );
	}
}

void vectorNonMemberOverloadsTests( void ) {
	std::cout << "VECTOR NON MEMBER OVERLOADS TESTS:" << std::endl << std::endl;

	{
		ft::vector<int> foo ( 3,100 );
		ft::vector<int> bar ( 2,200 );

		if ( foo == bar ) std::cout << "foo and bar are equal" << std::endl;
		if ( foo != bar ) std::cout << "foo and bar are not equal" << std::endl;
		if ( foo < bar ) std::cout << "foo is less than bar" << std::endl;
		if ( foo > bar ) std::cout << "foo is greater than bar" << std::endl;
		if ( foo <= bar ) std::cout << "foo is less than or equal to bar" << std::endl;
		if ( foo >= bar ) std::cout << "foo is greater than or equal to bar" << std::endl;
	}
	{
		ft::vector<int> foo ( 4,100 );
		ft::vector<int> bar ( 4,100 );

		if ( foo == bar ) std::cout << "foo and bar are equal" << std::endl;
		if ( foo != bar ) std::cout << "foo and bar are not equal" << std::endl;
		if ( foo < bar ) std::cout << "foo is less than bar" << std::endl;
		if ( foo > bar ) std::cout << "foo is greater than bar" << std::endl;
		if ( foo <= bar ) std::cout << "foo is less than or equal to bar" << std::endl;
		if ( foo >= bar ) std::cout << "foo is greater than or equal to bar" << std::endl;
	}
	{
		ft::vector<int> foo ( 4,400 );
		ft::vector<int> bar ( 2,100 );

		if ( foo == bar ) std::cout << "foo and bar are equal" << std::endl;
		if ( foo != bar ) std::cout << "foo and bar are not equal" << std::endl;
		if ( foo < bar ) std::cout << "foo is less than bar" << std::endl;
		if ( foo > bar ) std::cout << "foo is greater than bar" << std::endl;
		if ( foo <= bar ) std::cout << "foo is less than or equal to bar" << std::endl;
		if ( foo >= bar ) std::cout << "foo is greater than or equal to bar" << std::endl;
	}
	{
		ft::vector<int> foo ( 2,100 );
		ft::vector<int> bar ( 4,400 );

		if ( foo == bar ) std::cout << "foo and bar are equal" << std::endl;
		if ( foo != bar ) std::cout << "foo and bar are not equal" << std::endl;
		if ( foo < bar ) std::cout << "foo is less than bar" << std::endl;
		if ( foo > bar ) std::cout << "foo is greater than bar" << std::endl;
		if ( foo <= bar ) std::cout << "foo is less than or equal to bar" << std::endl;
		if ( foo >= bar ) std::cout << "foo is greater than or equal to bar" << std::endl;
	}
	{
		ft::vector<int> foo ( 4,400 );
		ft::vector<int> bar ( 2,100 );
		ft::swap( foo, bar );
		displayVect( foo, "Swap test 1.1" );
		displayVect( bar, "Swap test 1.2" );
	}
	{
		ft::vector<int> foo ( 2,100 );
		ft::vector<int> bar ( 4,400 );
		ft::swap( foo, bar );
		displayVect( foo, "Swap test 2.1" );
		displayVect( bar, "Swap test 2.2" );
	}
	{
		ft::vector<int> foo ( 4,100 );
		ft::vector<int> bar ( 4,100 );
		ft::swap( foo, bar );
		displayVect( foo, "Swap test 3.1" );
		displayVect( bar, "Swap test 3.2" );
	}
	{
		ft::vector<int> foo ( 3,100 );
		ft::vector<int> bar ( 2,200 );
		ft::swap( foo, bar );
		displayVect( foo, "Swap test 4.1" );
		displayVect( bar, "Swap test 4.2" );
	}
}

void stackConstructorTests( void ) {
	std::cout << "STACK CONSTRUCTOR TESTS:" << std::endl << std::endl;

	{
		std::deque<int> mydeque( 3, 100 );
		ft::vector<int> myvector( 2, 200 );

		ft::stack<int> first;
		ft::stack<int,ft::vector<int> > second( myvector );

		ft::stack<int,std::deque<int> > third;
		ft::stack<int,std::deque<int> > fourth( mydeque );

		std::cout << "size of first: " << first.size() << std::endl;
		std::cout << "size of second: " << second.size() << std::endl;
		std::cout << "size of third: " << third.size() << std::endl;
		std::cout << "size of fourth: " << fourth.size() << std::endl;
		std::cout << "second top: " << second.top() << std::endl;
		std::cout << "fourth top: " << fourth.top() << std::endl;
	}
}

void stackMemberFunctionTests( void ) {
	std::cout << "STACK MEMBER FUNCTION TESTS:" << std::endl << std::endl;

	{
		std::cout << "Empty tests" << std::endl << std::endl;
		std::cout << "=======================================================" << std::endl;
		ft::stack<int> stk;
		std::cout << std::boolalpha << stk.empty() << std::endl;
		stk.push( 42 );
		std::cout << std::boolalpha << stk.empty() << std::endl;
		stk.pop();
		std::cout << std::boolalpha << stk.empty() << std::endl;
	}
	{
		ft::stack<int> mystack;
		int sum( 0 );
		for ( int i = 1; i <= 10; i++ )
			mystack.push( i );
		while ( !mystack.empty() ) {
			sum += mystack.top();
			mystack.pop();
		}
		std::cout << "total: " << sum << std::endl;
	}
	{
		std::cout << "Size tests" << std::endl << std::endl;
		std::cout << "=======================================================" << std::endl;
		ft::stack<int> mystack;
		std::cout << mystack.size() << std::endl;
		mystack.push( 1 );
		std::cout << mystack.size() << std::endl;
		mystack.push( 4 );
		std::cout << mystack.size() << std::endl;
		mystack.pop();
		std::cout << mystack.size() << std::endl;
		mystack.pop();
		std::cout << mystack.size() << std::endl;
	}
	{
		ft::stack<int> mystack;
		for ( size_t i = 0; i < 100; i++ )
			mystack.push( i );
		std::cout << mystack.size() << std::endl;
		for ( size_t i = 0; i < 42; i++ )
			mystack.pop();
		std::cout << mystack.size() << std::endl;
		while ( !mystack.empty() )
			mystack.pop();
		std::cout << mystack.size() << std::endl;
	}
	{
		std::cout << "Top tests" << std::endl << std::endl;
		std::cout << "=======================================================" << std::endl;
		ft::stack<int> mystack;
		mystack.push( 1 );
		std::cout << mystack.top() << std::endl;
		mystack.push( 4 );
		std::cout << mystack.top() << std::endl;
		mystack.pop();
		std::cout << mystack.top() << std::endl;
	}
	{
		ft::stack<int> mystack;
		for ( size_t i = 0; i < 100; i++ )
			mystack.push( i );
		std::cout << mystack.top() << std::endl;
		for ( size_t i = 0; i < 42; i++ )
			mystack.pop();
		std::cout << mystack.top() << std::endl;
		while ( !mystack.empty() )
			mystack.pop();
	}
	{
		std::cout << "Push and pop tests" << std::endl << std::endl;
		std::cout << "=======================================================" << std::endl;
		ft::stack<int> a;
		a.push( 42 );
		std::cout << a.top() << " " << a.size() << std::endl;
		a.push( 29 );
		std::cout << a.top() << " " << a.size() << std::endl;
		a.push( 41 );
		std::cout << a.top() << " " << a.size() << std::endl;
		a.push( 79 );
		std::cout << a.top() << " " << a.size() << std::endl;
		a.pop();
		std::cout << a.top() << " " << a.size() << std::endl;
		a.pop();
		std::cout << a.top() << " " << a.size() << std::endl;
		a.pop();
		std::cout << a.top() << " " << a.size() << std::endl;
		a.pop();
	}
	{
		ft::stack<int> a;
		for ( size_t i = 0; i < 42; i++ ) {
			a.push( i * 3 );
			std::cout << a.top() << " " << a.size() << std::endl;
		}
	}
}

void stackNonMemberOverloadsTests( void ) {
	std::cout << "STACK NON MEMBER OVERLOADS TESTS:" << std::endl << std::endl;

	{
		ft::stack<int> foo;
		ft::stack<int> bar;
		std::cout << std::boolalpha << ( foo == bar ) << std::endl;
		std::cout << std::boolalpha << ( foo != bar ) << std::endl;
		std::cout << std::boolalpha << ( foo < bar ) << std::endl;
		std::cout << std::boolalpha << ( foo <= bar ) << std::endl;
		std::cout << std::boolalpha << ( foo > bar ) << std::endl;
		std::cout << std::boolalpha << ( foo >= bar ) << std::endl;
		foo.push( 42 );
		foo.push( 84 );
		std::cout << std::boolalpha << ( foo == bar ) << std::endl;
		std::cout << std::boolalpha << ( foo != bar ) << std::endl;
		std::cout << std::boolalpha << ( foo < bar ) << std::endl;
		std::cout << std::boolalpha << ( foo <= bar ) << std::endl;
		std::cout << std::boolalpha << ( foo > bar ) << std::endl;
		std::cout << std::boolalpha << ( foo >= bar ) << std::endl;
		bar.push( 42 );
		bar.push( 84 );
		std::cout << std::boolalpha << ( foo == bar ) << std::endl;
		std::cout << std::boolalpha << ( foo != bar ) << std::endl;
		std::cout << std::boolalpha << ( foo < bar ) << std::endl;
		std::cout << std::boolalpha << ( foo <= bar ) << std::endl;
		std::cout << std::boolalpha << ( foo > bar ) << std::endl;
		std::cout << std::boolalpha << ( foo >= bar ) << std::endl;
		foo.pop();
		std::cout << std::boolalpha << ( foo == bar ) << std::endl;
		std::cout << std::boolalpha << ( foo != bar ) << std::endl;
		std::cout << std::boolalpha << ( foo < bar ) << std::endl;
		std::cout << std::boolalpha << ( foo <= bar ) << std::endl;
		std::cout << std::boolalpha << ( foo > bar ) << std::endl;
		std::cout << std::boolalpha << ( foo >= bar ) << std::endl;
	}
}

bool fncomp( char lhs, char rhs ) {
	return lhs > rhs;
}

struct classcomp {
  bool operator()( const char& lhs, const char& rhs ) const {
		return lhs > rhs;
	}
};

void mapConstructorTests( void ) {
	std::cout << "MAP CONSTRUCTOR TESTS:" << std::endl << std::endl;

	{
		ft::map<char,int> first;
		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		displayMap( first, "Constructor test 1" );

		ft::map<char,int> second( first.begin(), first.end() );
		displayMap( second, "Constructor test 2" );

		ft::map<char,int> third( second );
		displayMap( third, "Constructor test 3" );

		ft::map<char,int,classcomp> fourth;
		fourth['d']=70;
		fourth['a']=10;
		fourth['b']=30;
		fourth['c']=50;
		displayMap( fourth, "Constructor test 4" );

		bool(*fn_pt)(char,char) = fncomp;
		ft::map<char,int,bool(*)(char,char)> fifth( fn_pt );
		fifth['d']=70;
		fifth['b']=30;
		fifth['c']=50;
		fifth['a']=10;
		displayMap( fifth, "Constructor test 5" );
	}
}

void mapIteratorTests( void ) {
	std::cout << "MAP ITERATOR TESTS:" << std::endl << std::endl;

	{
		ft::map<int, int> a;
		a[5] = 5;
		a[15] = 15;
		a[25] = 25;
		a[35] = 35;
		std::cout << a.begin()->first << std::endl;
		std::cout << (a.begin()++)->first << std::endl;
		std::cout << a.rbegin()->first << std::endl;
		std::cout << (a.rbegin()++)->first << std::endl;
	}
}

void mapCapacityTests( void ) {
	std::cout << "MAP CAPACITY TESTS:" << std::endl << std::endl;

	{
		ft::map<int, int> a;
		ft::map<char, char> b;

		std::cout << a.max_size() << std::endl;
		std::cout << b.max_size() << std::endl;
		a[2] = 2;
		b['a'] = 'a';
		std::cout << a.max_size() << std::endl;
		std::cout << b.max_size() << std::endl;
		displayMap( a, "Max_size test" );
		displayMap( b, "Max_size test" );
	}
	{
		ft::map<int, int> a;
		std::cout << std::boolalpha << a.empty() << std::endl;
		displayMap( a, "size test 1" );
		a[5] = 5;
		std::cout << std::boolalpha << a.empty() << std::endl;
		displayMap( a, "size test 2" );
		a[1] = 1;
		a[2] = 2;
		std::cout << std::boolalpha << a.empty() << std::endl;
		displayMap( a, "size test 3" );
		a[-42] = -42;
		a[-10] = -10;
		a[10] = 10;
		std::cout << std::boolalpha << a.empty() << std::endl;
		displayMap( a, "size test 4" );
	}
}

void mapElementAccessTests( void ) {
	std::cout << "MAP ELEMENT ACCESS TESTS:" << std::endl << std::endl;

	{
		ft::map<int, int> a;
		a[2];
		a[2] = 21;
		displayMap( a, "Element access test 1" );
		a[5] = 5;
		a[6] = 6;
		a[8] = 8;
		displayMap( a, "Element access test 2" );
		a[-8] = -8;
		a[12] = 12;
		a[55] = 55;
		displayMap( a, "Element access test 3" );
	}
	{
		ft::map<std::string, std::string> a;
		a["hi"] = "Hello world!";
		a["bye"] = "Good bye";
		displayMap( a, "Element access test 4" );
		a["ty"] = "Thank you";
		a["np"] = "You are welcome";
		displayMap( a, "Element access test 5" );
		std::cout << a["ty"] << std::endl;
		std::cout << a["np"] << std::endl;
		std::cout << a["bye"] << std::endl;
		std::cout << a["hi"] << std::endl;
		std::cout << a["hi"] << std::endl;
		std::cout << a["wtf"] << std::endl;
	}
}

void mapModifiersTests( void ) {
	std::cout << "MAP MODIFIERS TESTS:" << std::endl << std::endl;

	{
		ft::map<int, int> a;
		displayMap( a, "Insert test 1" );
		a.insert( ft::make_pair<int, int>( 5, 5 ) );
		a.insert( ft::make_pair<int, int>( 15, 15 ) );
		a.insert( ft::make_pair<int, int>( 25, 25 ) );
		a.insert( ft::make_pair<int, int>( 35, 35 ) );
		a.insert( ft::make_pair<int, int>( 45, 45 ) );
		a.insert( ft::make_pair<int, int>( 55, 55 ) );
		a.insert( ft::make_pair<int, int>( 65, 65 ) );
		displayMap( a, "Insert test 2" );
		a.insert( ft::make_pair<int, int>( 75, 75 ) );
		a.insert( ft::make_pair<int, int>( 85, 85 ) );
		a.insert( ft::make_pair<int, int>( 95, 95 ) );
		a.insert( ft::make_pair<int, int>( 1, 1 ) );
		a.insert( ft::make_pair<int, int>( 95, 95 ) );
		displayMap( a, "Insert test 3" );
	}
	{
		ft::map<int, int> a;
		a.insert( ft::make_pair<int, int>( 95, 95 ) );
		a.insert( ft::make_pair<int, int>( 5, 5 ) );
		a.insert( ft::make_pair<int, int>( 65, 65 ) );
		a.insert( ft::make_pair<int, int>( 85, 85 ) );
		displayMap( a, "Insert test 4" );
		a.insert( ft::make_pair<int, int>( 55, 55 ) );
		a.insert( ft::make_pair<int, int>( 95, 95 ) );
		a.insert( ft::make_pair<int, int>( 25, 25 ) );
		a.insert( ft::make_pair<int, int>( 45, 45 ) );
		displayMap( a, "Insert test 5" );
		a.insert( ft::make_pair<int, int>( 15, 15 ) );
		a.insert( ft::make_pair<int, int>( 1, 1 ) );
		a.insert( ft::make_pair<int, int>( 35, 35 ) );
		a.insert( ft::make_pair<int, int>( 75, 75 ) );
		displayMap( a, "Insert test 6" );
	}
	{
		ft::map<int, int> a;
		ft::map<int, int> b;
		a.insert( ft::make_pair<int, int>( 15, 15 ) );
		a.insert( ft::make_pair<int, int>( 25, 25 ) );
		a.insert( ft::make_pair<int, int>( 95, 95 ) );
		a.insert( ft::make_pair<int, int>( 95, 95 ) );
		a.insert( ft::make_pair<int, int>( 95, 95 ) );
		a.insert( ft::make_pair<int, int>( 95, 95 ) );
		a.insert( ft::make_pair<int, int>( 95, 95 ) );
		displayMap( a, "Insert test 7" );
		b.insert( a.begin(), a.end() );
		displayMap( b, "Insert test 7.5" );
	}
	{
		ft::map<int, int> a;
		ft::map<int, int> b;
		a.insert( ft::make_pair<int, int>( 30, 30 ) );
		a.insert( ft::make_pair<int, int>( 40, 40 ) );
		a.insert( ft::make_pair<int, int>( 20, 20 ) );
		displayMap( a, "Insert test 8" );
		a.insert( a.begin(), ft::make_pair<int, int>( 50, 50 ) );
		a.insert( a.begin(), ft::make_pair<int, int>( 10, 10 ) );
		a.insert( a.begin(), ft::make_pair<int, int>( 60, 60 ) );
		a.insert( a.begin(), ft::make_pair<int, int>( 0, 0 ) );
		a.insert( a.begin(), ft::make_pair<int, int>( 55, 55 ) );
		a.insert( a.begin(), ft::make_pair<int, int>( 5, 5 ) );
		displayMap( a, "Insert test 9" );
		a.insert( a.begin(), ft::make_pair<int, int>( 45, 45 ) );
		a.insert( a.begin(), ft::make_pair<int, int>( 15, 15 ) );
		a.insert( a.begin(), ft::make_pair<int, int>( 52, 52 ) );
		a.insert( a.begin(), ft::make_pair<int, int>( 8, 8 ) );
		displayMap( a, "Insert test 10" );
		a.insert( a.begin(), ft::make_pair<int, int>( 45, 45 ) );
		a.insert( a.begin(), ft::make_pair<int, int>( 15, 15 ) );
		a.insert( a.begin(), ft::make_pair<int, int>( 52, 52 ) );
		a.insert( a.begin(), ft::make_pair<int, int>( 8, 8 ) );
		displayMap( a, "Insert test 11" );
		ft::map<int, int>::iterator it = a.begin()++;
		it++;
		a.insert( it, ft::make_pair<int, int>( 18, 18 ) );
		displayMap( a, "Insert test 12" );
		a.insert( it, ft::make_pair<int, int>( 33, 33 ) );
		displayMap( a, "Insert test 13" );
		for ( size_t i = 0; i < 8; i++ )
			it++;
		std::cout << it->first << " " << it->second << std::endl;
		a.insert( it, ft::make_pair<int, int>( 51, 51 ) );
		displayMap( a, "Insert test 14" );
		a.insert( it, ft::make_pair<int, int>( 38, 38 ) );
		a.insert( it, ft::make_pair<int, int>( 49, 49 ) );
		displayMap( a, "Insert test 15" );
		b.insert( a.begin(), it );
		std::cout << it->first << " " << it->second << std::endl;
		displayMap( b, "Insert test 16" );
		b.insert( a.begin(), a.end() );
		displayMap( b, "Insert test 17" );
		displayMap( a, "Insert test 18" );
		std::cout << 18 << std::endl;
		a.erase( 18 );
		displayMap( a, "Erase test 1" );
		std::cout << 10 << std::endl;
		a.erase( 10 );
		displayMap( a, "Erase test 2" );
		std::cout << 33 << std::endl;
		a.erase( 33 );
		displayMap( a, "Erase test 3" );
		std::cout << 45 << std::endl;
		a.erase( 45 );
		displayMap( a, "Erase test 4" );
		std::cout << 60 << std::endl;
		a.erase( 60 );
		displayMap( a, "Erase test 5" );
		std::cout << 40 << std::endl;
		a.erase( 40 );
		displayMap( a, "Erase test 6" );
		std::cout << 50 << std::endl;
		a.erase( 50 );
		displayMap( a, "Erase test 7" );
		std::cout << 30 << std::endl;
		a.erase( 30 );
		displayMap( a, "Erase test 8" );
		std::cout << 15 << std::endl;
		a.erase( 15 );
		displayMap( a, "Erase test 9" );
		std::cout << 55 << std::endl;
		a.erase( 55 );
		displayMap( a, "Erase test 10" );
		std::cout << 0 << std::endl;
		a.erase( 0 );
		displayMap( a, "Erase test 11" );
		std::cout << 5 << std::endl;
		a.erase( 5 );
		displayMap( a, "Erase test 12" );
		std::cout << 38 << std::endl;
		a.erase( 38 );
		displayMap( a, "Erase test 13" );
		std::cout << 49 << std::endl;
		a.erase( 49 );
		displayMap( a, "Erase test 14" );
		std::cout << 8 << std::endl;
		a.erase( 8 );
		displayMap( a, "Erase test 15" );
		std::cout << 20 << std::endl;
		a.erase( 20 );
		displayMap( a, "Erase test 16" );
		std::cout << 51 << std::endl;
		a.erase( 51 );
		displayMap( a, "Erase test 17" );
		std::cout << 52 << std::endl;
		a.erase( 52 );
		displayMap( a, "Erase test 18" );
		std::cout << 52 << std::endl;
		a.erase( 52 );
		displayMap( a, "Erase test 19" );
	}
	{
		ft::map<int, int> a;
		a.insert( ft::make_pair<int, int>( 42, 42 ) );
		a.insert( ft::make_pair<int, int>( 64, 64 ) );
		a.insert( ft::make_pair<int, int>( 83, 83 ) );
		a.insert( ft::make_pair<int, int>( 10, 10 ) );
		a.insert( ft::make_pair<int, int>( 7, 7 ) );
		a.insert( ft::make_pair<int, int>( 50, 50 ) );
		a.insert( ft::make_pair<int, int>( 29, 29 ) );
		a.insert( ft::make_pair<int, int>( 5, 5 ) );
		a.insert( ft::make_pair<int, int>( 31, 31 ) );
		displayMap( a, "Pre Erase" );
		a.erase( 5 );
		displayMap( a, "Erase test 20" );
		a.erase( 10 );
		displayMap( a, "Erase test 21" );
		a.erase( 31 );
		displayMap( a, "Erase test 22" );
		a.erase( 7 );
		displayMap( a, "Erase test 23" );
		a.erase( 29 );
		displayMap( a, "Erase test 24" );
		std::cout << "Every node, from last to first:" << std::endl;
		for (ft::map<int, int>::reverse_iterator it = a.rbegin(); it != a.rend(); ++it)
			std::cout << it->first << "=>" << it->second << std::endl;
		std::cout << std::endl;
		a.erase( a.begin(), a.end() );
		displayMap( a, "Erase test 25" );
	}
	{
		ft::map<int, int> a;
		a.insert( ft::make_pair<int, int>( 42, 42 ) );
		a.insert( ft::make_pair<int, int>( 64, 64 ) );
		a.insert( ft::make_pair<int, int>( 83, 83 ) );
		a.insert( ft::make_pair<int, int>( 10, 10 ) );
		a.insert( ft::make_pair<int, int>( 7, 7 ) );
		a.insert( ft::make_pair<int, int>( 50, 50 ) );
		a.insert( ft::make_pair<int, int>( 29, 29 ) );
		a.insert( ft::make_pair<int, int>( 5, 5 ) );
		a.insert( ft::make_pair<int, int>( 31, 31 ) );
		ft::map<int, int> b( a );
		ft::map<int, int> c;
		displayMap( a, "Erase test 26" );
		ft::map<int, int>::iterator it = a.begin();
		it++;
		it++;
		it++;
		a.erase( a.begin(), it );
		displayMap( a, "Erase test 27" );
		a.swap( b );
		displayMap( a, "Swap test 1" );
		displayMap( b, "Swap test 2" );
		a.swap( c );
		displayMap( a, "Swap test 3" );
		displayMap( c, "Swap test 4" );
		a.clear();
		b.clear();
		c.clear();
		displayMap( a, "Clear test 1" );
		displayMap( b, "Clear test 2" );
		displayMap( c, "Clear test 3" );
	}
	{
		ft::map<int, int> a;
		displayMap( a, "Clear test 4" );
		a.insert( ft::make_pair<int, int>( 42, 42 ) );
		a.insert( ft::make_pair<int, int>( 64, 64 ) );
		a.insert( ft::make_pair<int, int>( 83, 83 ) );
		a.insert( ft::make_pair<int, int>( 10, 10 ) );
		a.insert( ft::make_pair<int, int>( 7, 7 ) );
		a.insert( ft::make_pair<int, int>( 50, 50 ) );
		a.insert( ft::make_pair<int, int>( 29, 29 ) );
		a.insert( ft::make_pair<int, int>( 5, 5 ) );
		a.insert( ft::make_pair<int, int>( 31, 31 ) );
		a.clear();
		displayMap( a, "Clear test 5" );
	}
	{
		ft::map<char, int, classcomp> a;
		ft::pair<char, int> p1( 'f', 10 ), p2( 'h', 20 );
		ft::pair<char, int> p3( 'z', 10 ), p4( 'a', 20 );
		std::cout << std::boolalpha << a.key_comp()( 'f', 'h' ) << std::endl;
		std::cout << std::boolalpha << a.key_comp()( 'z', 'a' ) << std::endl;
		std::cout << std::boolalpha << a.value_comp()( p1, p2 ) << std::endl;
		std::cout << std::boolalpha << a.value_comp()( p3, p4 ) << std::endl;
	}
}

void mapOperationsTests( void ) {
	std::cout << "MAP OPERATIONS TESTS:" << std::endl << std::endl;

	{
		ft::map<int, int> a;
		a.insert( ft::make_pair<int, int>( 42, 42 ) );
		a.insert( ft::make_pair<int, int>( 64, 64 ) );
		a.insert( ft::make_pair<int, int>( 83, 83 ) );
		a.insert( ft::make_pair<int, int>( 10, 10 ) );
		a.insert( ft::make_pair<int, int>( 7, 7 ) );
		a.insert( ft::make_pair<int, int>( 50, 50 ) );
		a.insert( ft::make_pair<int, int>( 29, 29 ) );
		a.insert( ft::make_pair<int, int>( 5, 5 ) );
		a.insert( ft::make_pair<int, int>( 31, 31 ) );
		a.insert( ft::make_pair<int, int>( 32, 32 ) );
		const ft::map<int, int> b( a );
		std::cout << a.find( 50 )->first << std::endl;
		std::cout << b.find( 50 )->first << std::endl;
		std::cout << b.find( 5 )->first << std::endl;
		std::cout << a.find( 5 )->first << std::endl;
		std::cout << b.find( 10 )->first << std::endl;
		std::cout << a.find( 10 )->first << std::endl;
		if ( b.find( 11 ) == b.end() )
			std::cout << std::boolalpha << true << std::endl;
		if ( a.find( 11 ) == a.end() )
			std::cout << std::boolalpha << true << std::endl;
		ft::map<int, int>::iterator it1, it2;
		it1 = a.lower_bound( 100 );
		it2 = a.lower_bound( 11 );
		if ( it1 == a.end() )
			std::cout << std::boolalpha << true << std::endl;
		std::cout << it2->first << " " << it2->first << std::endl;
		it1 = a.lower_bound( -10000 );
		it2 = a.lower_bound( 2 );
		std::cout << it1->first << " " << it1->first << std::endl;
		std::cout << it2->first << " " << it2->first << std::endl;
		it1 = a.lower_bound( 5 );
		it2 = a.lower_bound( 6 );
		std::cout << it1->first << " " << it1->first << std::endl;
		std::cout << it2->first << " " << it2->first << std::endl;
		it1 = a.lower_bound( 40 );
		it2 = a.lower_bound( 20 );
		std::cout << it1->first << " " << it1->first << std::endl;
		std::cout << it2->first << " " << it2->first << std::endl;
		it1 = a.lower_bound( 8 );
		it2 = a.lower_bound( 31 );
		std::cout << it1->first << " " << it1->first << std::endl;
		std::cout << it2->first << " " << it2->first << std::endl;
		std::cout << std::endl;
		it1 = a.upper_bound( 10 );
		it2 = a.upper_bound( 31 );
		std::cout << it1->first << " " << it1->first << std::endl;
		std::cout << it2->first << " " << it2->first << std::endl;
		it1 = a.upper_bound( 32 );
		it2 = a.upper_bound( 0 );
		std::cout << it1->first << " " << it1->first << std::endl;
		std::cout << it2->first << " " << it2->first << std::endl;
		it1 = a.upper_bound( 44 );
		it2 = a.upper_bound( 7 );
		std::cout << it1->first << " " << it1->first << std::endl;
		std::cout << it2->first << " " << it2->first << std::endl;
		it1 = a.upper_bound( 51 );
		it2 = a.upper_bound( 35 );
		std::cout << it1->first << " " << it1->first << std::endl;
		std::cout << it2->first << " " << it2->first << std::endl;
		it1 = a.upper_bound( 80 );
		it2 = a.upper_bound( 47 );
		std::cout << it1->first << " " << it1->first << std::endl;
		std::cout << it2->first << " " << it2->first << std::endl;
		it1 = a.upper_bound( 83 );
		if ( it1 == a.end() )
			std::cout << std::boolalpha << true << std::endl;
		std::cout << std::endl;
		ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> p;
		p = a.equal_range( 29 );
		std::cout << p.first->first << " " << p.second->first << std::endl;
		p = a.equal_range( 30 );
		std::cout << p.first->first << " " << p.second->first << std::endl;
		p = a.equal_range( 4 );
		std::cout << p.first->first << " " << p.second->first << std::endl;
		p = a.equal_range( 5 );
		std::cout << p.first->first << " " << p.second->first << std::endl;
		p = a.equal_range( 32 );
		std::cout << p.first->first << " " << p.second->first << std::endl;
		p = a.equal_range( 42 );
		std::cout << p.first->first << " " << p.second->first << std::endl;
		p = a.equal_range( 43 );
		std::cout << p.first->first << " " << p.second->first << std::endl;
		p = a.equal_range( 82 );
		std::cout << p.first->first << " " << p.second->first << std::endl;
		p = a.equal_range( 83 );
		std::cout << p.first->first << std::endl;
		if ( p.second == a.end() )
			std::cout << std::boolalpha << true << std::endl;
		p = a.equal_range( 100 );
		if ( p.first == a.end() )
			std::cout << std::boolalpha << true << std::endl;
		if ( p.second == a.end() )
			std::cout << std::boolalpha << true << std::endl;
		p = a.equal_range( -100 );
		std::cout << p.first->first << " " << p.second->first << std::endl;
	}
}

void setConstructorTests( void ) {
	std::cout << "SET CONSTRUCTOR TESTS:" << std::endl << std::endl;

	{
		ft::set<char> first;
		first.insert( 'a' );
		first.insert( 'b' );
		first.insert( 'c' );
		first.insert( 'd' );
		displaySet( first, "Constructor test 1" );

		ft::set<char> second( first.begin(), first.end() );
		displaySet( second, "Constructor test 2" );

		ft::set<char> third( second );
		displaySet( third, "Constructor test 3" );

		ft::set<char,classcomp> fourth;
		first.insert( 'd' );
		first.insert( 'a' );
		first.insert( 'b' );
		first.insert( 'c' );
		displaySet( fourth, "Constructor test 4" );

		bool(*fn_pt)(char,char) = fncomp;
		ft::set<char,bool(*)(char,char)> fifth( fn_pt );
		first.insert( 'd' );
		first.insert( 'b' );
		first.insert( 'c' );
		first.insert( 'a' );
		displaySet( fifth, "Constructor test 5" );
	}
}

void setIteratorTests( void ) {
	std::cout << "SET ITERATOR TESTS:" << std::endl << std::endl;

	{
		ft::set<int> a;
		a.insert( 5 );
		a.insert( 15 );
		a.insert( 25 );
		a.insert( 35 );
		std::cout << *a.begin() << std::endl;
		std::cout << *(a.begin()++) << std::endl;
		std::cout << *a.rbegin() << std::endl;
		std::cout << *(a.rbegin()++) << std::endl;
	}
}

void setCapacityTests( void ) {
	std::cout << "SET CAPACITY TESTS:" << std::endl << std::endl;

	{
		ft::set<int> a;
		ft::set<char> b;

		std::cout << a.max_size() << std::endl;
		std::cout << b.max_size() << std::endl;
		a.insert( 2 );
		b.insert( 'a' );
		std::cout << a.max_size() << std::endl;
		std::cout << b.max_size() << std::endl;
		displaySet( a, "Max_size test" );
		displaySet( b, "Max_size test" );
	}
	{
		ft::set<int> a;
		std::cout << std::boolalpha << a.empty() << std::endl;
		displaySet( a, "size test 1" );
		a.insert( 5 );
		std::cout << std::boolalpha << a.empty() << std::endl;
		displaySet( a, "size test 2" );
		a.insert( 1 );
		a.insert( 2 );
		std::cout << std::boolalpha << a.empty() << std::endl;
		displaySet( a, "size test 3" );
		a.insert( -42 );
		a.insert( -10 );
		a.insert( 10 );
		std::cout << std::boolalpha << a.empty() << std::endl;
		displaySet( a, "size test 4" );
	}
}

void setModifiersTests( void ) {
	std::cout << "SET MODIFIERS TESTS:" << std::endl << std::endl;

	{
		ft::set<int> a;
		displaySet( a, "Insert test 1" );
		a.insert( 5 );
		a.insert( 15 );
		a.insert( 25 );
		a.insert( 35 );
		a.insert( 45 );
		a.insert( 55 );
		a.insert( 65 );
		displaySet( a, "Insert test 2" );
		a.insert( 75 );
		a.insert( 85 );
		a.insert( 95 );
		a.insert( 1 );
		a.insert( 95 );
		displaySet( a, "Insert test 3" );
	}
	{
		ft::set<int> a;
		a.insert( 95 );
		a.insert( 5 );
		a.insert( 65 );
		a.insert( 85 );
		displaySet( a, "Insert test 4" );
		a.insert( 55 );
		a.insert( 95 );
		a.insert( 25 );
		a.insert( 45 );
		displaySet( a, "Insert test 5" );
		a.insert( 15 );
		a.insert( 1 );
		a.insert( 35 );
		a.insert( 75 );
		displaySet( a, "Insert test 6" );
	}
	{
		ft::set<int> a;
		ft::set<int> b;
		a.insert( 15 );
		a.insert( 25 );
		a.insert( 95 );
		a.insert( 95 );
		a.insert( 95 );
		a.insert( 95 );
		a.insert( 95 );
		displaySet( a, "Insert test 7" );
		b.insert( a.begin(), a.end() );
		displaySet( b, "Insert test 7.5" );
	}
	{
		ft::set<int> a;
		ft::set<int> b;
		a.insert( 30 );
		a.insert( 40 );
		a.insert( 20 );
		displaySet( a, "Insert test 8" );
		a.insert( a.begin(), 50 );
		a.insert( a.begin(), 10 );
		a.insert( a.begin(), 60 );
		a.insert( a.begin(), 0 );
		a.insert( a.begin(), 55 );
		a.insert( a.begin(), 5 );
		displaySet( a, "Insert test 9" );
		a.insert( a.begin(), 45 );
		a.insert( a.begin(), 15 );
		a.insert( a.begin(), 52 );
		a.insert( a.begin(), 9 );
		displaySet( a, "Insert test 10" );
		a.insert( a.begin(), 45 );
		a.insert( a.begin(), 15 );
		a.insert( a.begin(), 52 );
		a.insert( a.begin(), 9 );
		displaySet( a, "Insert test 11" );
		ft::set<int>::iterator it = a.begin()++;
		it++;
		a.insert( it, 18 );
		displaySet( a, "Insert test 12" );
		a.insert( it, 33 );
		displaySet( a, "Insert test 13" );
		for ( size_t i = 0; i < 8; i++ )
			it++;
		std::cout << *it << std::endl;
		a.insert( it, 51 );
		displaySet( a, "Insert test 14" );
		a.insert( it, 38 );
		a.insert( it, 49 );
		displaySet( a, "Insert test 15" );
		b.insert( a.begin(), it );
		std::cout << *it << std::endl;
		displaySet( b, "Insert test 16" );
		b.insert( a.begin(), a.end() );
		displaySet( b, "Insert test 17" );
		displaySet( a, "Insert test 18" );
		std::cout << 18 << std::endl;
		a.erase( 18 );
		displaySet( a, "Erase test 1" );
		std::cout << 10 << std::endl;
		a.erase( 10 );
		displaySet( a, "Erase test 2" );
		std::cout << 33 << std::endl;
		a.erase( 33 );
		displaySet( a, "Erase test 3" );
		std::cout << 45 << std::endl;
		a.erase( 45 );
		displaySet( a, "Erase test 4" );
		std::cout << 60 << std::endl;
		a.erase( 60 );
		displaySet( a, "Erase test 5" );
		std::cout << 40 << std::endl;
		a.erase( 40 );
		displaySet( a, "Erase test 6" );
		std::cout << 50 << std::endl;
		a.erase( 50 );
		displaySet( a, "Erase test 7" );
		std::cout << 30 << std::endl;
		a.erase( 30 );
		displaySet( a, "Erase test 8" );
		std::cout << 15 << std::endl;
		a.erase( 15 );
		displaySet( a, "Erase test 9" );
		std::cout << 55 << std::endl;
		a.erase( 55 );
		displaySet( a, "Erase test 10" );
		std::cout << 0 << std::endl;
		a.erase( 0 );
		displaySet( a, "Erase test 11" );
		std::cout << 5 << std::endl;
		a.erase( 5 );
		displaySet( a, "Erase test 12" );
		std::cout << 38 << std::endl;
		a.erase( 38 );
		displaySet( a, "Erase test 13" );
		std::cout << 49 << std::endl;
		a.erase( 49 );
		displaySet( a, "Erase test 14" );
		std::cout << 8 << std::endl;
		a.erase( 8 );
		displaySet( a, "Erase test 15" );
		std::cout << 20 << std::endl;
		a.erase( 20 );
		displaySet( a, "Erase test 16" );
		std::cout << 51 << std::endl;
		a.erase( 51 );
		displaySet( a, "Erase test 17" );
		std::cout << 52 << std::endl;
		a.erase( 52 );
		displaySet( a, "Erase test 18" );
		std::cout << 52 << std::endl;
		a.erase( 52 );
		displaySet( a, "Erase test 19" );
	}
	{
		ft::set<int> a;
		a.insert( 42 );
		a.insert( 64 );
		a.insert( 83 );
		a.insert( 10 );
		a.insert( 7 );
		a.insert( 50 );
		a.insert( 29 );
		a.insert( 5 );
		a.insert( 31 );
		displaySet( a, "Pre Erase" );
		a.erase( 5 );
		displaySet( a, "Erase test 20" );
		a.erase( 10 );
		displaySet( a, "Erase test 21" );
		a.erase( 31 );
		displaySet( a, "Erase test 22" );
		a.erase( 7 );
		displaySet( a, "Erase test 23" );
		a.erase( 29 );
		displaySet( a, "Erase test 24" );
		std::cout << "Every node, from last to first:" << std::endl;
		for (ft::set<int>::reverse_iterator it = a.rbegin(); it != a.rend(); ++it)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		a.erase( a.begin(), a.end() );
		displaySet( a, "Erase test 25" );
	}
	{
		ft::set<int> a;
		a.insert( 42 );
		a.insert( 64 );
		a.insert( 83 );
		a.insert( 10 );
		a.insert( 7 );
		a.insert( 50 );
		a.insert( 29 );
		a.insert( 5 );
		a.insert( 31 );
		ft::set<int> b( a );
		ft::set<int> c;
		displaySet( a, "Erase test 26" );
		ft::set<int>::iterator it = a.begin();
		it++;
		it++;
		it++;
		a.erase( a.begin(), it );
		displaySet( a, "Erase test 27" );
		a.swap( b );
		displaySet( a, "Swap test 1" );
		displaySet( b, "Swap test 2" );
		a.swap( c );
		displaySet( a, "Swap test 3" );
		displaySet( c, "Swap test 4" );
		a.clear();
		b.clear();
		c.clear();
		displaySet( a, "Clear test 1" );
		displaySet( b, "Clear test 2" );
		displaySet( c, "Clear test 3" );
	}
	{
		ft::set<int> a;
		displaySet( a, "Clear test 4" );
		a.insert( 42 );
		a.insert( 64 );
		a.insert( 83 );
		a.insert( 10 );
		a.insert( 7 );
		a.insert( 50 );
		a.insert( 29 );
		a.insert( 5 );
		a.insert( 31 );
		a.clear();
		displaySet( a, "Clear test 5" );
	}
	{
		ft::set<char, classcomp> d;
		char f( 'h' ), h( 'h' ), z( 'z' ), a( 'a' );
		std::cout << std::boolalpha << d.key_comp()( f, h ) << std::endl;
		std::cout << std::boolalpha << d.key_comp()( z, a ) << std::endl;
		std::cout << std::boolalpha << d.value_comp()( f, h ) << std::endl;
		std::cout << std::boolalpha << d.value_comp()( z, a ) << std::endl;
	}
}

void setOperationsTests( void ) {
	std::cout << "SET OPERATIONS TESTS:" << std::endl << std::endl;

	{
		ft::set<int> a;
		a.insert( 42 );
		a.insert( 64 );
		a.insert( 83 );
		a.insert( 10 );
		a.insert( 7 );
		a.insert( 50 );
		a.insert( 29 );
		a.insert( 5 );
		a.insert( 31 );
		a.insert( 32 );
		const ft::set<int> b( a );
		std::cout << *a.find( 50 ) << std::endl;
		std::cout << *b.find( 50 ) << std::endl;
		std::cout << *b.find( 5 ) << std::endl;
		std::cout << *a.find( 5 ) << std::endl;
		std::cout << *b.find( 10 ) << std::endl;
		std::cout << *a.find( 10 ) << std::endl;
		if ( a.find( 11 ) == a.end() )
			std::cout << std::boolalpha << true << std::endl;
		ft::set<int>::iterator it1, it2;
		it1 = a.lower_bound( 100 );
		it2 = a.lower_bound( 11 );
		if ( it1 == a.end() )
			std::cout << std::boolalpha << true << std::endl;
		std::cout << *it2 << std::endl;
		it1 = a.lower_bound( -10000 );
		it2 = a.lower_bound( 2 );
		std::cout << *it1 << std::endl;
		std::cout << *it2 << std::endl;
		it1 = a.lower_bound( 5 );
		it2 = a.lower_bound( 6 );
		std::cout << *it1 << std::endl;
		std::cout << *it2 << std::endl;
		it1 = a.lower_bound( 40 );
		it2 = a.lower_bound( 20 );
		std::cout << *it1 << std::endl;
		std::cout << *it2 << std::endl;
		it1 = a.lower_bound( 8 );
		it2 = a.lower_bound( 31 );
		std::cout << *it1 << std::endl;
		std::cout << *it2 << std::endl;
		std::cout << std::endl;
		it1 = a.upper_bound( 10 );
		it2 = a.upper_bound( 31 );
		std::cout << *it1 << std::endl;
		std::cout << *it2 << std::endl;
		it1 = a.upper_bound( 32 );
		it2 = a.upper_bound( 0 );
		std::cout << *it1 << std::endl;
		std::cout << *it2 << std::endl;
		it1 = a.upper_bound( 44 );
		it2 = a.upper_bound( 7 );
		std::cout << *it1 << std::endl;
		std::cout << *it2 << std::endl;
		it1 = a.upper_bound( 51 );
		it2 = a.upper_bound( 35 );
		std::cout << *it1 << std::endl;
		std::cout << *it2 << std::endl;
		it1 = a.upper_bound( 80 );
		it2 = a.upper_bound( 47 );
		std::cout << *it1 << std::endl;
		std::cout << *it2 << std::endl;
		it1 = a.upper_bound( 83 );
		if ( it1 == a.end() )
			std::cout << std::boolalpha << true << std::endl;
		std::cout << std::endl;
		ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> p;
		p = a.equal_range( 29 );
		std::cout << *p.first << " " << *p.second << std::endl;
		p = a.equal_range( 30 );
		std::cout << *p.first << " " << *p.second << std::endl;
		p = a.equal_range( 4 );
		std::cout << *p.first << " " << *p.second << std::endl;
		p = a.equal_range( 5 );
		std::cout << *p.first << " " << *p.second << std::endl;
		p = a.equal_range( 32 );
		std::cout << *p.first << " " << *p.second << std::endl;
		p = a.equal_range( 42 );
		std::cout << *p.first << " " << *p.second << std::endl;
		p = a.equal_range( 43 );
		std::cout << *p.first << " " << *p.second << std::endl;
		p = a.equal_range( 82 );
		std::cout << *p.first << " " << *p.second << std::endl;
		p = a.equal_range( 83 );
		std::cout << *p.first << std::endl;
		if ( p.second == a.end() )
			std::cout << std::boolalpha << true << std::endl;
		p = a.equal_range( 100 );
		if ( p.first == a.end() )
			std::cout << std::boolalpha << true << std::endl;
		if ( p.second == a.end() )
			std::cout << std::boolalpha << true << std::endl;
		p = a.equal_range( -100 );
		std::cout << *p.first << " " << *p.second << std::endl;
	}
}

int	main(void) {
	// Iterator Tests
	iteratorTests();
	constIteratorTests();
	reverseIteratorTests();
	constReverseIteratorTests();
	treeIteratorTests();
	constTreeIteratorTests();

	// Vector Tests
	vectorConstructorTests();
	vectorIteratorTests();
	vectorCapacityTests();
	vectorElementAccessTests();
	vectorModifiersTests();
	vectorNonMemberOverloadsTests();

	// Stack Tests
	stackConstructorTests();
	stackMemberFunctionTests();
	stackNonMemberOverloadsTests();

	// Map Tests
	mapConstructorTests();
	mapIteratorTests();
	mapCapacityTests();
	mapElementAccessTests();
	mapModifiersTests();
	mapOperationsTests();

	// Set Tests
	setConstructorTests();
	setIteratorTests();
	setCapacityTests();
	setModifiersTests();
	setOperationsTests();
	return (0);
}