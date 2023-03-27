/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:22:55 by smiro             #+#    #+#             */
/*   Updated: 2023/02/28 13:22:56 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_ITERATOR_HPP
#define BST_ITERATOR_HPP

#include "../utility.hpp"

namespace ft
{

template  <typename  T>
class BST_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
{

public:

	typedef typename T::value_type																	value_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

	BST_iterator(void)
	: node(), sentinel() {};

	BST_iterator(T* node, T* sentinel)
	: node(node), sentinel(sentinel) {};

	BST_iterator(const BST_iterator& cpy)
	: node(cpy.node), sentinel(cpy.sentinel) {};

	virtual ~BST_iterator(void) {};

	BST_iterator&
	operator=(const BST_iterator& src) {
		if (*this == src)
			return *this;

		this->node = src.node;
		this->sentinel = src.sentinel;
		return *this;
	}

	bool
	operator==(const BST_iterator& rhs)
	{ return this->node == rhs.node; }

	bool
	operator!=(const BST_iterator& rhs)
	{ return this->node != rhs.node; }

	reference
	operator*(void) const
	{ return this->node->value; }

	pointer
	operator->(void) const
	{ return &this->node->value; }

	BST_iterator&
	operator++(void) {
		if (this->node == this->sentinel->right)
			this->node = sentinel;
		else if (this->node->right != this->sentinel) {
			this->node = this->node->right;

			while (this->node->left != this->sentinel)
				this->node = this->node->left;
		}
		else {
			T*	temp = this->node;
			this->node = this->node->parent;

			while (this->node->left != temp && this->node != this->sentinel) {
				temp = this->node;
				this->node = this->node->parent;
			}
		}
		return *this;
	}

	BST_iterator
	operator++(int) {
		BST_iterator temp(*this);

		operator++();
		return temp;
	}

	BST_iterator&
	operator--(void) {
		if (this->node == this->sentinel)
			this->node = this->sentinel->right;
		else if (this->node->left != this->sentinel) {
			this->node = this->node->left;

			while (this->node->right != this->sentinel)
				this->node = this->node->right;
		}
		else {
			T*	temp = this->node;
			this->node = this->node->parent;

			while (this->node->right != temp && this->node != this->sentinel) {
				temp = this->node;
				this->node = this->node->parent;
			}
		}
		return *this;
	}

	BST_iterator operator--(int) {
		BST_iterator temp(*this);

		operator--();
		return temp;
	}

private:

	T* 		node;
	T* 		sentinel;

};

}//ft namespace

#endif//BST_ITERATOR_HPP
