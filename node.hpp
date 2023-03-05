/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:29:02 by smiro             #+#    #+#             */
/*   Updated: 2023/02/28 12:29:04 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

namespace ft
{

	template < typename T >
	struct	Node
	{
		
		typedef T		value_type;
		
		Node(void)
			: value(), parent(nullptr), left(nullptr), right(nullptr), color(true) {};
		
			Node(Node * parent = nullptr, Node * left = nullptr, Node * right = nullptr, bool color = true)
			: value(), parent(parent), left(left), right(right), color(color) {};
			
			Node(const value_type & val, Node * parent = nullptr, Node * left = nullptr, Node * right = nullptr, bool color = true)
			: value(val), parent(parent), left(left), right(right), color(color) {};
			
		Node(const Node & cpy) 
			: value(cpy.value), parent(cpy.parent), left(cpy.left), right(cpy.right), color(cpy.color) {};
		
		Node & operator=(const Node & src) {
			
			if (*this == src)
				return *this;
			this->value = src.value;
			this->parent = src.parent;
			this->left = src.left;
			this->right = src.right;
			this->color = src.color;
			return *this;
		}
		
		virtual ~Node() {};
		
		bool	operator==(const Node & rhs)
			{ return this->value == rhs.value; };
			
		void	setColor(bool	color)
		 { this->color = color; };
		
		value_type	value;
		Node * parent;
		Node * left;
		Node * right;
		bool	color;
		
	};
}

#endif
