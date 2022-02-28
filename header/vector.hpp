#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <exception>
#include "utility.hpp"
#include "type_traits.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

		public:

			/************************************* Typedefs ******************************************/

			typedef T															value_type;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef Iterator<T>													iterator;
			typedef ConstantIterator<T>											const_iterator;
			typedef ReverseIterator<T>											reverse_iterator;
			typedef ConstantReverseIterator<T>									const_reverse_iterator;
			typedef typename std::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t														size_type;


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
				for ( size_type i = 0; i < _size; i++ )
					_allocator.construct( &_arr[i], val );
			}

			template <class InputIterator>
        	vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL ) {
				size_type i = 0;

				_capacity = ft::vector_do_distance( first, last, std::input_iterator_tag() );
				_size = _capacity;
				_allocator = alloc;
				_arr = _allocator.allocate( _capacity );
				while ( first != last )
					_allocator.construct( &_arr[i++], *first++ );
			}

			vector( const vector& x ) {
				_capacity = x._capacity;
				_size = x._size;
				_allocator = x.allocator_type();
				_arr = _allocator.alloc( _capacity );
				for ( size_type i = 0; i < _size; i++ )
					_allocator.construct( &_arr[i], x._arr[i] );
			}

			/************************************* Destructor ****************************************/

			~vector( void ) {
				deallocate();
			}

			/************************************* Operator = ****************************************/
			
			vector& operator=( const vector& x ) {
				if ( _capacity < x._capacity ) {
					deallocate();
					_size = x._size;
					_capacity = x._capacity;
					_arr = _allocator.allocate( _capacity );
					for ( size_type i = 0; i < _size; i++ )
						_allocator.construct( &_arr[i], x._arr[i] );
				}
				else {
					destruct();
					_size = x._size;
					for ( size_type i = 0; i < _size; i++ )
						_allocator.construct( &_arr[i], x._arr[i] );
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
				if ( n < _size ) {
					for ( size_type i = n; i < _size; i++ )
						_allocator.destroy( &_arr[i] );
					_size = n;			
				}
				else if ( n > _capacity )
					reallocate( true, n, val );
				else {
					for ( size_type i = _size; i < n; i++ )
						_allocator.construct( &_arr[i], val );
					_size = n;
				}
			}

			size_type capacity( void ) const {
				return _capacity;
			}

			bool empty( void ) const {
				return ( _size == 0 ) ? true : false;
			}

			void reserve( size_type n ) {
				if ( n > max_size() )
					throw std::length_error("reserve more than max capacity");
				else if ( n > _capacity )
					reallocate( false, n );
			}

			/************************************* Element access ************************************/

			reference operator[]( size_type n ) {
				return _arr[n];
			}

			const_reference operator[]( size_type n ) const {
				return _arr[n];
			}

			reference at( size_type n ) {
				if ( n >= _size )
					throw std::out_of_range("at: out of range");
				return _arr[n];
			}

			const_reference at( size_type n ) const {
				if ( n >= _size )
					throw std::out_of_range("at: out of range");
				return _arr[n];
			}

			reference front( void ) {
				return _arr[0];
			}

			const_reference front( void ) const {
				return _arr[0];
			}

			reference back( void ) {
				return _arr[_size - 1];
			}

			const_reference back( void ) const {
				return _arr[_size - 1];
			}

			/************************************* Modifiers *****************************************/

			template <class InputIterator>
  			void assign( InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL ) {
				size_type a_size = ft::vector_do_distance( first, last, std::input_iterator_tag() );
				size_type i;
				if ( a_size > _capacity )
					reallocate( 0, a_size );
				for ( i = 0; i < a_size; i++ ) {
					if ( i < _size )
						_allocator.destroy( &_arr[i] );
					_allocator.construct( &_arr[i], *( first + i ));
				}
				_size = i;
			}

			void assign( size_type n, const value_type& val ) {
				size_type i;
				if ( n > _capacity )
					reallocate( 0, n );
				for ( i = 0; i < n; i++ ) {
					if ( i < _size )
						_allocator.destroy( &_arr[i] );
					_allocator.construct( &_arr[i], val );
				}
				_size = i;
			}

			void push_back( const value_type& val ) {
				if ( _size == _capacity )
					reallocate( 0, _capacity * 2 );
				_allocator.construct( &_arr[_size], val );
				_size++;				
			}

			void pop_back( void ) {
				if ( _size == 0 )
					return ;
				_size--;
				_allocator.destruct( &_arr[_size] );
			}

			iterator insert( iterator position, const value_type& val ) {
				iterator it = position;
				value_type copy = val;
				value_type paste;
				if ( _size == _capacity )
					reallocate( 0, _capacity * 2 );
				_size++;
				while ( it != end() ) {
					paste = copy;
					copy = *it;
					_allocator.destroy( &(*it) );
					_allocator.construct( &(*it), paste );
					it++;
				}
				return position;
			}

			void insert( iterator position, size_type n, const value_type& val ) {
				iterator it = end() - 1;
				if ( _size + n > _capacity )
					reallocate( 0, _size + n );
				while ( it != position - 1 ) {
					if ( &*( it + n ) < &back() )
						_allocator.destroy( &*( it + n ));
					_allocator.construct( &*( it + n ), *it );
					it--;
				}
				for ( size_type i = 0; i < n; i++ ) {
					if ( &*( position + n ) < &back() )
						_allocator.destroy( &*( position + n ));
					_allocator.construct( &*( position + n ), val );
				}
			}

			template <class InputIterator>
    		void insert( iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL ) {
				size_type n = ft::vector_do_distance( first, last, std::input_iterator_tag() );
				iterator it = end() - 1;
				if ( _size + n > _capacity )
					reallocate( 0, _size + n );
				while ( it != position - 1 ) {
					if ( &*( it + n ) < &back() )
						_allocator.destroy( &*( it + n ));
					_allocator.construct( &*( it + n ), *it );
					it--;
				}
				for ( size_type i = 0; i < n; i++ ) {
					if ( &*( position + n ) < &back() )
						_allocator.destroy( &*( position + n ));
					_allocator.construct( &*( position + n ), *( first + n ) );
				}
			}

		private:

			T*								_arr;
			size_type						_capacity;
			size_type						_size;
			allocator_type					_allocator;

			/************************************* Utility *******************************************/

			void reallocate( bool mode, size_type n, value_type val = value_type() ) {
				T* new_arr = _allocator.allocate( n );
				size_type i;
				for ( i = 0; i < n; i++ ) {
					if ( i < _size )
						_allocator.construct( &new_arr[i], _arr[i] );
					else if ( mode )
						_allocator.construct( &new_arr[i], val );
					else
						break ;
				}
				deallocate();
				_arr = new_arr;
				_size = i;
				_capacity = n;
			}

			void destruct( size_type n = ft::vector<T>::size() ) {
				for ( size_type i = 0; i < n; i++ )
					_allocator.destroy( &_arr[i] );
			}

			void deallocate( void ) {
				destruct();
				_allocator.deallocate( _arr, _capacity );
			}

	};
}

#endif