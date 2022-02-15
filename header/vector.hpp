#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

		private:

			class Iterator 
			{

				private:

					pointer _ptr;

				public:

					using iterator_category = std::random_access_iterator_tag;
					using difference_type   = std::ptrdiff_t;
					using value_type        = T;
					using pointer           = value_type*;
					using reference         = value_type&;

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

			};

			class ConstantIterator 
			{

				private:

					pointer _ptr;

				public:

					using iterator_category = std::random_access_iterator_tag;
					using difference_type   = std::ptrdiff_t;
					using value_type        = T;
					using pointer           = value_type*;
					using reference         = value_type&;

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
					const reference operator*( void ) const {
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

			};

			template <class Iterator>
			class ReverseIterator {

				private:

					Iterator _iter;

				public:

					using iterator_type		= Iterator;
					using iterator_category = Iterator::iterator_category;
					using difference_type   = std::ptrdiff_t;
					using value_type        = Iterator::value_type;
					using pointer           = Iterator::pointer;
					using reference         = Iterator::reference;

					/************************* Constructors and Destructor ***************************/

					ReverseIterator( void ) {}
					explicit ReverseIterator( iterator_type it ) : _iter( it ) {}
					template <class Iter>
					ReverseIterator( ReverseIterator<Iter> const & cpy ) { 
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
		
		public:

			/************************* Non member function operators *********************************/

			bool Iterator::operator== ( Iterator const & lhs, Iterator const & rhs ) {
				return lhs._ptr == rhs._ptr;
			}
			bool Iterator::operator!= ( Iterator const & lhs, Iterator const & rhs ) {
				return lhs._ptr != rhs._ptr;
			}
			bool Iterator::operator<( Iterator const & lhs, Iterator const & rhs ) {
				return lhs._ptr < rhs._ptr;
			}
			bool Iterator::operator>( Iterator const & lhs, Iterator const & rhs ) {
				return lhs._ptr > rhs._ptr;
			}
			bool Iterator::operator<=( Iterator const & lhs, Iterator const & rhs ) {
				return lhs._ptr <= rhs._ptr;
			}
			bool Iterator::operator>=( Iterator const & lhs, Iterator const & rhs ) {
				return lhs._ptr >= rhs._ptr;
			}

			bool ConstantIterator::operator== ( ConstantIterator const & lhs, ConstantIterator const & rhs ) {
				return lhs._ptr == rhs._ptr;
			}
			bool ConstantIterator::operator!= ( ConstantIterator const & lhs, ConstantIterator const & rhs ) {
				return lhs._ptr != rhs._ptr;
			}
			bool ConstantIterator::operator<( ConstantIterator const & lhs, ConstantIterator const & rhs ) {
				return lhs._ptr < rhs._ptr;
			}
			bool ConstantIterator::operator>( ConstantIterator const & lhs, ConstantIterator const & rhs ) {
				return lhs._ptr > rhs._ptr;
			}
			bool ConstantIterator::operator<=( ConstantIterator const & lhs, ConstantIterator const & rhs ) {
				return lhs._ptr <= rhs._ptr;
			}
			bool ConstantIterator::operator>=( ConstantIterator const & lhs, ConstantIterator const & rhs ) {
				return lhs._ptr >= rhs._ptr;
			}

			template <class Iterator>
			bool ReverseIterator<Iterator>::operator==( ReverseIterator<Iterator> const & lhs, ReverseIterator<Iterator> const & rhs ) {
				return lhs._iter == rhs._iter;
			}
			template <class Iterator>
			bool ReverseIterator<Iterator>::operator!=( ReverseIterator<Iterator> const & lhs, ReverseIterator<Iterator> const & rhs ) {
				return lhs._iter != rhs._iter;
			}
			template <class Iterator>
			bool ReverseIterator<Iterator>::operator<( ReverseIterator<Iterator> const & lhs, ReverseIterator<Iterator> const & rhs ) {
				return lhs._iter > rhs._iter;
			}
			template <class Iterator>
			bool ReverseIterator<Iterator>::operator<=( ReverseIterator<Iterator> const & lhs, ReverseIterator<Iterator> const & rhs ) {
				return lhs._iter >= rhs._iter;
			}
			template <class Iterator>
			bool ReverseIterator<Iterator>::operator>( ReverseIterator<Iterator> const & lhs, ReverseIterator<Iterator> const & rhs ) {
				return lhs._iter < rhs._iter;
			}
			template <class Iterator>
			bool ReverseIterator<Iterator>::operator>=( ReverseIterator<Iterator> const & lhs, ReverseIterator<Iterator> const & rhs ) {
				return lhs._iter <= rhs._iter;
			}
			template <class Iterator>
			ReverseIterator<Iterator> ReverseIterator<Iterator>::operator+( typename ReverseIterator<Iterator>::difference_type n, ReverseIterator<Iterator> const & rev_it ) {
				return rev_it - n;
			}
			template <class Iterator>
			typename ReverseIterator<Iterator>::difference_type ReverseIterator<Iterator>::operator- ( ReverseIterator<Iterator> const & lhs, ReverseIterator<Iterator> const & rhs ) {
				return rhs.base() - lhs.base();
			}

	};
}

#endif