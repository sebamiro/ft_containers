/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:53:57 by smiro             #+#    #+#             */
/*   Updated: 2023/02/20 11:53:59 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	
	template < class Iterator >
	class reverse_iterator : public iterator< typename iterator_traits<Iterator>::iterator_category,
                     											 	typename iterator_traits<Iterator>::value_type,
                               							typename iterator_traits<Iterator>::difference_type,
                                      			typename iterator_traits<Iterator>::pointer,
                                         		typename iterator_traits<Iterator>::reference	>
  {
  	
  	protected:
   			
   			Iterator	current;
      
    public:
    
    		typedef Iterator 																						iterator_type;
      	typedef typename iterator_traits<Iterator>::difference_type	difference_type;
      	typedef typename iterator_traits<Iterator>::reference				reference;
      	typedef typename iterator_traits<Iterator>::pointer					pointer;
  
       
    		reverse_iterator(void) : current() {};
      	explicit	reverse_iterator(iterator_type x) : current(x) {};
       	template <class U>
        reverse_iterator(const reverse_iterator<U> & u) : current(u.base()) {};
        ~reverse_iterator() {};
        
        iterator_type	base(void) const { return current; };
        
        reference	operator*(void) const {
        	iterator_type	temp = current;	
        	return *(--temp);
        };
        
        pointer	operator->(void) const	{ return &(this->operator*()); };
        
        reverse_iterator & operator++(void) {
        	current--;
         	return  *this;
        };
        
        reverse_iterator & operator--(void) {
        	current++;
         	return  *this;
        };
        
        reverse_iterator operator++(int) {
        	reverse_iterator cpy(*this);
        	current--;
         	return  cpy;
        };
        
        reverse_iterator operator--(int) {
        	reverse_iterator cpy(*this);
        	current++;
         	return  cpy;
        };
        
        reverse_iterator operator+(difference_type n) const { return current - n; };
        
        reverse_iterator operator-(difference_type n) const { return current + n; };
        
        reverse_iterator & operator+=(difference_type n) {
        	current -= n;
         	return  *this;
        };
        
        reverse_iterator & operator-=(difference_type n) {
        	current += n;
         	return  *this;
        };
        
        reference	operator[](difference_type n) const { return current.base()[-n - 1];};
        
  };
  
  template < class T>
  typename reverse_iterator<T>::difference_type
  operator-(const reverse_iterator<T> & lhs,
  					const reverse_iterator<T> & rhs)
  { return lhs.base() - rhs.base(); };
	
  template < class T_L, class T_R>
  typename reverse_iterator<T_L>::difference_type
  operator-(const reverse_iterator<T_L> & lhs,
  					const reverse_iterator<T_R> & rhs)
  { return lhs.base() - rhs.base(); };
  
  
  template < class T >
  typename ft::reverse_iterator<T>
  operator+(typename ft::reverse_iterator<T>::difference_type n,
  					typename ft::reverse_iterator<T> & rhs)
  {	return rhs + n; };
  
  template < class T>
  typename reverse_iterator<T>::difference_type
  operator+(const reverse_iterator<T> & lhs,
  					const reverse_iterator<T> & rhs)
  { return lhs.base() - rhs.base(); };
	
  template < class T_L, class T_R>
  typename reverse_iterator<T_L>::difference_type
  operator+(const reverse_iterator<T_L> & lhs,
  					const reverse_iterator<T_R> & rhs)
  { return lhs.base() - rhs.base(); };
  
  template <typename T>
  bool
  operator==(const ft::reverse_iterator<T> & lhs,
						const ft::reverse_iterator<T> & rhs)
  {	return lhs.base() == rhs.base(); };
  
  template <typename T_L, typename T_R>
  bool
  operator==(const ft::reverse_iterator<T_L> & lhs,
						const ft::reverse_iterator<T_R> & rhs)
  {	return lhs.base() == rhs.base(); };
  
  template <typename T>
  bool
  operator!=(const ft::reverse_iterator<T> & lhs,
						const ft::reverse_iterator<T> & rhs)
  {	return lhs.base() != rhs.base();	};
  
  template <typename T_L, typename T_R>
  bool
  operator!=(const ft::reverse_iterator<T_L> & lhs,
						const ft::reverse_iterator<T_R> & rhs)
  {	return lhs.base() != rhs.base(); };
  
  template <typename T>
  bool
  operator<(const ft::reverse_iterator<T> & lhs,
						const ft::reverse_iterator<T> & rhs)
  {	return lhs.base() < rhs.base();	};
  
  template <typename T_L, typename T_R>
  bool
  operator<(const ft::reverse_iterator<T_L> & lhs,
						const ft::reverse_iterator<T_R> & rhs)
  {	return lhs.base() < rhs.base(); };
  
  template <typename T>
  bool
  operator>(const ft::reverse_iterator<T> & lhs,
						const ft::reverse_iterator<T> & rhs)
  {	return lhs.base() > rhs.base();	};
  
  template <typename T_L, typename T_R>
  bool
  operator>(const ft::reverse_iterator<T_L> & lhs,
						const ft::reverse_iterator<T_R> & rhs)
  {	return lhs.base() > rhs.base(); };
  
  template <typename T>
  bool
  operator<=(const ft::reverse_iterator<T> & lhs,
						const ft::reverse_iterator<T> & rhs)
  {	return lhs.base() <= rhs.base();	};
  
  template <typename T_L, typename T_R>
  bool
  operator<=(const ft::reverse_iterator<T_L> & lhs,
						const ft::reverse_iterator<T_R> & rhs)
  {	return lhs.base() <= rhs.base(); };
  
  template <typename T>
  bool
  operator>=(const ft::reverse_iterator<T> & lhs,
						const ft::reverse_iterator<T> & rhs)
  {	return lhs.base() >= rhs.base();	};
  
  template <typename T_L, typename T_R>
  bool
  operator>=(const ft::reverse_iterator<T_L> & lhs,
						const ft::reverse_iterator<T_R> & rhs)
  {	return lhs.base() >= rhs.base(); };
}

#endif
