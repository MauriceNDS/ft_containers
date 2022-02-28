#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft {

	template<bool B, class T = void>
	struct enable_if {};
	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <class T, T v>
	struct integral_constant {
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
		operator T() { return v; }
	};

	typedef integral_constant<bool,false> false_type;
	typedef integral_constant<bool,true> true_type;

	template<typename> struct is_integral_base : public false_type {};

	template<> struct is_integral_base<bool> : public true_type {};
	template<> struct is_integral_base<int> : public true_type {};
	template<> struct is_integral_base<short> : public true_type {};
	template<> struct is_integral_base<char> : public true_type {};
	template<> struct is_integral_base<wchar_t> : public true_type {};
	template<> struct is_integral_base<long> : public true_type {};
	template<> struct is_integral_base<long long> : public true_type {};
	template<> struct is_integral_base<unsigned char> : public true_type {};
	template<> struct is_integral_base<unsigned short> : public true_type {};
	template<> struct is_integral_base<unsigned int> : public true_type {};
	template<> struct is_integral_base<unsigned long> : public true_type {};
	template<> struct is_integral_base<unsigned long long> : public true_type {};

	template<typename T> struct is_integral : public is_integral_base<T> {};


}

#endif