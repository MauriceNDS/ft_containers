#ifndef MAP_HPP
#define MAP_HPP

#include "tree.hpp"
#include "stack.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< pair< const Key, T > > >
	class map {

		private:

			class value_comp;

		public:

			/************************************* Typedefs ******************************************/

			typedef Key																					key_type;
			typedef T																					mapped_type;
			typedef Compare																				key_compare;
			typedef value_comp																			value_compare;
			typedef pair< key_type, mapped_type >														value_type;
			typedef Alloc																				allocator_type;
			typedef typename allocator_type::template rebind< tree_node< value_type > >::other			new_alloc;
			typedef typename allocator_type::reference													reference;
			typedef typename allocator_type::const_reference											const_reference;
			typedef typename allocator_type::pointer													pointer;
			typedef typename allocator_type::const_pointer												const_pointer;
			typedef tree_iterator< value_type, ft::tree< value_type, value_compare, new_alloc > >		iterator;
			typedef const_tree_iterator< value_type, ft::tree< value_type, value_compare, new_alloc > >	const_iterator;
			typedef reverse_iterator<iterator>															reverse_iterator;
			typedef const_reverse_iterator<const_iterator>												const_reverse_iterator;
			typedef std::ptrdiff_t																		difference_type;
			typedef size_t																				size_type;

		private:

			key_compare _kcomparer;
			value_compare _vcomparer;
			allocator_type _allocator;
			tree< value_type, value_compare, new_alloc > _tree;

		public:

			/************************************* Constructors **************************************/

			explicit map( const key_compare& comp = key_compare(), const new_alloc& alloc = new_alloc() )
			: _kcomparer( comp ), _vcomparer( comp ), _allocator( alloc ), _tree( _vcomparer, alloc ) {}

			template <class InputIterator>
			map( InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const new_alloc& alloc = new_alloc() ) 
			: _kcomparer( comp ), _vcomparer( comp ), _allocator( alloc ), _tree( first, last, comp, alloc ) {}

			map( const map& x ) {
				*this = x;
			}

			/************************************* Destructor ****************************************/

			~map( void ) {}

			/************************************* Operator = ****************************************/

			map& operator=( const map& x ) {
				_tree = x._tree;
				_vcomparer = x._vcomparer;
				_kcomparer = x._kcomparer;
				_allocator = x._allocator;
				return *this;
			}

			/************************************* Iterators *****************************************/

			iterator begin( void ) {
				return _tree.begin();
			}

			const_iterator begin( void ) const {
				return _tree.begin();
			}

			iterator end( void ) {
				if ( _tree.getLast() )
					return _tree.end();
				return begin();
			}

			const_iterator end( void ) const {
				if ( _tree.getLast() )
					return _tree.end();
				return begin();
			}

			reverse_iterator rbegin( void ) {
				return reverse_iterator( &_tree, _tree.getLast() );
			}

			const_reverse_iterator rbegin( void ) const {
				return const_reverse_iterator( &_tree, _tree.getLast() );
			}

			reverse_iterator rend( void ) {
				if ( _tree.getFirst() )
					return reverse_iterator( &_tree, _tree.getFirst()->left );
				return rbegin();
			}

			const_reverse_iterator rend( void ) const {
				if ( _tree.getFirst() )
					return const_reverse_iterator( &_tree, _tree.getFirst()->left );
				return rbegin();
			}

			/************************************* Capacity ******************************************/

			bool empty( void ) const {
				return ( _tree.getSize() == 0 ) ? true : false;
			}

			size_type size( void ) const {
				return _tree.getSize();
			}

			size_type max_size( void ) const {
				return _tree.getAllocator().max_size();
			}

			/************************************* Element access ************************************/

			mapped_type& operator[]( const key_type& k ) {
				bool duplicate = false;
				tree_node<value_type>* res = _tree.add( ft::make_pair< key_type, mapped_type >( k, mapped_type() ), &duplicate );
				return res->value.second;
				// tree_node<value_type>* res = _tree.search( _tree.getRoot(), ft::make_pair< key_type, mapped_type >( k, mapped_type() ) );
				// if ( res )
				// 	return res->value.second;
				// return _tree.add( ft::make_pair< key_type, mapped_type >( k, mapped_type() ) )->value.second;
			}

			/************************************* Modifiers *****************************************/

			pair<iterator, bool> insert( const value_type& val ) {
				bool duplicate = false;
				tree_node< value_type >* res = _tree.add( val, &duplicate );
				iterator it ( &_tree, res );
				return ft::make_pair<iterator, bool>( it, !duplicate );
			}

			iterator insert( iterator position, const value_type& val ) {
				bool duplicate = false;
				tree_node< value_type > *walk, *node;
				node = _tree.search( _tree.getRoot(), *position );
				if ( node == NULL || node == _tree.getRoot() )
					return insert( val ).first;
				walk = node->parent;
				if ( _vcomparer( val, node->value ) ) {
					if ( !node->isLeft && _vcomparer( val, walk->value ) )
						return insert( val ).first;
					else if ( node->isLeft ) 
						return iterator( &_tree, _tree.hint_add( node, val, &duplicate ) );
				}
				else {
					if ( node->isLeft && _vcomparer( walk->value, val ) )
						return insert( val ).first;
					else if ( !node->isLeft )
						return iterator( &_tree, _tree.hint_add( node, val, &duplicate ) );
				}
				return iterator( &_tree, _tree.hint_add( node, val, &duplicate ) );
			}

			template <class InputIterator>
			void insert( InputIterator first, InputIterator last ) {
				while ( first != last ) {
					insert( *first );
					first++;
				}
			}

			void erase( iterator position ) {
				tree_node< value_type > *node = _tree.search( _tree.getRoot(), *position );
				if ( node == NULL )
					return ;
				_tree.del( node );
			}

			size_type erase( const key_type& k ) {
				tree_node< value_type >* res = _tree.search( _tree.getRoot(), ft::make_pair<key_type, mapped_type>( k, mapped_type() ) );
				if ( res ) {
					_tree.del( res );
					return 1;
				}
				return 0;
			}

			void erase( iterator first, iterator last ) {
				ft::stack<key_type> a;
				while ( first != last ) {
					a.push( first->first );
					first++;
				}
				while ( !a.empty() ) {
					erase( a.top() );
					a.pop();
				}
			}

			void swap( map& x ) {
				_tree.swap( x._tree );
			}

			void clear( void ) {
				_tree.clear();
			}

			/************************************* Observers *****************************************/

			key_compare key_comp( void ) const {
				return _kcomparer;
			}

			value_compare value_comp( void ) const {
				return _vcomparer;
			}

			/************************************* Operations ****************************************/
			
			iterator find( const key_type& k ) {
				return iterator( &_tree, _tree.search( _tree.getRoot(), ft::make_pair<key_type, mapped_type>( k, mapped_type() ) ) );
			}

			const_iterator find( const key_type& k ) const {
				return const_iterator( &_tree, _tree.search( _tree.getRoot(), ft::make_pair<key_type, mapped_type>( k, mapped_type() ) ) );
			}

			size_type count( const key_type& k ) const {
				if ( _tree.search( _tree.getRoot(), ft::make_pair<key_type, mapped_type>( k, mapped_type() ) ) )
					return 1;
				return 0;
			}

			iterator lower_bound( const key_type& k ) {
				tree_node< value_type >* node = _tree.lower_search( _tree.getRoot(), ft::make_pair<key_type, mapped_type>( k, mapped_type() ) );
				if ( node )
					return iterator( &_tree, node );
				return end();
			}

			const_iterator lower_bound( const key_type& k ) const {
				tree_node< value_type >* node = _tree.lower_search( _tree.getRoot(), ft::make_pair<key_type, mapped_type>( k, mapped_type() ) );
				if ( node )
					return iterator( &_tree, node );
				return end();
			}

			iterator upper_bound( const key_type& k ) {
				tree_node< value_type >* node = _tree.lower_search( _tree.getRoot(), ft::make_pair<key_type, mapped_type>( k, mapped_type() ) );
				if ( node ) {
					if ( !_kcomparer( k, node->value.first ) && !_kcomparer( node->value.first, k ) )
						return ++iterator( &_tree, node );
					return iterator( &_tree, node );
				}
				return end();
			}

			const_iterator upper_bound( const key_type& k ) const {
				tree_node< value_type >* node = _tree.lower_search( _tree.getRoot(), ft::make_pair<key_type, mapped_type>( k, mapped_type() ) );
				if ( node ) {
					if ( !_kcomparer( k, node->value.first ) && !_kcomparer( node->value.first, k ) )
						return ++const_iterator( &_tree, node );
					return const_iterator( &_tree, node );
				}
				return end();
			}

			pair<iterator,iterator> equal_range( const key_type& k ) {
				tree_node< value_type >* node = _tree.lower_search( _tree.getRoot(), ft::make_pair<key_type, mapped_type>( k, mapped_type() ) );
				if ( node ) {
					if ( !_kcomparer( k, node->value.first ) && !_kcomparer( node->value.first, k ) )
						return ft::make_pair<iterator,iterator>( iterator( &_tree, node ), ++iterator( &_tree, node ) );
				}
				return ft::make_pair<iterator,iterator>( iterator( &_tree, node ), iterator( &_tree, node ) );
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				tree_node< value_type >* node = _tree.lower_search( _tree.getRoot(), ft::make_pair<key_type, mapped_type>( k, mapped_type() ) );
				if ( node ) {
					if ( !_kcomparer( k, node->value.first ) && !_kcomparer( node->value.first, k ) )
						return ft::make_pair<const_iterator,const_iterator>( const_iterator( &_tree, node ), ++const_iterator( &_tree, node ) );
				}
				return ft::make_pair<const_iterator,const_iterator>( const_iterator( &_tree, node ), const_iterator( &_tree, node ) );
			}

			/************************************* Allocator *****************************************/

			allocator_type get_allocator( void ) const {
				return _allocator;
			}

		private:
			
			void printBT( void ) {
				_tree.printBT( "", _tree.getRoot(), false );
			}

			class value_comp : std::binary_function< value_type, value_type, bool > {

				friend class map;

			protected:

				key_compare comp;
				value_comp( key_compare c ) : comp( c ) {}

			public:
				value_comp( void ) {}

				typedef bool 				result_type;
				typedef value_type			first_argument_type;
				typedef value_type			second_argument_type;
				bool operator()( const value_type& x, const value_type& y ) const {
					return comp( x.first, y.first );
				}
				
				value_comp& operator=( const value_comp& rhs ) {
					comp = rhs.comp;
					return *this;
				}

			};

	};

}

#endif