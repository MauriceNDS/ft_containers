#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "iterator.hpp"
#include "utility.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

		private:

			T*								_arr;
			size_type						_capacity;
			size_type						_size;
			allocator_type					_allocator;

			/************************************* Utility *******************************************/

			void reallocate( size_type n, value_type val = value_type() ) {
				T* new_arr = _allocator.allocate( n );
				for ( size_type i = 0; i < n; i++ ) {
					if ( i < _size )
						_allocator.construct( new_arr[i], _arr[i] );
					else
						_allocator.construct( new_arr[i], val );
				}
				deallocate();
				_arr = new_arr;
				_size = n;
				_capacity = n;
			}

			void destruct( size_type n = _size ) {
				for ( size_type i = 0; i < n; i++ )
					_allocator.destruct( _arr[i] );
			}

			void deallocate( void ) {
				destruct();
				_allocator.deallocate( _arr, _capacity );
			}

		public:

			/************************************* Typedefs ******************************************/

			using value_type				= T;
			using allocator_type			= Alloc;
			using reference					= allocator_type::reference;
			using const_reference			= allocator_type::const_reference;
			using pointer					= allocator_type::pointer;
			using const_pointer				= allocator_type::const_pointer;
			using iterator					= Iterator<T>;
			using const_iterator			= ConstantIterator<T>;
			using reverse_iterator			= ReverseIterator<T>;
			using const_reverse_iterator	= ConstantReverseIterator<T>;
			using difference_type			= iterator_traits<iterator>::difference_type;
			using size_type					= size_t;


			/************************************* Constructors **************************************/

			explicit vector( const allocator_type& alloc = allocator_type() ) {
				_arr = NULL;
				_capacity = 0;
				_size = 0;
				_allocator = alloc;
			}

			explicit vector( size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type() ) {
				_capacity = n;
				_size = n;
				_allocator = alloc;
				_arr = _allocator.allocate( _capacity );
				_allocator.construct( _arr, val );
			}

			template <class InputIterator>
        	vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() ) {
				size_type i = 0;

				_capacity = vector_do_distance( first, last );
				_size = _capacity;
				_allocator = alloc;
				_arr = _allocator.allocate( _capacity );
				while ( first != last )
					_allocator.construct( _arr[i++], *first++ );
			}

			vector( const vector& x ) {
				_capacity = x._capacity;
				_size = x._size;
				_allocator = x.allocator_type()
				_arr = _allocator.alloc( _capacity );
				for ( size_type i = 0; i < _size; i++ )
					_allocator.construct( _arr[i], x._arr[i] );
			}

			/************************************* Destructor ****************************************/

			~vector( void ) {
				deallocate();
			}

			/************************************* Operator = ****************************************/
			
			vector& operator=( const vector& x ) {
				if ( _capacity < x._capacity ) {
					deallocate();
					_size = x._size
					_capacity = x._capacity;
					_arr = _allocator.allocate( _capacity );
					for ( size_type i = 0; i < _size; i++ )
						_allocator.construct( _arr[i], x._arr[i] );
				}
				else {
					destruct();
					_size = x._size;
					for ( size_type i = 0; i < _size; i++ )
						_allocator.construct( _arr[i], x._arr[i] );
				}
				return *this;
			}

			/************************************* Iterators *****************************************/

			iterator begin( void ) {
				return iterator( _arr );
			}

			const_iterator begin( void ) const {
				return const_iterator( _arr );
			}

			iterator end( void ) {
				return iterator( _arr + _size );
			}

			const_iterator end( void ) const {
				return const_iterator( _arr + _size );
			}

			reverse_iterator rbegin( void ) {
				return reverse_iterator( _arr + _size - 1);
			}

			const_reverse_iterator rbegin( void ) const {
				return const_reverse_iterator( _arr + _size - 1 );
			}

			reverse_iterator rend( void ) {
				return reverse_iterator( _arr - 1);
			}

			const_reverse_iterator rend( void ) const {
				return const_reverse_iterator( _arr - 1 );
			}

			/************************************* Capacity ******************************************/

			size_type size( void ) const {
				return _size;
			}

			size_type max_size( void ) const {
				return _allocator.max_size();
			}

			void resize( size_type n, value_type val = value_type() ) {
				if ( n < _size )
					for ( size_type i = n; i < _size; i++ )
						_allocator.destruct( _arr[i] );
				else if ( n > _capacity )
					reallocate( n, val );
				else
					for ( size_type i = _size; i < n; i++ )
						_allocator.construct( _arr[i], val );
			}

	};
}

#endif