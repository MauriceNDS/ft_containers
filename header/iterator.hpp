#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <memory>

namespace ft {

	template <class T>
	class Iterator 
	{

		public:

			typedef std::random_access_iterator_tag		iterator_category;
			typedef std::ptrdiff_t						difference_type;
			typedef T									value_type;
			typedef value_type*							pointer;
			typedef value_type&							reference;

			/************************* Constructors and Destructor ***************************/

			Iterator( void ) {}
			Iterator( pointer ptr ) : _ptr( ptr ) {}
			Iterator( Iterator const & cpy ) { 
				*this = cpy;
			}
			~Iterator( void ) {}

			/************************* Implement operators ***********************************/

			Iterator& operator=( Iterator const & rhs ) {
				this->_ptr = rhs._ptr;
				return *this;
			}
			reference operator*( void ) const {
				return *_ptr;
			}
			pointer operator->( void ) {
				return _ptr;
			}
			Iterator& operator++( void ) {
				_ptr++;
				return *this;
			}
			Iterator operator++( int ) {
				Iterator tmp = *this;
				++( *this );
				return tmp;
			}
			Iterator& operator--( void ) {
				_ptr--;
				return *this;
			}
			Iterator operator--( int ) {
				Iterator tmp = *this;
				--( *this );
				return tmp;
			}
			Iterator operator+( difference_type n ) const {
				return this->_ptr + n;
			}
			Iterator operator-( difference_type n ) const {
				return this->_ptr - n;
			}
			Iterator& operator+=( difference_type n ) {
				return this->_ptr += n;
			}
			Iterator& operator-=( difference_type n ) {
				return this->_ptr -= n;
			}
			Iterator& operator[]( size_t index ) const {
				return this->_ptr + index;
			}

		private:

			pointer _ptr;

	};

	template <class T>
	class ConstantIterator 
	{

		public:

			typedef std::random_access_iterator_tag		iterator_category;
			typedef std::ptrdiff_t						difference_type;
			typedef T									value_type;
			typedef value_type*							pointer;
			typedef value_type&							reference;

			/************************* Constructors and Destructor ***************************/

			ConstantIterator( void ) {}
			ConstantIterator( pointer ptr ) : _ptr( ptr ) {}
			ConstantIterator( ConstantIterator const & cpy ) { 
				*this = cpy;
			}
			~ConstantIterator( void ) {}

			/************************* Implement operators ***********************************/

			ConstantIterator& operator=( ConstantIterator const & rhs ) {
				this->_ptr = rhs._ptr;
				return *this;
			}
			value_type const & operator*( void ) const {
				return *_ptr;
			}
			pointer operator->( void ) {
				return _ptr;
			}
			ConstantIterator& operator++( void ) {
				_ptr++;
				return *this;
			}
			ConstantIterator operator++( int ) {
				ConstantIterator tmp = *this;
				++( *this );
				return tmp;
			}
			ConstantIterator& operator--( void ) {
				_ptr--;
				return *this;
			}
			ConstantIterator operator--( int ) {
				ConstantIterator tmp = *this;
				--( *this );
				return tmp;
			}
			ConstantIterator operator+( difference_type n ) const {
				return this->_ptr + n;
			}
			ConstantIterator operator-( difference_type n ) const {
				return this->_ptr - n;
			}
			ConstantIterator& operator+=( difference_type n ) {
				return this->_ptr += n;
			}
			ConstantIterator& operator-=( difference_type n ) {
				return this->_ptr -= n;
			}
			ConstantIterator& operator[]( size_t index ) const {
				return this->_ptr + index;
			}

		private:

			pointer _ptr;

	};

	template <class Iter>
	class ReverseIterator {

		private:

			Iter _iter;

		public:

			typedef Iter								iterator_type;
			typedef typename Iter::iterator_category	iterator_category;
			typedef std::ptrdiff_t						difference_type;
			typedef typename Iter::value_type			value_type;
			typedef typename Iter::pointer				pointer;
			typedef typename Iter::reference			reference;

			/************************* Constructors and Destructor ***************************/

			ReverseIterator( void ) {}
			explicit ReverseIterator( iterator_type it ) : _iter( it ) {}
			template <class It>
			ReverseIterator( ReverseIterator<It> const & cpy ) { 
				this->_iter = cpy._iter;
			}
			~ReverseIterator( void ) {}

			/************************* Member Functions **************************************/

			iterator_type base( void ) const {
				return _iter;
			}

			/************************* Implement operators ***********************************/

