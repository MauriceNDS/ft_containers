#ifndef MAP_HPP
#define MAP_HPP

#include "tree.hpp"

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

			value_compare _vcomparer;
			tree< value_type, value_compare, new_alloc > _tree;

		public:

			/************************************* Constructors **************************************/

			explicit map( const key_compare& comp = key_compare(), const new_alloc& alloc = new_alloc() )
			: _vcomparer( comp ), _tree( _vcomparer, alloc ) {}

			template <class InputIterator>
			map( InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const new_alloc& alloc = new_alloc() ) 
			: _tree( first, last, comp, alloc ) {}

			map( const map& x ) {
				*this = x;
			}

			/************************************* Destructor ****************************************/

			~map( void ) {}

			/************************************* Operator = ****************************************/

			map& operator=( const map& x ) {
				_tree = x._tree;
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

			bool empty() const {
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
				tree_node<value_type>* res = _tree.search( _tree.getRoot(), ft::make_pair< key_type, mapped_type >( k, mapped_type() ) );
				if ( res )
					return res->value.second;
				return _tree.add( ft::make_pair< key_type, mapped_type >( k, mapped_type() ) )->value.second;
			}

			/************************************* Modifiers *****************************************/

			pair<iterator, bool> insert( const value_type& val ) {
				tree_node< value_type >* res = _tree.search( _tree.getRoot(), val );
				if ( res ) {
					iterator it( &_tree, res );
					return ft::make_pair< iterator, bool >( it, false );
				}
				iterator new_elem( &_tree, _tree.add( val ) );
				return ft::make_pair< iterator, bool >( new_elem, true );
			}

			iterator insert( iterator position, const value_type& val ) {
				tree_node< value_type > *walk, *node;
				node = _tree.search( _tree.getRoot(), *position );
				if ( node == NULL || node == _tree.getRoot() )
					return insert( val ).first;
				walk = node->parent;
				if ( _vcomparer( val, node->value ) ) {
					if ( !node->isLeft && _vcomparer( val, walk->value ) )
						return insert( val ).first;
					else if ( node->isLeft )
						return iterator( &_tree, _tree.hint_add( node, val ) );
				}
				else {
					if ( node->isLeft && _vcomparer( walk->value, val ) )
						return insert( val ).first;
					else if ( !node->isLeft )
						return iterator( &_tree, _tree.hint_add( node, val ) );
				}
				return iterator( &_tree, _tree.hint_add( node, val ) );
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
				tree_node< value_type >* res = _tree.search( _tree.getRoot(), make_pair<key_type, mapped_type>( k, mapped_type() ) );
				if ( res ) {
					_tree.del( res );
					return 1;
				}
				return 0;
			}

			void erase( iterator first, iterator last ) {
				while ( first != last ) {
					_tree.erase( first );
					first++;
				}
			}

			void swap( map& x ) {
				(void)x;
			}
			
			void printBT( void ) {
				_tree.printBT( "", _tree.getRoot(), false );
			}

		private:

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