#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <memory>
#include "iterator.hpp"

namespace ft {

	template <class T>
	class tree_iterator;

	template <class T>
	class const_tree_iterator;

	template <class Iter>
	class reverse_iterator;

	template <class ConstIter>
	class const_reverse_iterator;

	template <class T>
	struct tree_node {

		T			value;
		bool		black;
		bool		isLeft;
		tree_node*	parent;
		tree_node*	left;
		tree_node*	right;

		tree_node( void ) : parent( NULL ), left( NULL ), right( NULL ), black( true ), isLeft( false ) {}
		tree_node( T val ) : value( val ), parent( NULL ), left( NULL ), right( NULL ), black( false ), isLeft( false ) {}

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

		private: coucou

			class value_comp {

				friend class map;

			protected:

				Compare comp;
				value_comp( Compare c ) : comp( c ) {}

			public:

				typedef bool 		result_type;
				typedef T			first_argument_type;
				typedef T			second_argument_type;
				bool operator()( const T& x, const T& y ) const {
				  return comp( x.first, y.first );
				}

			};

		public:

			/************************************* Typedefs ******************************************/

			typedef Key															key_type;
			typedef T															mapped_type;
			typedef Compare														key_compare;
			typedef value_comp													value_compare; // ?
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef tree_iterator< pair< key_type, mapped_type > >				iterator;
			typedef const_tree_iterator< pair< key_type, mapped_type > >		const_iterator;
			typedef reverse_iterator<iterator>									reverse_iterator;
			typedef const_reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef std::ptrdiff_t												difference_type;
			typedef size_t														size_type;

		private:

			tree_node< pair< key_type, mapped_type > > * _root;
			size_type _size;
			allocator_type _allocator;
			key_compare _comparer;

		public:

			/************************************* Constructors **************************************/

			explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) : _size( 0 ), _root( NULL ) {
				_comparer = comp;
				_allocator = alloc;
			}

			template <class InputIterator>
			map( InputIterator first, InputIterator last, const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type() ) {
				_comparer = comp;
				_allocator = alloc;
				// to be continued
			}

		private:

			void add( pair< key_type, mapped_type > p ) {
				if ( check_duplicates( p ) )
					return ;
				// TO change
				tree_node< pair< key_type, mapped_type > > * node = new tree_node< pair< key_type, mapped_type > >( p );
				if ( _root == NULL ) {
					_root = node;
					_root->black = true;
					_size++;
					return ;
				}
				add( _root, node );
				check_color( node );
				_size++;
			}

			void add( tree_node< pair< key_type, mapped_type > > * parent, tree_node< pair< key_type, mapped_type > > * new_node ) {
				if ( key_compare( parent->key, new_node->key ) ) {
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

			bool chek_duplicates( pair< key_type, mapped_type > p ) {
				for ( iterator it = begin(); it != end(); it++ )
					if ( !_comparer( p.first, it->first ) && !_comparer( it->first, p.first ) )
						return true;
				return false;
			}
			
			void check_color( tree_node< pair< key_type, mapped_type > > * node ) {
				if ( node == _root )
					return ;
				if ( !node->black && !node->parent->black )
					correct_tree( node );
				check_color( node->parent ); 
			}

			void correct_tree( tree_node< pair< key_type, mapped_type > > * node ) {
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

			void rotate( tree_node< pair< key_type, mapped_type > > * node ) {
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
					left_rotate( node->parent->parent );
					node->black = false;
					node->parent->black = true;
					if ( node->parent->right != NULL )
						node->parent->right->black = false;
					return ;
				}
				leftright_rotate( node->parent->parent );
				node->black = true;
				node->right->black = false;
				node->left->black = false;
			}

			void left_rotate( tree_node< pair< key_type, mapped_type > > * node ) {
				tree_node< pair< key_type, mapped_type > > * temp = node->right;
				node->right = temp->left;
				if ( node->right != NULL ) {
					node->right->parent = node;
					node->right->isLeft = false;
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
				temp->left = node;
				node->isLeft = true;
				node->parent = temp;
			}

			void right_rotate( tree_node< pair< key_type, mapped_type > > * node ) {
				tree_node< pair< key_type, mapped_type > > * temp = node->left;
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

			void leftright_rotate( tree_node< pair< key_type, mapped_type > > * node ) {
				left_rotate( node->left );
				right_rotate( node );
			}

			void rightleft_rotate( tree_node< pair< key_type, mapped_type > > * node ) {
				left_rotate( node->left );
				right_rotate( node );
			}

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