			ReverseIterator& operator=( ReverseIterator const & rhs ) {
				this->_iter = rhs._iter;
				return *this;
			}
			reference operator*( void ) const {
				return *_iter;
			}
			pointer operator->( void ) {
				return &( *_iter );
			}
			ReverseIterator& operator++( void ) {
				_iter--;
				return *this;
			}
			ReverseIterator operator++( int ) {
				ReverseIterator tmp = *this;
				--( *this );
				return tmp;
			}
			ReverseIterator& operator--( void ) {
				_iter++;
				return *this;
			}
			ReverseIterator operator--( int ) {
				ReverseIterator tmp = *this;
				++( *this );
				return tmp;
			}
			ReverseIterator operator+( difference_type n ) const {
				return this->_iter - n;
			}
			ReverseIterator operator-( difference_type n ) const {
				return this->_iter + n;
			}
			ReverseIterator& operator+=( difference_type n ) {
				return this->_iter += n;
			}
			ReverseIterator& operator-=( difference_type n ) {
				return this->_iter -= n;
			}
			ReverseIterator& operator[]( size_t index ) const {
				return this->_iter - index;
			}
	};

	template <class ConstIter>
	class ConstantReverseIterator {

		private:

			ConstIter _iter;

		public:

			typedef ConstIter									iterator_type;
			typedef typename ConstIter::iterator_category		iterator_category;
			typedef std::ptrdiff_t								difference_type;
			typedef typename ConstIter::value_type				value_type;
			typedef typename ConstIter::pointer					pointer;
			typedef typename ConstIter::reference				reference;

			/************************* Constructors and Destructor ***************************/

			ConstantReverseIterator( void ) {}
			explicit ConstantReverseIterator( iterator_type it ) : _iter( it ) {}
			template <class ConstIt>
			ConstantReverseIterator( ConstantReverseIterator<ConstIt> const & cpy ) { 
				this->_iter = cpy._iter;
			}
			~ConstantReverseIterator( void ) {}

			/************************* Member Functions **************************************/

			iterator_type base( void ) const {
				return _iter;
			}

			/************************* Implement operators ***********************************/

			ConstantReverseIterator& operator=( ConstantReverseIterator const & rhs ) {
				this->_iter = rhs._iter;
				return *this;
			}
			const reference operator*( void ) const {
				return *_iter;
			}
			pointer operator->( void ) {
				return &( *_iter );
			}
			ConstantReverseIterator& operator++( void ) {
				_iter--;
				return *this;
			}
			ConstantReverseIterator operator++( int ) {
				ConstantReverseIterator tmp = *this;
				--( *this );
				return tmp;
			}
			ConstantReverseIterator& operator--( void ) {
				_iter++;
				return *this;
			}
			ConstantReverseIterator operator--( int ) {
				ConstantReverseIterator tmp = *this;
				++( *this );
				return tmp;
			}
			ConstantReverseIterator operator+( difference_type n ) const {
				return this->_iter - n;
			}
			ConstantReverseIterator operator-( difference_type n ) const {
				return this->_iter + n;
			}
			ConstantReverseIterator& operator+=( difference_type n ) {
				return this->_iter += n;
			}
			ConstantReverseIterator& operator-=( difference_type n ) {
				return this->_iter -= n;
			}
			ConstantReverseIterator& operator[]( size_t index ) const {
				return this->_iter - index;
			}
	};

	/************************* Non member function operators *********************************/

	template <class T>
	bool operator== ( Iterator<T> const & lhs, Iterator<T> const & rhs ) {
		return *lhs == *rhs;
	}
	template <class T>
	bool operator!= ( Iterator<T> const & lhs, Iterator<T> const & rhs ) {
		return *lhs != *rhs;
	}
	template <class T>
	bool operator<( Iterator<T> const & lhs, Iterator<T> const & rhs ) {
		return *lhs < *rhs;
	}
	template <class T>
	bool operator>( Iterator<T> const & lhs, Iterator<T> const & rhs ) {
		return *lhs > *rhs;
	}
	template <class T>
	bool operator<=( Iterator<T> const & lhs, Iterator<T> const & rhs ) {
		return *lhs <= *rhs;
	}
	template <class T>
	bool operator>=( Iterator<T> const & lhs, Iterator<T> const & rhs ) {
		return *lhs >= *rhs;
	}
	template <class T>
	Iterator<T> operator+( typename Iterator<T>::difference_type n, Iterator<T> const & rev_it ) {
		return rev_it + n;
	}
	template <class T>
	typename Iterator<T>::difference_type operator- ( Iterator<T> const & lhs, Iterator<T> const & rhs ) {
		return lhs.base() - rhs.base();
	}


