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

	template < class T, class value_comp = std::less<T>, class Alloc = std::allocator< tree_node< T > > >
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

			tree( void ) : _root( NULL ), _first( NULL ), _last( NULL ), _size( 0 ) {}

			tree( const value_comp& comp, const Alloc& alloc ) : _root( NULL ), _first( NULL ), _last( NULL ), _size( 0 ) {
				_comparer = comp;
				_allocator = alloc;
			}

			template <class InputIterator>
			tree( InputIterator first, InputIterator last, const value_comp& comp, const Alloc& alloc ) : _root( NULL ), _first( NULL ), _last( NULL ), _size( 0 ) {
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
				clear( _root );
			}

			void printBT( const std::string& prefix, const tree_node<T>* node, bool isLeft ) {
				if ( node != NULL ) {
					std::cout << prefix;

					std::cout << (isLeft ? "├──L:" : "└──R:" );

					// print the value of the node
					if ( !node->black ) {
						std::cout << "\033[31m[" << node->value.first << " -- ";
						std::cout << node->value.second << "]\033[0m" << std::endl;
					}
					else {
						std::cout << "[" << node->value.first << " -- ";
						std::cout << node->value.second << "]" << std::endl;
					}

					// enter the next tree level - left and right branch
					printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
					printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
				}
			}

			tree& operator=( const tree& x ) {
				clear( _root );
				_root = NULL;
				_size = 0;
				_comparer = x._comparer;
				_allocator = x._allocator;
				copy( x._root );
				return *this;
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

			tree_node< T > * getFirst( void ) const {
				return _first;
			}

			tree_node< T > * getLast( void ) const {
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

			tree_node< T >* search( tree_node< T >* node, T const key ) const {
				if ( node == NULL ) {
					return NULL;
				}
				if ( !_comparer( node->value, key ) && !_comparer( key, node->value ) ) {
					return node;
				}
				tree_node< T >* res = NULL;
				if (!(res = search( node->left, key ))) {
					res = search( node->right, key );
				}
				return res;
			}

			void del( tree_node< T >* v ) {
				// step one - perform a basic binary tree deletion
				tree_node< T >* u = bst_delete( v );
				// step two - if either 'u' or 'v' are red
				if ( u && v->black == false ) {
					u->black = false;
					if ( u->right )
						u->right->black = true;
					if ( u->left )
						u->left->black = true;
				}
				else if ( u && u->black == false )
					u->black = true;
				// step three - if both 'u' and 'v' are black
				else if ( v->black )
					handle_double_black( v, u );
				iterator it( v );
				if ( v->parent == NULL ) {
					_first = NULL;
					_last = NULL;
				}
				else {
					if ( v == _first )
						_first = search( _root, *(++it) );
					if ( v == _last )
						_last = search( _root, *(--it) );
				}
				free_node( v );
			}

		private:

		void copy( tree_node< T >* node ) {
			if ( node == NULL )
				return ;
			add( node->value );
			copy( node->left );
			copy( node->right );
		}

		void clear( tree_node< T >* node ) {
			if ( node == NULL )
				return ;
			clear( node->left );
			clear( node->right );
			free_node( node );
			node = NULL;
		}

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
				if ( node == _root )
					return ;
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
					node->black = true;
					node->right->black = false;
					node->left->black = false;
					return ;
				}
				left_rotate( node->parent->parent );
				node->black = false;
				node->parent->black = true;
				if ( node->parent->left != NULL )
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
				right_rotate( node->right );
				left_rotate( node );
			}

			tree_node< T >* bst_delete_no_leaf( tree_node< T >* node ) {
				if ( node->parent && node->isLeft )
					node->parent->left = NULL;
				else if ( node->parent )
					node->parent->right = NULL;
				else
					_root = NULL;
				_size--;
				return NULL;
			}

			tree_node< T >* bst_delete_left_leaf( tree_node< T >* node ) {
				_size--;
				if ( node->parent == NULL ) {
					_root = node->left;
					node->left->parent = NULL;
					node->left->isLeft = false;
					return node;
				}
				if ( node->isLeft )
					node->parent->left = node->left;
				else {
					node->parent->right = node->left;
					node->left->isLeft = false;
				}
				node->left->parent = node->parent;
				return node->left;
			}

			tree_node< T >* bst_delete_right_leaf( tree_node< T >* node ) {
				_size--;
				if ( node->parent == NULL ) {
					_root = node->right;
					node->right->parent = NULL;
					return node;
				}
				if ( node->isLeft ) {
					node->parent->left = node->right;
					node->right->isLeft = true;
				}
				else
					node->parent->right = node->right;
				node->right->parent = node->parent;
				return node->right;
			}

			tree_node< T >* bst_delete_two_leaf( tree_node< T >* node ) {
				_size--;
				tree_node< T >* next = node->right;
				while ( next->left )
					next = next->left;
				if ( node->parent == NULL ) {
					if ( next->isLeft ) {
						next->parent->left = next->right;
						if ( next->right ) {
							next->right->isLeft = true;
							next->right->parent = next->parent;
						}
						next->right = node->right;
						node->right->parent = next;
					}
					next->parent = NULL;
					next->isLeft = node->isLeft;
					next->left = node->left;
					node->left->parent = next;
					_root = next;
					return next;
				}
				if ( next->isLeft ) {
					next->parent->left = next->right;
					if ( next->right ) {
						next->right->isLeft = true;
						next->right->parent = next->parent;
					}
					next->right = node->right;
					node->right->parent = next;
				}
				if ( node->isLeft )
					node->parent->left = next;
				else
					node->parent->right = next;
				next->parent = node->parent;
				next->isLeft = node->isLeft;
				next->left = node->left;
				node->left->parent = next;
				return next;
			}

			tree_node< T >* bst_delete( tree_node< T > * node ) {
				if ( node->left == NULL && node->right == NULL )
					return bst_delete_no_leaf( node );
				else if ( node->left != NULL && node->right == NULL )
					return bst_delete_left_leaf( node );
				else if ( node->left == NULL && node->right != NULL )
					return bst_delete_right_leaf( node );
				else
					return bst_delete_two_leaf( node );				
			}

			void rotate_double_black( tree_node< T >* s, tree_node< T >* r ) {
				if ( s->isLeft && r->isLeft )
					right_rotate( s->parent );
				else if ( s->isLeft && !r->isLeft )
					leftright_rotate( s->parent );
				else if ( !s->isLeft && !r->isLeft )
					left_rotate( s->parent );
				else
					rightleft_rotate( s->parent );
			}

			void handle_double_black( tree_node< T >* v, tree_node< T >* u ) {
				tree_node< T >* s, *r;
				// tree_node< T >* double_black = v;
				if ( u == _root )
					return ;
				if ( v && v->isLeft )
					s = v->parent->right;
				else
					s = v->parent->left;
				if ( s->black && ( ( s->left && !s->left->black ) || ( s->right && !s->right->black ) ) ) {
					if ( s->left && !s->left->black && s->right && !s->right->black && v->isLeft )
						r = s->right;
					else if ( s->left && !s->left->black && s->right && !s->right->black )
						r = s->left;
					else if ( s->left && !s->left->black )
						r = s->left;
					else
						r = s->right;
					rotate_double_black( s, r );
					r->black = true;
					if ( u && u->black )
						u->black = false;
				}
				else if ( s->black && ( !s->left || s->left->black ) && ( !s->right || s->right->black ) ) {
					s->black = false;
					if ( !s->parent->black )
						s->parent->black = true;
					else
						handle_double_black( s->parent, s->parent );
				}
				else if ( !s->black ) {
					s->black = !s->black;
					s->parent->black = !s->parent->black;
					if ( s->isLeft )
						right_rotate( s->parent );
					else
						left_rotate( s->parent );
					handle_double_black( v, v );
				}
			}

			void free_node( tree_node< T > * node ) {
				if ( node ) {
					_allocator.destroy( node );
					_allocator.deallocate( node, 1 );
				}
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