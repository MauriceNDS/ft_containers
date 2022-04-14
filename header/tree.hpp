#ifndef TREE_HPP
#define TREE_HPP

#include <functional>
#include <memory>
#include "iterator.hpp"

namespace ft {

	template <class T>
	struct tree_node {

		T			value;
		bool		black;
		bool		isLeft;
		tree_node*	parent;
		tree_node*	left;
		tree_node*	right;

		tree_node( void ) : parent( NULL ), left( NULL ), right( NULL ), black( true ), isLeft( false ) {}
		tree_node( T val ) : value( val ), black( false ), isLeft( false ), parent( NULL ), left( NULL ), right( NULL ) {}

	};

	template <class T>
	class tree_iterator;

	template <class T>
	class const_tree_iterator;

	template <class Iter>
	class reverse_iterator;

	template <class ConstIter>
	class const_reverse_iterator;

	template < class T, class value_comp, class Alloc >
	class tree {

		private:

			tree_node< T > * _root;
			tree_node< T > * _first;
			tree_node< T > * _last;
			size_t _size;
			Alloc _allocator;
			value_comp _comparer;

		public:

			typedef ft::tree_iterator< T >										iterator;
			typedef const_tree_iterator< T >									const_iterator;
			typedef reverse_iterator<iterator>									reverse_iterator;
			typedef const_reverse_iterator<const_iterator>						const_reverse_iterator;

			tree( const value_comp& comp, const Alloc& alloc ) : _root( NULL ), _size( 0 ) {
				_comparer = comp;
				_allocator = alloc;
				_first = NULL;
				_last = NULL;
			}

			template <class InputIterator>
			tree( InputIterator first, InputIterator last, const value_comp& comp, const Alloc& alloc ) {
				_comparer = comp;
				_allocator = alloc;
				while ( first != last )
					add( *first++ );
			}

			tree( const tree& x ) {
				*this = x;
			}

			// to be continued
			~tree( void ) {
				
			}

			tree& operator=( const tree& x ) {
				_root = x._root;
				_size = x._size;
			}

			iterator begin( void ) {
				return iterator( _first );
			}

			const_iterator begin( void ) const {
				return const_iterator( _first );
			}

			iterator end( void ) {
				if ( _last )
					return iterator( _last->right );
				return begin();
			}

			const_iterator end( void ) const {
				if ( _last )
					return const_iterator( _last->right );
				return begin();
			}

			tree_node< T > * getRoot( void ) const {
				return _root;
			}

			tree_node< T > const * getFirst( void ) const {
				return _first;
			}

			tree_node< T > const * getLast( void ) const {
				return _last;
			}

			size_t getSize( void ) const {
				return _size;
			}

			Alloc getAllocator( void ) const {
				return _allocator;
			}

			tree_node<T>* add( T p ) {
				// if ( check_duplicates( p ) )
				// 	return NULL;
				tree_node< T >* node = _allocator.allocate( 1 );
				_allocator.construct( node, tree_node<T>( p ) );
				if ( _root == NULL ) {
					_root = node;
					_root->black = true;
					_first = _root;
					_last = _root;
					_size++;
					return node;
				}
				add( _root, node );
				check_color( node );
				if ( _comparer( node->value, _first->value ) )
					_first = node;
				if ( _comparer( _last->value, node->value ) )
					_last = node;
				_root->black = true;
				_size++;
				return node;
			}

			tree_node<T>* hint_add( tree_node< T >* position, T p ) {
				tree_node< T >* node = _allocator.allocate( 1 );
				_allocator.construct( node, tree_node<T>( p ) );
				add( position, node );
				check_color( node );
				if ( _comparer( node->value, _first->value ) )
					_first = node;
				if ( _comparer( _last->value, node->value ) )
					_last = node;
				_root->black = true;
				_size++;
				return node;
			}

			tree_node<T>* search( tree_node<T> * node, T const key ) const {
				if ( node && !_comparer( node->value, key ) && !_comparer( key, node->value ) )
					return node;
				if ( node && node->left )
					return search( node->left, key );
				if ( node && node->right )
					return search( node->right, key );
				return NULL;
			}

		private:

