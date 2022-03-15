#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "iterator.hpp"

namespace ft {

	template <class It>
	typename It::difference_type 
    vector_do_distance( It first, It last ) {
   		typename It::difference_type result = 0;

		while ( first != last ) {
        	++first;
        	++result;
   		}
    	return result;
	}
	
}

#endif