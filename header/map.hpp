#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <memory>
#include "iterator.hpp"

namespace ft {

	template <class T>
	struct tree_node {

		T			value;
		tree_node*	parent;
		tree_node*	left;
		tree_node*	right;

		tree_node( void ) : parent( NULL ), left( NULL ), right( NULL ) {}
		tree_node( T val ) : value( val ), parent( NULL ), left( NULL ), right( NULL ) {}

	};

	template <class T1, class T2>
	struct pair {

		first_type						first;
		second_type						second;
		
		typedef T1						first_type;
		typedef T2						second_type;

		pair( void ) {}

		template<class U, class V>
		pair( const pair<U,V>& pr ) {
			*this = pr;
		}

		pair( const first_type& a, const second_type& b ) : first( a.first ), second( b.second ) {}

		pair& operator=( const pair& pr ) {
			first = pr.first;
			second = pr.second;
		}

	};

	template <class T1, class T2>
	pair<T1,T2> make_pair( T1 x, T2 y ) {
		return pair<T1,T2>( x, y );
	}

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map {

		public:

			/************************************* Typedefs ******************************************/

			typedef Key															key_type;
			typedef T															mapped_type;
			typedef Compare														key_compare;
			typedef value_comp( key_compare )									value_compare;
			typedef Alloc														allocator_type;
			typedef allocator_type::reference									reference;
			typedef allocator_type::const_reference								const_reference;
			typedef allocator_type::pointer										pointer;
			typedef allocator_type::const_pointer								const_pointer;
			typedef tree_iterator< pair<key_type, mapped_type> >				iterator;
			typedef const_tree_iterator< pair<key_type, mapped_type> >			const_iterator;
			typedef reverse_iterator<iterator>									reverse_iterator;
			typedef const_reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef std::ptrdiff_t												difference_type;
			typedef size_t														size_type;

			class value_comp {
				friend class map;
			protected:

				Compare comp;
				value_comp( Compare c ) : comp( c ) {}

			public:

				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator()( const value_type& x, const value_type& y ) const {
				  return comp( x.first, y.first );
				}

			};


	};

	template <class T1, class T2>
	bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}
	template <class T1, class T2>
	bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return !( lhs == rhs );
	}
	template <class T1, class T2>
	bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return lhs.first < rhs.first || ( !( rhs.first < lhs.first ) && lhs.second < rhs.second );
	}
	template <class T1, class T2>
	bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return !( rhs < lhs );
	}
	template <class T1, class T2>
	bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return rhs < lhs;
	}
	template <class T1, class T2>
	bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return !( lhs < rhs );
	}

}

#endif