/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:04:23 by smiro             #+#    #+#             */
/*   Updated: 2023/02/20 10:04:25 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{

template < class T >
class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
{
	
	public:
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type				value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
		
		typedef T*	pointer;
		typedef T&	reference;
	
	private:
		
		pointer	current;
	
	public:
	
		random_access_iterator(void)
			: current(nullptr)	{};
			random_access_iterator(pointer current)
			: current(current)	{};
		random_access_iterator(const random_access_iterator & cpy)
			: current(cpy.current)	{};
		random_access_iterator & operator=(const random_access_iterator & src){
			if (this == &src)
				return *this;
			this->current = src.current;
			return *this;
		};
		virtual	~random_access_iterator(void) {};
		
		pointer	base(void) const { return this->current; };
		
		reference	operator*(void) const { return *current; };
		
		pointer		operator->(void) { return &(this->operator*()); };
		
		random_access_iterator &	operator++(void) {
			current++;
			return *this;
		};
		
		random_access_iterator &	operator--(void) {
			current--;
			return *this;
		};
		
		random_access_iterator	operator++(int) {
			random_access_iterator	cpy(*this);
			current++;
			return cpy;
		};
		
		random_access_iterator	operator--(int) {
			random_access_iterator	cpy(*this);
			current--;
			return cpy;
		};
		
		random_access_iterator		operator+(difference_type n) const { return current + n; };
		
		random_access_iterator		operator-(difference_type n) const { return current - n; };
		
		random_access_iterator	&	operator+=(difference_type n) { 
			current += n;
			return *this;
		};
		
		random_access_iterator	&	operator-=(difference_type n) { 
			current -= n;
			return *this;
		};
		
		reference	operator[](difference_type n) { return *(operator+(n)); };
		
		operator random_access_iterator<const T> (void) const
		{ return random_access_iterator<const T>(this->current); };

};

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator==(const ft::random_access_iterator<T> lhs,
						const ft::random_access_iterator<T> rhs)
{	return lhs.base() == rhs.base(); };

template <typename T_L, typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator==(const ft::random_access_iterator<T_L> lhs,
						const ft::random_access_iterator<T_R> rhs)
{	return lhs.base() == rhs.base(); };

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator!=(const ft::random_access_iterator<T> lhs,
						const ft::random_access_iterator<T> rhs)
{	return lhs.base() != rhs.base();	};

template <typename T_L, typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator!=(const ft::random_access_iterator<T_L> lhs,
						const ft::random_access_iterator<T_R> rhs)
{	return lhs.base() != rhs.base(); };

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator<(const ft::random_access_iterator<T> lhs,
						const ft::random_access_iterator<T> rhs)
{	return lhs.base() < rhs.base();	};

template <typename T_L, typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator<(const ft::random_access_iterator<T_L> lhs,
						const ft::random_access_iterator<T_R> rhs)
{	return lhs.base() < rhs.base(); };

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator>(const ft::random_access_iterator<T> lhs,
						const ft::random_access_iterator<T> rhs)
{	return lhs.base() > rhs.base();	};

template <typename T_L, typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator>(const ft::random_access_iterator<T_L> lhs,
						const ft::random_access_iterator<T_R> rhs)
{	return lhs.base() > rhs.base(); };

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator<=(const ft::random_access_iterator<T> lhs,
						const ft::random_access_iterator<T> rhs)
{	return lhs.base() <= rhs.base();	};

template <typename T_L, typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator<=(const ft::random_access_iterator<T_L> lhs,
						const ft::random_access_iterator<T_R> rhs)
{	return lhs.base() <= rhs.base(); };

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator>=(const ft::random_access_iterator<T> lhs,
						const ft::random_access_iterator<T> rhs)
{	return lhs.base() >= rhs.base();	};

template <typename T_L, typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator>=(const ft::random_access_iterator<T_L> lhs,
						const ft::random_access_iterator<T_R> rhs)
{	return lhs.base() >= rhs.base(); };

template <typename T>
typename ft::random_access_iterator<T>
operator+(typename ft::random_access_iterator<T>::difference_type n,
					typename ft::random_access_iterator<T>& rhs)
{	return &(*rhs) + n; };

template <typename T>
typename ft::random_access_iterator<T>::difference_type
operator-(const ft::random_access_iterator<T> lhs,
						const ft::random_access_iterator<T> rhs)
{	return lhs.base() - rhs.base();	};

template <typename T_L, typename T_R>
typename ft::random_access_iterator<T_L>::difference_type
operator-(const ft::random_access_iterator<T_L> lhs,
						const ft::random_access_iterator<T_R> rhs)
{	return lhs.base() - rhs.base(); };

}

#endif