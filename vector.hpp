/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:21:10 by smiro             #+#    #+#             */
/*   Updated: 2023/02/20 20:21:13 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define  VECTOR_HPP

#include <memory>
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"

namespace ft
{
	
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		
		public:
		
			typedef T																												value_type;
			typedef Allocator																								allocator_type;
			typedef typename allocator_type::reference											reference;
			typedef typename allocator_type::const_reference								const_reference;
			typedef ft::random_access_iterator<value_type>									iterator;
			typedef ft::random_access_iterator<const value_type>						const_iterator;
			typedef typename allocator_type::size_type											size_type;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::pointer												pointer;
			typedef typename allocator_type::const_pointer									const_pointer;
			typedef ft::reverse_iterator<iterator>													reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>										const_reverse_iterator;

			
			explicit	vector(const allocator_type & alloc = allocator_type())
				:	alloc(alloc), start(nullptr), end(nullptr), end_capacity(nullptr) {};
			
			explicit	vector(size_type n, const value_type val = value_type(), const allocator_type & alloc = allocator_type())
				: alloc(alloc), start(nullptr), end(nullptr), end_capacity(nullptr) {
					start = alloc.allocate(n);
					end_capacity = start + n;
					end = start;
					while (n--)
					{
						alloc.construct(end, val);
						end++;
					}
				}
			
			
		private:
			
			allocator_type	alloc;
			pointer					start;
			pointer					end;
			pointer					end_capacity;
			
	};
	
}

#endif
