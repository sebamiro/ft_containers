/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:50:11 by smiro             #+#    #+#             */
/*   Updated: 2023/02/18 17:50:12 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "Vector.hpp"
#include <iterator>

namespace ft
{

template <class T, class Container = ft::vector<T> >
class stack
{

public:

	typedef Container									container_type;
	typedef typename container_type::value_type			value_type;
	typedef typename container_type::reference			reference;
	typedef typename container_type::const_reference	const_reference;
	typedef typename container_type::size_type			size_type;

protected:

	container_type	c;

public:

	explicit stack(const container_type& c = container_type())
	: c(c) {}

	stack&
	operator=(const stack& src) {
		if (this == &src)
			return *this;
		c = src.c;
		return *this;
	}

	virtual	~stack() {};

	bool
	empty(void) const
	{ return c.empty(); }

	size_type
	size(void) const
	{ return c.size(); }

	reference
	top(void)
	{ return c.back(); }

	const_reference
	top(void) const
	{ return c.back(); }

	void
	push(const value_type& x)
	{ c.push_back(x); }

	void
	pop(void)
	{ c.pop_back(); }

	template <typename value_type, typename container_type>
	friend bool
	operator==(const stack<value_type, container_type>& lhs,
				const stack<value_type, container_type>& rhs){
		return lhs.c == rhs.c;
	}

	template <typename value_type, typename container_type>
	friend bool
	operator!=(const stack<value_type, container_type>& lhs,
				const stack<value_type, container_type>& rhs){
		return lhs.c != rhs.c;
	}

	template <typename value_type, typename container_type>
	friend bool
	operator>(const stack<value_type, container_type>& lhs,
				const stack<value_type, container_type>& rhs){
		return lhs.c > rhs.c;
	}

	template <typename value_type, typename container_type>
	friend bool
	operator>=(const stack<value_type, container_type>& lhs,
				const stack<value_type, container_type>& rhs){
		return lhs.c >= rhs.c;
	}

	template <typename value_type, typename container_type>
	friend bool
	operator<(const stack<value_type, container_type>& lhs,
				const stack<value_type, container_type>& rhs){
		return lhs.c < rhs.c;
	}

	template <typename value_type, typename container_type>
	friend bool
	operator<=(const stack<value_type, container_type>& lhs,
				const stack<value_type, container_type>& rhs){
		return lhs.c <= rhs.c;
	}

};

}//ft namespace

#endif //STACK_HPP
