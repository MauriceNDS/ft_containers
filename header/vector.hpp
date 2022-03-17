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
			typedef typename ft::iterator<T>									iterator;
			typedef typename ft::const_iterator<T>								const_iterator;
			typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
			typedef typename ft::const_reverse_iterator<iterator>				const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
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

				_capacity = ft::vector_do_distance( first, last );
				_size = _capacity;
				_allocator = alloc;
				_arr = _allocator.allocate( _capacity );
				while ( first != last )
					_allocator.construct( &_arr[i++], *first++ );
			}

			vector( const vector& x ) {
				_capacity = x._capacity;
				_size = x._size;
				_allocator = x._allocator;
				_arr = _allocator.allocate( _capacity );
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
				if ( n > _capacity )
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
					throw std::out_of_range("vector");
				return _arr[n];
			}

			const_reference at( size_type n ) const {
				if ( n >= _size )
					throw std::out_of_range("vector");
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
				size_type a_size = ft::vector_do_distance( first, last );
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
				if ( _size == _capacity && _capacity != 0 )
					reallocate( 0, _capacity * 2 );
				else if ( _size == _capacity )
					reallocate( 0, 1 );
				_allocator.construct( &_arr[_size], val );
				_size++;				
			}

			void pop_back( void ) {
				if ( _size == 0 )
					return ;
				_size--;
				_allocator.destroy( &_arr[_size] );
			}

			iterator insert( iterator position, const value_type& val ) {
				reserve( _size + 1 );
				_size++;
				iterator it = end() - 1;
				while ( it != position ) {
					*it = *( it - 1 );
					it--;
				}
				_allocator.construct( &*it, val );
				return it;
			}

			iterator erase( iterator position ) {
				_allocator.destroy( &*position );
				for ( iterator it = position; it != end(); it++ )
					*it = *( it + 1 );
				_size--;
				return position;
			}

			iterator erase( iterator first, iterator last ) {
				size_type n = ft::vector_do_distance( first, last );
				for ( size_type i = 0; i < n; i++ )
					_allocator.destroy( &*( first + i ) );
				for ( iterator it = first; it != last; it++ ) {
					if ( it + n == end() )
						break ;
					*it = *( it + n );
				}
				_size -= n;
				return first;
			}

			void swap( vector& x ) {
				T* arr_buff = _arr;
				size_type capacity_buff = _capacity;
				size_type size_buff = _size;
				allocator_type allocator_buff = _allocator;

				_arr = x._arr;
				_capacity = x._capacity;
				_size = x._size;
				_allocator = x._allocator;
				x._arr = arr_buff;
				x._capacity = capacity_buff;
				x._size = size_buff;
				x._allocator = allocator_buff;
			}

			void clear( void ) {
				for ( iterator it = begin(); it != end(); it++ )
					_allocator.destroy( &*it );
				_size = 0;
			}

			/************************************* Allocator *****************************************/

			allocator_type get_allocator( void ) const {
				return _allocator;
			}

		private:

			T*								_arr;
			size_type						_capacity;
			size_type						_size;
			allocator_type					_allocator;

			/************************************* Utility *******************************************/

			void reallocate( bool mode, size_type n, value_type val = value_type() ) {
				if ( n > max_size() )
					throw std::length_error("reserve more than max capacity");
				if ( _capacity * 2 >= n )
					_capacity *= 2;
				else
					_capacity = n;
				T* new_arr = _allocator.allocate( _capacity );
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
			}

			void destruct( size_type n = ft::vector<T>::size() ) {
				for ( size_type i = 0; i < n; i++ )
					_allocator.destroy( &_arr[i] );
			}

			void deallocate( void ) {
				destruct();
				if ( _arr )
					_allocator.deallocate( _arr, _capacity );
			}

	};

	template <class T, class Alloc>
	bool operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		if ( lhs.size() != rhs.size() )
			return false;
		for ( typename ft::vector<T>::size_type i = 0; i < lhs.size(); i++ )
			if ( lhs[i] != rhs[i] )
				return false;
		return true;
	}

	template <class T, class Alloc>
	bool operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		return !( lhs == rhs );
	}

	template <class T, class Alloc>
	bool operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		typename ft::vector<T>::size_type len = ( lhs.size() < rhs.size() ) ? lhs.size : rhs.size();
		for ( typename ft::vector<T>::size_type i = 0; i < len; i++ )
			if ( lhs[i] >= rhs[i] )
				return false;
		return true;
	}

	template <class T, class Alloc>
	bool operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		return !( rhs < lhs );
	}

	template <class T, class Alloc>
	bool operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		return rhs < lhs;
	}

	template <class T, class Alloc>
	bool operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		return !( lhs < rhs );
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}

}

#endif