	template <class T>
	bool operator== ( ConstantIterator<T> const & lhs, ConstantIterator<T> const & rhs ) {
		return *lhs == *rhs;
	}
	template <class T>
	bool operator!= ( ConstantIterator<T> const & lhs, ConstantIterator<T> const & rhs ) {
		return *lhs != *rhs;
	}
	template <class T>
	bool operator<( ConstantIterator<T> const & lhs, ConstantIterator<T> const & rhs ) {
		return *lhs < *rhs;
	}
	template <class T>
	bool operator>( ConstantIterator<T> const & lhs, ConstantIterator<T> const & rhs ) {
		return *lhs > *rhs;
	}
	template <class T>
	bool operator<=( ConstantIterator<T> const & lhs, ConstantIterator<T> const & rhs ) {
		return *lhs <= *rhs;
	}
	template <class T>
	bool operator>=( ConstantIterator<T> const & lhs, ConstantIterator<T> const & rhs ) {
		return *lhs >= *rhs;
	}
	template <class T>
	ConstantIterator<T> operator+( typename ConstantIterator<T>::difference_type n, ConstantIterator<T> const & rev_it ) {
		return rev_it + n;
	}
	template <class T>
	typename ConstantIterator<T>::difference_type operator- ( ConstantIterator<T> const & lhs, ConstantIterator<T> const & rhs ) {
		return lhs.base() - rhs.base();
	}


	template <class Iter>
	bool operator==( ReverseIterator<Iter> const & lhs, ReverseIterator<Iter> const & rhs ) {
		return *lhs == *rhs;
	}
	template <class Iter>
	bool operator!=( ReverseIterator<Iter> const & lhs, ReverseIterator<Iter> const & rhs ) {
		return *lhs != *rhs;
	}
	template <class Iter>
	bool operator<( ReverseIterator<Iter> const & lhs, ReverseIterator<Iter> const & rhs ) {
		return *lhs > *rhs;
	}
	template <class Iter>
	bool operator<=( ReverseIterator<Iter> const & lhs, ReverseIterator<Iter> const & rhs ) {
		return *lhs >= *rhs;
	}
	template <class Iter>
	bool operator>( ReverseIterator<Iter> const & lhs, ReverseIterator<Iter> const & rhs ) {
		return *lhs < *rhs;
	}
	template <class Iter>
	bool operator>=( ReverseIterator<Iter> const & lhs, ReverseIterator<Iter> const & rhs ) {
		return *lhs <= *rhs;
	}
	template <class Iter>
	ReverseIterator<Iter> operator+( typename ReverseIterator<Iter>::difference_type n, ReverseIterator<Iter> const & rev_it ) {
		return rev_it - n;
	}
	template <class Iter>
	typename ReverseIterator<Iter>::difference_type operator- ( ReverseIterator<Iter> const & lhs, ReverseIterator<Iter> const & rhs ) {
		return rhs.base() - lhs.base();
	}


	template <class ConstIter>
	bool operator==( ConstantReverseIterator<ConstIter> const & lhs, ConstantReverseIterator<ConstIter> const & rhs ) {
		return *lhs == *rhs;
	}
	template <class ConstIter>
	bool operator!=( ConstantReverseIterator<ConstIter> const & lhs, ConstantReverseIterator<ConstIter> const & rhs ) {
		return *lhs != *rhs;
	}
	template <class ConstIter>
	bool operator<( ConstantReverseIterator<ConstIter> const & lhs, ConstantReverseIterator<ConstIter> const & rhs ) {
		return *lhs > *rhs;
	}
	template <class ConstIter>
	bool operator<=( ConstantReverseIterator<ConstIter> const & lhs, ConstantReverseIterator<ConstIter> const & rhs ) {
		return *lhs >= *rhs;
	}
	template <class ConstIter>
	bool operator>( ConstantReverseIterator<ConstIter> const & lhs, ConstantReverseIterator<ConstIter> const & rhs ) {
		return *lhs < *rhs;
	}
	template <class ConstIter>
	bool operator>=( ConstantReverseIterator<ConstIter> const & lhs, ConstantReverseIterator<ConstIter> const & rhs ) {
		return *lhs <= *rhs;
	}
	template <class ConstIter>
	ConstantReverseIterator<ConstIter> operator+( typename ConstantReverseIterator<ConstIter>::difference_type n, ConstantReverseIterator<ConstIter> const & rev_it ) {
		return rev_it - n;
	}
	template <class ConstIter>
	typename ConstantReverseIterator<ConstIter>::difference_type operator- ( ConstantReverseIterator<ConstIter> const & lhs, ConstantReverseIterator<ConstIter> const & rhs ) {
		return rhs.base() - lhs.base();
	}

}

#endif