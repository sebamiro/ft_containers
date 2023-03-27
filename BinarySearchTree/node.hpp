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
	enum	color {RED, BLACK};

	template < typename T >
	struct	Node
	{

		typedef T		value_type;

		Node(void)
			: value(), parent(nullptr), left(nullptr), right(nullptr), _color(RED) {};

			Node(Node * parent = nullptr, Node * left = nullptr, Node * right = nullptr, ft::color color = RED)
			: value(), parent(parent), left(left), right(right), _color(color) {};

			Node(const value_type & val, Node * parent = nullptr, Node * left = nullptr, Node * right = nullptr, ft::color color = RED)
			: value(val), parent(parent), left(left), right(right), _color(color) {};

		Node(const Node & cpy)
			: value(cpy.value), parent(cpy.parent), left(cpy.left), right(cpy.right), _color(cpy._color) {};

		Node & operator=(const Node & src) {

			if (*this == src)
				return *this;
			this->value = src.value;
			this->parent = src.parent;
			this->left = src.left;
			this->right = src.right;
			this->_color = src._color;
			return *this;
		}

		virtual ~Node() {};

		bool	operator==(const Node & rhs)
			{ return this->value == rhs.value; };

		void	setColor(ft::color color)
		 { this->_color = color; };

		value_type	value;
		Node * parent;
		Node * left;
		Node * right;
		color _color;

	};
}

#endif
