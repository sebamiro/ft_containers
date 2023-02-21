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

namespace ft
{
	
	template < class Iterator1, class Iterator2 >
	bool	equal(Iterator1 first1, Iterator1 last1, Iterator2 first2)
	{
		while (first1 != last1)
		{
				if (*first1 != *first2)
					return false;
				++first1; ++first2;
		}
		return true;
	};
	
	template < class Iterator1, class Iterator2, class BinaryPredicate >
	bool	equal(Iterator1 first1, Iterator1 last1,
							Iterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
				if (!pred(first1, first2))
					return false;
				++first1; ++first2;
		}
		return true;
	};
	
	template < class Iterator1, class Iterator2 >
	bool	lexicographical_compare(Iterator1 first1, Iterator1 last1,
																Iterator2 first2, Iterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
		}
		return (first2 != last2);
	}
	
	template < class Iterator1, class Iterator2, class Compare >
	bool	lexicographical_compare(Iterator1 first1, Iterator1 last1,
																Iterator2 first2, Iterator2 last2,
																Compare comp)
	{
		while (first1 != last1)
		{
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
		
		pair(void) : first(), second() {};
		pair(const first_type & t1, const second_type & t2) : first(t1), second(t2) {};
		
		template<class U, class V>
		pair(const pair<U, V> & cpy) : first(cpy.first), second(cpy.second) {};
		
		pair & operator=(pair const & src) {
			first = src.first;
			second = src.second;
			return *this;
		};
		
	};
	
	template < class T1, class T2 >
	pair<T1, T2> makepair(T1 x, T2 y) { return pair<T1, T2>(x, y); };

	template <class T1, class T2 >
	bool	operator==(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{ return lhs.first == rhs.first && lhs.second == rhs.second; };
	
	template <class T1, class T2 >
	bool	operator!=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{ return !(lhs == rhs); };
	
	template <class T1, class T2 >
	bool	operator<(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{ return lhs.first < rhs.first || !(rhs.first < lhs.first) && lhs.second < rhs.second; };
	
	template <class T1, class T2 >
	bool	operator<=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{ return !(rhs < lhs); };
	
	template <class T1, class T2 >
	bool	operator>(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{ return rhs < lhs; };
	
	template <class T1, class T2 >
	bool	operator>=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{ return !(lhs<rhs); };

}

#endif
