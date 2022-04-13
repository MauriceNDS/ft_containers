#ifndef MAP_HPP
#define MAP_HPP

#include "tree.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< tree_node < pair<Key,T> > > >
	class map {

		private:

			class value_comp;

		public:

			/************************************* Typedefs ******************************************/

			typedef Key															key_type;
			typedef T															mapped_type;
			typedef Compare														key_compare;
			typedef value_comp													value_compare;
			typedef pair< key_type, mapped_type >								value_type;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef tree_iterator<value_type>									iterator;
			typedef const_tree_iterator<value_type>								const_iterator;
			typedef reverse_iterator<iterator>									reverse_iterator;
			typedef const_reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef std::ptrdiff_t												difference_type;
			typedef size_t														size_type;

		private:

			tree< value_type, value_compare, allocator_type > _tree;
			value_compare _vcomparer;

		public:

			/************************************* Constructors **************************************/

			explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() )
			: _tree( _vcomparer, alloc ), _vcomparer( comp ) {}

			template <class InputIterator>
			map( InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) 
			: _tree( first, last, comp, alloc ) {}

			map( const map& x ) {
				*this = x;
			}

			/************************************* Destructor ****************************************/

			~map( void ) {}

			/************************************* Operator = ****************************************/

			map& operator=( const map& x ) {
				_tree = x._tree;
			}

			/************************************* Iterators *****************************************/

			iterator begin( void ) {
				return iterator( _tree.getFirst() );
			}

			const_iterator begin( void ) const {
				return const_iterator( _tree.getFirst() );
			}

			iterator end( void ) {
				if ( _tree.getLast() )
					return iterator( _tree.getLast()->right );
				return begin();
			}

			const_iterator end( void ) const {
				if ( _tree.getLast() )
					return const_iterator( _tree.getLast()->right );
				return begin();
			}

			reverse_iterator rbegin( void ) {
				return reverse_iterator( _tree.getLast() );
			}

			const_reverse_iterator rbegin( void ) const {
				return const_reverse_iterator( _tree.getLast() );
			}

			reverse_iterator rend( void ) {
				if ( _tree.getFirst() )
					return reverse_iterator( _tree.getFirst()->left );
				return rbegin();
			}

			const_reverse_iterator rend( void ) const {
				if ( _tree.getFirst() )
					return const_reverse_iterator( _tree.getFirst()->left );
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
				tree_node<value_type> * res = _tree.search( _tree.getRoot(), ft::make_pair< key_type, mapped_type >( k, mapped_type() ) );
				if ( res )
					return res->value.second;
				_tree.add( ft::make_pair< key_type, mapped_type >( k, mapped_type() ) );
				return _tree.search( _tree.getRoot(), ft::make_pair< key_type, mapped_type >( k, mapped_type() ) )->value.second;
			}

		private:

			class value_comp : std::binary_function< value_type, value_type, bool > {

				friend class map;

			protected:

				Compare comp;
				value_comp( Compare c ) : comp( c ) {}

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