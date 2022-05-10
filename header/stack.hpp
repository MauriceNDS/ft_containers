#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {

    template <class T, class Container = ft::vector<T> >
    class stack {
        
        public:

            /************************************* Typedefs ******************************************/

            typedef T                   value_type;
            typedef Container           container_type;
            typedef size_t              size_type;

            /************************************* Friends *******************************************/

            template <class U, class C>
            friend bool operator==( const stack<U,C>& lhs, const stack<U,C>& rhs );
            template <class U, class C>
            friend bool operator!=( const stack<U,C>& lhs, const stack<U,C>& rhs );
            template <class U, class C>
            friend bool operator<( const stack<U,C>& lhs, const stack<U,C>& rhs );
            template <class U, class C>
            friend bool operator<=( const stack<U,C>& lhs, const stack<U,C>& rhs );
            template <class U, class C>
            friend bool operator>( const stack<U,C>& lhs, const stack<U,C>& rhs );
            template <class U, class C>
            friend bool operator>=( const stack<U,C>& lhs, const stack<U,C>& rhs );

            /************************************* Constructor ***************************************/

            explicit stack( const container_type& ctnr = container_type() ) : _data( ctnr ) {}
            
            /************************************* Destructor ****************************************/

            ~stack( void ) {}
            
            /************************************* Member functions **********************************/

            bool empty( void ) const {
                return _data.empty();
            }

            size_type size( void ) const {
                return _data.size();
            }

            value_type& top( void ) {
                return _data.back();
            }

            const value_type& top( void ) const {
                return _data.back();
            }

            void push( const value_type& val ) {
                _data.push_back( val );
            }

            void pop( void ) {
                _data.pop_back();
            }

        protected:

            container_type _data;
    
    };

    template <class T, class Container>
    bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
        return lhs._data == rhs._data;
    }
    template <class T, class Container>
    bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
        return lhs._data != rhs._data;
    }
    template <class T, class Container>
    bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
        return lhs._data < rhs._data;
    }
    template <class T, class Container>
    bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
        return lhs._data <= rhs._data;
    }
    template <class T, class Container>
    bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
        return lhs._data > rhs._data;
    }
    template <class T, class Container>
    bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
        return lhs._data >= rhs._data;
    }

}

#endif