			void add( tree_node< T > * parent, tree_node< T > * new_node ) {
				if ( _comparer( parent->value, new_node->value ) ) {
					if ( parent->right == NULL ) {
						parent->right = new_node;
						new_node->parent = parent;
						new_node->isLeft = false;
						return ;
					}
					return add( parent->right, new_node );
				}
				if ( parent->left == NULL ) {
					parent->left = new_node;
					new_node->parent = parent;
					new_node->isLeft = true;
					return ;
				}
				return add( parent->left, new_node );
			}

			bool check_duplicates( T p ) {
				for ( iterator it = begin(); it != end(); it++ )
					if ( !_comparer( p, *it ) && !_comparer( *it, p ) )
						return true;
				return false;
			}
			
			void check_color( tree_node< T > * node ) {
				if ( node == _root )
					return ;
				if ( !node->black && !node->parent->black )
					correct_tree( node );
				check_color( node->parent ); 
			}

			void correct_tree( tree_node< T > * node ) {
				if ( node->parent->isLeft ) { // aunt is node->parent->parent->right
					if ( node->parent->parent->right == NULL || node->parent->parent->right->black )
						return rotate( node );
					if ( node->parent->parent->right != NULL )
						node->parent->parent->right->black = true;
					node->parent->parent->black = false;
					node->parent->black = true;
					return ;
				}
				// aunt is node->parent->parent->left
				if ( node->parent->parent->left == NULL || node->parent->parent->left->black )
					return rotate( node );
				if ( node->parent->parent->left != NULL )
					node->parent->parent->left->black = true;
				node->parent->parent->black = false;
				node->parent->black = true;
			}

			void rotate( tree_node< T > * node ) {
				if ( node->isLeft ) {
					if ( node->parent->isLeft ) {
						right_rotate( node->parent->parent );
						node->black = false;
						node->parent->black = true;
						if ( node->parent->right != NULL )
							node->parent->right->black = false;
						return ;
					}
					rightleft_rotate( node->parent->parent );
					node->black = true;
					node->right->black = false;
					node->left->black = false;
					return ;
				}
				if ( node->parent->isLeft ) {
					leftright_rotate( node->parent->parent );
					node->black = false;
					node->parent->black = true;
					if ( node->parent->right != NULL )
						node->parent->right->black = false;
					return ;
				}
				left_rotate( node->parent->parent );
				node->parent->black = true;
				node->parent->right->black = false;
				node->parent->left->black = false;
			}

			void left_rotate( tree_node< T > * node ) {
				tree_node< T > * temp = node->right;
				node->right = temp->left;
				if ( node->right != NULL ) {
					node->right->parent = node;
					node->right->isLeft = false;
				}
				if ( node->parent == NULL ) { // we are the root node
					_root = temp;
					temp->parent = NULL;
				}
				else {
					temp->parent = node->parent;
					if ( node->isLeft ) {
						temp->isLeft = true;
						temp->parent->left = temp;
					}
					else {
						temp->isLeft = false;
						temp->parent->right = temp;
					}
				}
				temp->left = node;
				node->isLeft = true;
				node->parent = temp;
			}

			void right_rotate( tree_node< T > * node ) {
				tree_node< T > * temp = node->left;
				node->left = temp->right;
				if ( node->left != NULL ) {
					node->left->parent = node;
					node->left->isLeft = true;
				}
				if ( node->parent == NULL ) { // we are a root node
					_root = temp;
					temp->parent = NULL;
				}
				else {
					temp->parent = node->parent;
					if ( node->isLeft ) {
						temp->isLeft = true;
						temp->parent->left = temp;
					}
					else {
						temp->isLeft = false;
						temp->parent->right = temp;
					}
				}
				temp->right = node;
				node->isLeft = false;
				node->parent = temp;
			}

			void leftright_rotate( tree_node< T > * node ) {
				left_rotate( node->left );
				right_rotate( node );
			}

			void rightleft_rotate( tree_node< T > * node ) {
				left_rotate( node->left );
				right_rotate( node );
			}

	};

	template <class T1, class T2>
	struct pair {

		typedef T1						first_type;
		typedef T2						second_type;

		first_type						first;
		second_type						second;

		pair( void ) {}

		template<class U, class V>
		pair( const pair<U,V>& pr ) {
			*this = pr;
		}

		pair( const first_type& a, const second_type& b ) : first( a ), second( b ) {}

		pair& operator=( const pair& pr ) {
			first = pr.first;
			second = pr.second;
		}

	};

	template <class T1, class T2>
	pair<T1,T2> make_pair( T1 x, T2 y ) {
		return pair<T1,T2>( x, y );
	}

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