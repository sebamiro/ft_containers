/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:40:53 by smiro             #+#    #+#             */
/*   Updated: 2023/03/01 17:40:54 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

#include "node.hpp"
#include "BST_iterator.hpp"
#include "../utility.hpp"

#define RED true
#define BLACK false

namespace ft
{

	template < class T, class Compare = ft::less<T>,
								class Allocator = std::allocator<ft::Node<T> > >
	class	BST
	{
		public:
		
			typedef BST															self;
			typedef self &													self_reference;
			typedef T																value_type;
			typedef ft::Node<T>														node_type;
			typedef node_type *											node_pointer;
			typedef Allocator												node_alloc;
			typedef ft::BST_iterator<ft::Node<T> >					iterator;
			typedef ft::BST_iterator<ft::Node<T> >					const_iterator;
			typedef size_t													size_type;
			
			
			BST(const node_alloc & alloc = node_alloc()) 
				: _node_alloc(alloc), _size(0) {
					sentinel_node = _node_alloc.allocate(1);
					_node_alloc.construct(sentinel_node, node_type(sentinel_node, sentinel_node, sentinel_node, BLACK));
				}
			
			~BST(void) {
				_node_alloc.destroy(sentinel_node);
				_node_alloc.deallocate(sentinel_node, 1);
			}
			
			ft::pair<iterator, bool> insert_pair(value_type value) {
				
				node_pointer	start = sentinel_node->parent;
				node_pointer	prev = sentinel_node;
				
				bool					side = true;
				
				while (start != sentinel_node)
				{
					if (start->value.first == value.first)
						return (ft::make_pair(iterator(start, sentinel_node), false));
					prev = start;
					if (comp(value.first, start->value.first) == false)
					{
						side = true;
						start = start->right;
					}
					else
					{
						side = false;
						start = start->left;
					}
				}
				
				node_pointer	new_node = _node_alloc.allocate(1);
				_node_alloc.construct(new_node, node_type(value, prev, sentinel_node, sentinel_node));
				
				if (prev == sentinel_node)
					sentinel_node->parent = new_node;
				else if (side == true)
					prev->right = new_node;
				else
					prev->left = new_node;
				
				sentinel_node->left = getLower(sentinel_node->parent);
				sentinel_node->right = getHigher(sentinel_node->parent);
				insertCheck(new_node);
				_size += 1;
				return (ft::make_pair(iterator(new_node, sentinel_node), true));
			}
			
			void	removeByKey(value_type value) {
				
				node_pointer	node = searchByKey(value);
				
				
				if (node->left != sentinel_node && node->right != sentinel_node)
				{
					node_pointer reminder = getHigher(node->left);
					node_type	temp(reminder->value, node->parent, node->left, node->right);
					_node_alloc.destroy(node);
					_node_alloc.construct(node, temp);
					removeFrom(reminder->value, reminder);
				}
				else
					removeFrom(value, sentinel_node->parent);
			}
			
			node_pointer	searchByKey(const value_type value)
				{ return searchFrom(value, sentinel_node->parent); }
			
			void	swap(self_reference x) {
				node_pointer	temp = x.sentinel_node;
				Compare				temp_comp = x.comp;
				size_type			temp_size = x._size;
				x.sentinel_node = this->sentinel_node;
				x.comp = this->comp;
				x._size	=	this->_size;
				this->sentinel_node = temp;
				this->comp = temp_comp;
				this->_size = temp_size;
			}
			
			size_type	size(void) const
				{ return this->_size; }
			
			size_type	max_size(void) const 
				{ return _node_alloc.max_size(); }
			
			node_pointer	sentinel_node;
			
		private:
			
			void	removeFrom(value_type value, node_pointer root) {
				
				node_pointer	node = searchFrom(value, root);
				node_pointer	next_node;
				
				if (node->left != sentinel_node)
					next_node = node->left;
				else
					next_node = node->right;

				if (node->parent == sentinel_node)
					sentinel_node->parent = next_node;
				else if (node->parent->left == node)
					node->parent->left = next_node;
				else
					node->parent->right = next_node;
				
				if (next_node != sentinel_node)
					next_node->parent = node->parent;
				sentinel_node->left = getLower(sentinel_node->parent);
				sentinel_node->right = getHigher(sentinel_node->parent);
				_size -= 1;
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}
		
			node_pointer	searchFrom(const value_type value, node_pointer root) {
				while (root != sentinel_node)
				{
					if (root->value.first == value.first)
						return root;
					if (comp(value.first, root->value.first))
						root = root->left;
					else
						root = root->right;
				}
				return root;
			}
		
			node_pointer	getLower(node_pointer node) {
				while (node != sentinel_node && node->left != sentinel_node)
					node = node->left;
				return node;
			}
			
			node_pointer	getHigher(node_pointer node) {
				while (node != sentinel_node && node->right != sentinel_node)
					node = node->right;
				return node;
			}
			
			node_pointer	grandParent(node_pointer node) {
				
				if (node == sentinel_node || node->parent == sentinel_node)
					return sentinel_node;
				return node->parent->parent;
			}
			
			node_pointer	sibiling(node_pointer node) {
				if (node->parent == sentinel_node)
					return sentinel_node;
				if (node->parent->left == node)
					return node->parent->right;
				return node->parent->left;
			}
			
			node_pointer	uncle(node_pointer node) {
				if (node->parent == sentinel_node)
					return sentinel_node;
				return sibiling(node->parent);
			}
			
			void	replaceNode(node_pointer old_node, node_pointer new_node) {
				if (old_node->parent == sentinel_node)
					sentinel_node->parent = new_node;
				else
				{
					if (old_node->parent->left == old_node)
						old_node->parent->left = new_node;
					else
						old_node->parent->right = new_node;
				}
				if (new_node != sentinel_node)
					new_node->parent = old_node->parent;
			}
			
			void	rotateLeft(node_pointer	node) {
				
				node_pointer	temp = node->right;
				replaceNode(node, temp);
				node->right = temp->left;
				if (node->left != sentinel_node)
					temp->left->parent = node;
				temp->left = node;
				node->parent = temp;
			};
			
			void	rotateRight(node_pointer	node) {
				
				node_pointer	temp = node->left;
				replaceNode(node, temp);
				node->left = temp->right;
				if (node->right != sentinel_node)
					temp->right->parent = node;
				temp->right = node;
				node->parent = temp;
			};
			
			void	insertCheck(node_pointer node) {
				
				if (node->parent == sentinel_node)
					node->setColor(BLACK);
				else if (node->parent->color == BLACK)
					return ;
				else if (uncle(node)->color == RED)
				{
					node->parent->setColor(BLACK);
					uncle(node)->setColor(BLACK);
					grandParent(node)->setColor(RED);
					insertCheck(grandParent(node));
				}
				else
					insertRotations(node);
			};
			
			void	insertRotations(node_pointer node) {
				
				if (node == node->parent->right
					&& node->parent == grandParent(node)->left)
				{
					rotateLeft(node->parent);
					node = node->left;
				}
				else if (node == node->parent->left
					&& node->parent == grandParent(node)->right)
				{
					rotateRight(node->parent);
					node = node->right;
				}
				
				node->parent->setColor(BLACK);
				grandParent(node)->setColor(RED);
				
				if (node == node->parent->left && node->parent == grandParent(node)->left)
					rotateRight(grandParent(node));
				else if (node == node->parent->right && node->parent == grandParent(node)->right)
					rotateLeft(grandParent(node));
			}
			
			node_alloc		_node_alloc;
			Compare				comp;
			size_type			_size;
	};
}

#endif