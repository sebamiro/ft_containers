/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:45:43 by smiro             #+#    #+#             */
/*   Updated: 2023/02/20 18:45:46 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

#include "Iterator/iterator_traits.hpp"
#include "Iterator/random_access_iterator.hpp"
#include "Iterator/reverse_iterator.hpp"
#include <memory>
#include <stdexcept>

namespace ft
{

template <class Iterator1, class Iterator2>
bool
equal(Iterator1 first1, Iterator1 last1, Iterator2 first2) {
	while (first1 != last1) {
		if (*first1 != *first2)
			return false;
		++first1;
		++first2;
	}
	return true;
}

template <class Iterator1, class Iterator2, class BinaryPredicate>
bool
equal(Iterator1 first1, Iterator1 last1,
		Iterator2 first2, BinaryPredicate pred) {
	while (first1 != last1) {
		if (!pred(first1, first2))
			return false;
		++first1;
		++first2;
	}
	return true;
}

template <class Iterator1, class Iterator2>
bool
lexicographical_compare(Iterator1 first1, Iterator1 last1,
						Iterator2 first2, Iterator2 last2) {
	while (first1 != last1) {
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		first1++;
		first2++;
	}
	return (first2 != last2);
}

template <class Iterator1, class Iterator2, class Compare>
bool	lexicographical_compare(Iterator1 first1, Iterator1 last1,
								Iterator2 first2, Iterator2 last2,
								Compare comp) {
	while (first1 != last1) {
		if (first2 == last2 || comp(first2, first1))
			return false;
		else if (comp(first1, first2))
			return true;
	}
	return (first2 != last2);
}

template <class T1, class T2>
struct pair
{
	typedef T1	first_type;
	typedef T2	second_type;

	first_type	first;
	second_type	second;

	pair(void)
	: first(), second() {}

	pair(const first_type& t1, const second_type& t2)
	: first(t1), second(t2) {}

	template<class U, class V>
	pair(const pair<U, V>& cpy)
	: first(cpy.first), second(cpy.second) {};

	pair&
	operator=(const pair& src) {
		if (*this == src)
			return *this;

		this->first = src.first;
		this->second = src.second;
		return *this;
	}

};

template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y)
{ return pair<T1, T2>(x, y); }

template <class T1, class T2>
bool
operator==(const pair<T1, T2>& lhs,
			const pair<T1, T2>& rhs)
{ return lhs.first == rhs.first && lhs.second == rhs.second; }

template <class T1, class T2>
bool
operator!=(const pair<T1, T2>& lhs,
			const pair<T1, T2>& rhs)
{ return !(lhs == rhs); }

template <class T1, class T2>
bool
operator<(const pair<T1, T2>& lhs,
			const pair<T1, T2>& rhs)
{ return lhs.first < rhs.first ||
		(!(rhs.first < lhs.first) &&
		lhs.second < rhs.second); }

template <class T1, class T2>
bool
operator<=(const pair<T1, T2>& lhs,
			const pair<T1, T2>& rhs)
{ return !(rhs < lhs); }

template <class T1, class T2>
bool
operator>(const pair<T1, T2>& lhs,
			const pair<T1, T2>& rhs)
{ return rhs < lhs; }

template <class T1, class T2>
bool
operator>=(const pair<T1, T2>& lhs,
			const pair<T1, T2>& rhs)
{ return !(lhs<rhs); }

template <bool is_integral, typename T>
struct is_integral_res
{
	typedef T type;

	static const bool value = is_integral;
	operator type() const
	{ return value; }
};

template <typename> struct is_integral_type : public is_integral_res<false, bool> {};
template <> struct is_integral_type<bool> : public is_integral_res<true, bool> {};
template <> struct is_integral_type<char> : public is_integral_res<true, char> {};
template <> struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};
template <> struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};
template <> struct is_integral_type<char16_t> : public is_integral_res<true, char16_t> {};
template <> struct is_integral_type<char32_t> : public is_integral_res<true, char32_t> {};
template <> struct is_integral_type<wchar_t> : public is_integral_res<true, wchar_t> {};
template <> struct is_integral_type<short int> : public is_integral_res<true, short int> {};
template <> struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};
template <> struct is_integral_type<int> : public is_integral_res<true, int> {};
template <> struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};
template <> struct is_integral_type<long int> : public is_integral_res<true, long int> {};
template <> struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
template <> struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};
template <> struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};


template <typename T>
struct is_integral
: public is_integral_type<T> {};

template <bool Cond, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T>
{ typedef T type; };

template <class InputIterator>
typename ft::iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last) {
	typename ft::iterator_traits<InputIterator>::difference_type	len = 0;

	for (; first != last; first++)
		len++;
	return len;
}

template <class Arg1, class Arg2, class Result>
struct binary_function
{
	typedef Arg1	first_argument_type;
	typedef Arg2	second_argument_type;
	typedef Result	result_type;
};

template <class T>
struct less : binary_function<T, T, bool>
{
	bool
	operator()(const T & x, const T & y) const
	{ return x < y; }
};

}//ft namespace

#endif//UTILITY_HPP
