/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:00:13 by smiro             #+#    #+#             */
/*   Updated: 2023/02/19 19:00:14 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef>

namespace ft
{
	
	struct	random_access_iterator_tag { };
	struct	bidirectional_iterator_tag { };
	
	
	template < class Iterator >
	struct iterator_traits
	{
		typedef typename  Iterator::difference_type		difference_type;
		typedef typename  Iterator::value_type				value_type;
		typedef typename  Iterator::pointer						pointer;
		typedef typename  Iterator::reference					reference;
		typedef typename  Iterator::iterator_category	iterator_category;
	};

	template < class T >
	struct iterator_traits<T*>
	{
		typedef	ptrdiff_t												difference_type;
		typedef T																value_type;
		typedef T*															pointer;
		typedef T&															reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	template < class Category, class T, class Distance = ptrdiff_t,
							class Pointer = T*, class Reference = T& >
	struct	iterator
	{
		typedef T					value_type;
		typedef Distance	difference_type;
		typedef	Pointer		pointer;
		typedef Reference reference;
		typedef Category	iterator_category;
	};
	
}

#endif
