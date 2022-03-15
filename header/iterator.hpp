#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <memory>

namespace ft {

	struct random_access_iterator_tag {};

	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type        value_type;
		typedef typename Iterator::difference_type   difference_type;
		typedef typename Iterator::pointer           pointer;
		typedef typename Iterator::reference         reference;
	};

	template <class T>
	struct iterator_traits<T*> {
		typedef ft::random_access_iterator_tag	   iterator_category;
		typedef T	                      		   value_type;
		typedef std::ptrdiff_t	              	   difference_type;
		typedef T*         	            		   pointer;
		typedef T&                      		   reference;
	};

	template <class T>
	class iterator 
	{

		public:

			typedef ft::random_access_iterator_tag					iterator_category;
			typedef std::ptrdiff_t									difference_type;
			typedef T												value_type;
			typedef T*												pointer;
			typedef T&												reference;

			/************************* Constructors and Destructor ***************************/

			iterator( void ) {}
			iterator( pointer ptr ) : _ptr( ptr ) {}
			iterator( iterator const & cpy ) { 
				*this = cpy;
			}
			~iterator( void ) {}

			/************************* Implement operators ***********************************/

			iterator& operator=( iterator const & rhs ) {
				this->_ptr = rhs._ptr;
				return *this;
			}
			reference operator*( void ) const {
				return *_ptr;
			}
			pointer operator->( void ) {
				return _ptr;
			}
			iterator& operator++( void ) {
				_ptr++;
				return *this;
			}
			iterator operator++( int ) {
				iterator tmp = *this;
				++( *this );
				return tmp;
			}
			iterator& operator--( void ) {
				_ptr--;
				return *this;
			}
			iterator operator--( int ) {
				iterator tmp = *this;
				--( *this );
				return tmp;
			}
			iterator operator+( difference_type n ) const {
				ft::iterator<value_type> res( *this );
				res += n;
				return res;
			}
			iterator operator-( difference_type n ) const {
				ft::iterator<value_type> res( *this );
				res -= n;
				return res;
			}
			iterator& operator+=( difference_type n ) {
				this->_ptr += n;
				return *this;
			}
			iterator& operator-=( difference_type n ) {
				this->_ptr -= n;
				return *this;
			}
			reference operator[]( difference_type index ) const {
				return *(this->_ptr + index);
			}

		private:

			pointer _ptr;

	};

	template <class T>
	class const_iterator 
	{

		public:

			typedef ft::random_access_iterator_tag					iterator_category;
			typedef std::ptrdiff_t									difference_type;
			typedef T												value_type;
			typedef T*												pointer;
			typedef T&												reference;

			/************************* Constructors and Destructor ***************************/

			const_iterator( void ) {}
			const_iterator( pointer ptr ) : _ptr( ptr ) {}
			const_iterator( const_iterator const & cpy ) { 
				*this = cpy;
			}
			~const_iterator( void ) {}

			/************************* Implement operators ***********************************/

			const_iterator& operator=( const_iterator const & rhs ) {
				this->_ptr = rhs._ptr;
				return *this;
			}
			value_type const & operator*( void ) const {
				return *_ptr;
			}
			T const * operator->( void ) {
				return _ptr;
			}
			const_iterator& operator++( void ) {
				_ptr++;
				return *this;
			}
			const_iterator operator++( int ) {
				const_iterator tmp = *this;
				++( *this );
				return tmp;
			}
			const_iterator& operator--( void ) {
				_ptr--;
				return *this;
			}
			const_iterator operator--( int ) {
				const_iterator tmp = *this;
				--( *this );
				return tmp;
			}
			const_iterator operator+( difference_type n ) const {
				ft::const_iterator<value_type> res( *this );
				res += n;
				return res;
			}
			const_iterator operator-( difference_type n ) const {
				ft::const_iterator<value_type> res( *this );
				res -= n;
				return res;
			}
			const_iterator& operator+=( difference_type n ) {
				this->_ptr += n;
				return *this;
			}
			const_iterator& operator-=( difference_type n ) {
				this->_ptr -= n;
				return *this;
			}
			value_type const & operator[]( difference_type index ) const {
				return *(this->_ptr + index);
			}

		private:

			pointer _ptr;

	};

	template <class Iter>
	class reverse_iterator {

		private:

			Iter _iter;

		public:

			typedef Iter												iterator_type;
			typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iter>::difference_type		difference_type;
			typedef typename iterator_traits<Iter>::value_type			value_type;
			typedef typename iterator_traits<Iter>::pointer				pointer;
			typedef typename iterator_traits<Iter>::reference			reference;

			/************************* Constructors and Destructor ***************************/

			reverse_iterator( void ) {}
			explicit reverse_iterator( iterator_type it ) : _iter( it ) {}
			template <class It>
			reverse_iterator( reverse_iterator<It> const & cpy ) { 
				this->_iter = cpy._iter;
			}
			~reverse_iterator( void ) {}

			/************************* Member Functions **************************************/

			iterator_type base( void ) const {
				return _iter;
			}

			/************************* Implement operators ***********************************/

			reverse_iterator& operator=( reverse_iterator const & rhs ) {
				this->_iter = rhs._iter;
				return *this;
			}
			reference operator*( void ) const {
				return *_iter;
			}
			pointer operator->( void ) {
				return &( *_iter );
			}
			reverse_iterator& operator++( void ) {
				_iter--;
				return *this;
			}
			reverse_iterator operator++( int ) {
				reverse_iterator tmp = *this;
				--_iter;
				return tmp;
			}
			reverse_iterator& operator--( void ) {
				_iter++;
				return *this;
			}
			reverse_iterator operator--( int ) {
				reverse_iterator tmp = *this;
				++_iter;
				return tmp;
			}
			reverse_iterator operator+( difference_type n ) const {
				ft::reverse_iterator<Iter> res( *this );
				res += n;
				return res;
			}
			reverse_iterator operator-( difference_type n ) const {
				ft::reverse_iterator<Iter> res( *this );
				res -= n;
				return res;
			}
			reverse_iterator& operator+=( difference_type n ) {
				this->_iter -= n;
				return *this;
			}
			reverse_iterator& operator-=( difference_type n ) {
				this->_iter += n;
				return *this;
			}
			reference operator[]( size_t index ) const {
				return *(this->_iter - index);
			}
	};

	template <class ConstIter>
	class const_reverse_iterator {

		private:

			ConstIter _iter;

		public:

			typedef ConstIter												iterator_type;
			typedef typename iterator_traits<ConstIter>::iterator_category	iterator_category;
			typedef typename iterator_traits<ConstIter>::difference_type	difference_type;
			typedef typename iterator_traits<ConstIter>::value_type			value_type;
			typedef typename iterator_traits<ConstIter>::pointer			pointer;
			typedef typename iterator_traits<ConstIter>::reference			reference;

			/************************* Constructors and Destructor ***************************/

			const_reverse_iterator( void ) {}
			explicit const_reverse_iterator( iterator_type it ) : _iter( it ) {}
			template <class ConstIt>
			const_reverse_iterator( const_reverse_iterator<ConstIt> const & cpy ) { 
				this->_iter = cpy._iter;
			}
			~const_reverse_iterator( void ) {}

			/************************* Member Functions **************************************/

			iterator_type base( void ) const {
				return _iter;
			}

			/************************* Implement operators ***********************************/

			const_reverse_iterator& operator=( const_reverse_iterator const & rhs ) {
				this->_iter = rhs._iter;
				return *this;
			}
			const value_type & operator*( void ) const {
				return *_iter;
			}
			const value_type * operator->( void ) {
				return &( *_iter );
			}
			const_reverse_iterator& operator++( void ) {
				_iter--;
				return *this;
			}
			const_reverse_iterator operator++( int ) {
				const_reverse_iterator tmp = *this;
				--_iter;
				return tmp;
			}
			const_reverse_iterator& operator--( void ) {
				_iter++;
				return *this;
			}
			const_reverse_iterator operator--( int ) {
				const_reverse_iterator tmp = *this;
				++_iter;
				return tmp;
			}
			const_reverse_iterator operator+( difference_type n ) const {
				ft::const_reverse_iterator<ConstIter> res( *this );
				res += n;
				return res;
			}
			const_reverse_iterator operator-( difference_type n ) const {
				ft::const_reverse_iterator<ConstIter> res( *this );
				res -= n;
				return res;
			}
			const_reverse_iterator& operator+=( difference_type n ) {
				this->_iter -= n;
				return *this;
			}
			const_reverse_iterator& operator-=( difference_type n ) {
				this->_iter += n;
				return *this;
			}
			value_type const & operator[]( size_t index ) const {
				return *(this->_iter - index);
			}
	};

	/************************* Non member function operators *********************************/

	template <class T>
	bool operator== ( iterator<T> const & lhs, iterator<T> const & rhs ) {
		return &*lhs == &*rhs;
	}
	template <class T>
	bool operator!= ( iterator<T> const & lhs, iterator<T> const & rhs ) {
		return &*lhs != &*rhs;
	}
	template <class T>
	bool operator<( iterator<T> const & lhs, iterator<T> const & rhs ) {
		return &*lhs < &*rhs;
	}
	template <class T>
	bool operator>( iterator<T> const & lhs, iterator<T> const & rhs ) {
		return &*lhs > &*rhs;
	}
	template <class T>
	bool operator<=( iterator<T> const & lhs, iterator<T> const & rhs ) {
		return &*lhs <= &*rhs;
	}
	template <class T>
	bool operator>=( iterator<T> const & lhs, iterator<T> const & rhs ) {
		return &*lhs >= &*rhs;
	}
	template <class T>
	iterator<T> operator+( typename iterator<T>::difference_type n, iterator<T> const & rev_it ) {
		return rev_it + n;
	}
	template <class T>
	typename iterator<T>::difference_type operator-( iterator<T> const & lhs, iterator<T> const & rhs ) {
		return lhs.base() - rhs.base();
	}


	template <class T>
	bool operator== ( const_iterator<T> const & lhs, const_iterator<T> const & rhs ) {
		return &*lhs == &*rhs;
	}
	template <class T>
	bool operator!= ( const_iterator<T> const & lhs, const_iterator<T> const & rhs ) {
		return &*lhs != &*rhs;
	}
	template <class T>
	bool operator<( const_iterator<T> const & lhs, const_iterator<T> const & rhs ) {
		return &*lhs < &*rhs;
	}
	template <class T>
	bool operator>( const_iterator<T> const & lhs, const_iterator<T> const & rhs ) {
		return &*lhs > &*rhs;
	}
	template <class T>
	bool operator<=( const_iterator<T> const & lhs, const_iterator<T> const & rhs ) {
		return &*lhs <= &*rhs;
	}
	template <class T>
	bool operator>=( const_iterator<T> const & lhs, const_iterator<T> const & rhs ) {
		return &*lhs >= &*rhs;
	}
	template <class T>
	const_iterator<T> operator+( typename const_iterator<T>::difference_type n, const_iterator<T> const & rev_it ) {
		return rev_it + n;
	}
	template <class T>
	typename const_iterator<T>::difference_type operator-( const_iterator<T> const & lhs, const_iterator<T> const & rhs ) {
		return lhs.base() - rhs.base();
	}


	template <class Iter>
	bool operator==( reverse_iterator<Iter> const & lhs, reverse_iterator<Iter> const & rhs ) {
		return &*lhs == &*rhs;
	}
	template <class Iter>
	bool operator!=( reverse_iterator<Iter> const & lhs, reverse_iterator<Iter> const & rhs ) {
		return &*lhs != &*rhs;
	}
	template <class Iter>
	bool operator<( reverse_iterator<Iter> const & lhs, reverse_iterator<Iter> const & rhs ) {
		return &*lhs > &*rhs;
	}
	template <class Iter>
	bool operator<=( reverse_iterator<Iter> const & lhs, reverse_iterator<Iter> const & rhs ) {
		return &*lhs >= &*rhs;
	}
	template <class Iter>
	bool operator>( reverse_iterator<Iter> const & lhs, reverse_iterator<Iter> const & rhs ) {
		return &*lhs < &*rhs;
	}
	template <class Iter>
	bool operator>=( reverse_iterator<Iter> const & lhs, reverse_iterator<Iter> const & rhs ) {
		return &*lhs <= &*rhs;
	}
	template <class Iter>
	reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, reverse_iterator<Iter> const & rev_it ) {
		return rev_it + n;
	}
	template <class Iter>
	typename reverse_iterator<Iter>::difference_type operator-( reverse_iterator<Iter> const & lhs, reverse_iterator<Iter> const & rhs ) {
		return rhs.base() - lhs.base();
	}


	template <class ConstIter>
	bool operator==( const_reverse_iterator<ConstIter> const & lhs, const_reverse_iterator<ConstIter> const & rhs ) {
		return &*lhs == &*rhs;
	}
	template <class ConstIter>
	bool operator!=( const_reverse_iterator<ConstIter> const & lhs, const_reverse_iterator<ConstIter> const & rhs ) {
		return &*lhs != &*rhs;
	}
	template <class ConstIter>
	bool operator<( const_reverse_iterator<ConstIter> const & lhs, const_reverse_iterator<ConstIter> const & rhs ) {
		return &*lhs > &*rhs;
	}
	template <class ConstIter>
	bool operator<=( const_reverse_iterator<ConstIter> const & lhs, const_reverse_iterator<ConstIter> const & rhs ) {
		return &*lhs >= &*rhs;
	}
	template <class ConstIter>
	bool operator>( const_reverse_iterator<ConstIter> const & lhs, const_reverse_iterator<ConstIter> const & rhs ) {
		return &*lhs < &*rhs;
	}
	template <class ConstIter>
	bool operator>=( const_reverse_iterator<ConstIter> const & lhs, const_reverse_iterator<ConstIter> const & rhs ) {
		return &*lhs <= &*rhs;
	}
	template <class ConstIter>
	const_reverse_iterator<ConstIter> operator+( typename const_reverse_iterator<ConstIter>::difference_type n, const_reverse_iterator<ConstIter> const & rev_it ) {
		return rev_it + n;
	}
	template <class ConstIter>
	typename const_reverse_iterator<ConstIter>::difference_type operator-( const_reverse_iterator<ConstIter> const & lhs, const_reverse_iterator<ConstIter> const & rhs ) {
		return rhs.base() - lhs.base();
	}

}

#endif