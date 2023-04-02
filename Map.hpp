/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:43:16 by smiro             #+#    #+#             */
/*   Updated: 2023/03/02 14:43:21 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "utility.hpp"
#include "RedBlackTree/RBT.hpp"

namespace ft
{

template <class Key, class T, class Compare = ft::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, T> > >
class map
{

public:

	typedef Key												key_type;
	typedef T												mapped_type;
	typedef ft::pair<const key_type, mapped_type>			value_type;
	typedef Compare											key_compare;
	typedef Allocator										allocator_type;
	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference		const_reference;
	typedef typename allocator_type::pointer				pointer;
	typedef typename allocator_type::const_pointer			const_pointer;
	typedef typename allocator_type::size_type				size_type;
	typedef typename allocator_type::difference_type		difference_type;

	typedef typename ft::RBT<value_type>::iterator			iterator;
	typedef typename ft::RBT<value_type>::const_iterator	const_iterator;
	typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	class value_compare
	: public ft::binary_function<value_type, value_type, bool>
	{
		friend class map;

	protected:

		key_compare comp;

		value_compare(key_compare c) : comp(c) {};

	public:

		bool	operator()(const value_type& x, const value_type& y) const
		{ return comp(x.first, y.first); };
	};

	explicit map(const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
	: alloc(alloc), comp(comp), rbt(comp) {}

	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const allocator_type& alloc = allocator_type(),
		const key_compare& comp = key_compare(),
		typename ft::enable_if<!ft::is_integral_type<InputIterator>::value, InputIterator>::type* = 0)
	: alloc(alloc), comp(comp), rbt(comp)
	{	this->insert(first, last); }

	map(const map& cpy)
	: alloc(cpy.alloc), comp(cpy.comp), rbt(comp)
	{ this->insert(cpy.begin(), cpy.end()); }

	~map(void)
	{ this->clear(); }

	map&
	operator=(const map& src) {
		if (this ==&src)
			return (*this);

		this->clear();
		this->insert(src.begin(), src.end());
		return *this;
	}

	mapped_type&
	at(const key_type& n) {
		if (n >= this->size())
			throw (std::length_error("vector::at: Out of bounds"));
		return (*this)[n];
	}

	const mapped_type&
	at(const key_type& n) const {
		if (n >= this->size())
			throw (std::length_error("vector::at: Out of bounds"));
		return (*this)[n];
	}

	iterator
	begin(void)
	{ return iterator(rbt.left(), rbt.base()); }

	const_iterator
	begin(void) const
	{ return iterator(rbt.left(), rbt.base()); }

	iterator
	end(void)
	{ return iterator(rbt.base(), rbt.base()); }

	const_iterator
	end(void) const
	{ return iterator(rbt.base(), rbt.base()); }

	reverse_iterator
	rbegin(void)
	{ return reverse_iterator(this->end()); }

	const_reverse_iterator
	rbegin(void) const
	{ return reverse_iterator(this->end()); }

	reverse_iterator
	rend(void)
	{ return reverse_iterator(this->begin()); }

	const_reverse_iterator
	rend(void) const
	{ return const_reverse_iterator(this->begin()); }

	bool
	empty(void) const
	{ return rbt.root() == rbt.base(); }

	size_type
	size(void) const
	{ return rbt.size(); }

	size_type
	max_size(void) const
	{ return rbt.max_size(); }

	mapped_type&
	operator[](const key_type& key)
	{ return (*((this->insert(make_pair(key, mapped_type()))).first)).second; }

	ft::pair<iterator, bool>
	insert(const value_type& val)
	{ return rbt.insert_pair(val); }

	iterator
	insert(iterator position, const value_type& val) {
		(void)position;
		return rbt.insert_pair(val).first;
	}

	template < class InputIterator>
	void
	insert(InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral_type<InputIterator>::value,
			InputIterator>::type* = 0) {
		difference_type	len = ft::distance(first, last);
		while (len--)
			this->insert(*(first++));
	}

	void
	clear(void)
	{ this->rbt.clear(); }

	void
	erase(iterator position)
	{	this->erase((*position).first); }

	size_type
	erase(const key_type& k) {
		if (this->find(k) == this->end())
			return 0;
		rbt.removeByKey(ft::make_pair(k, mapped_type()));
		return 1;
	}

	void
	erase(iterator first, iterator last) {
		for (; first != last;)
			this->erase(first++);
	}

	void
	swap(map& m) {
		if (this == &m)
			return ;

		rbt.swap(m.rbt);
	}

	allocator_type
	get_allocator(void) const
	{ return this->alloc; }

	key_compare
	key_comp(void) const
	{ return this->comp; }

	value_compare
	value_comp(void) const
	{ return value_compare(key_compare()); }

	iterator
	find(const key_type& key)
	{ return iterator(rbt.searchByKey(ft::make_pair(key, mapped_type())), rbt.base()); }

	const_iterator
	find(const key_type& key) const
	{ return const_iterator(rbt.searchByKey(ft::make_pair(key, mapped_type())), rbt.base()); }

	size_type
	count(const key_type& key) const {
		iterator	first = this->begin();
		iterator	last = this->end();

		for (; first != last; first++)
			if (comp((*first).first, key) == false && comp(key, (*first).first) == false)
				return 1;
		return 0;
	}

	iterator
	lower_bound(const key_type& key) {
		iterator	first = this->begin();
		iterator	last = this->end();

		for (; first != last; first++)
			if (comp((*first).first, key) == false)
				return first;
		return first;
	}

	const_iterator
	lower_bound(const key_type& key) const
	{ return const_iterator(this->lower_bound(key)); }

	iterator
	upper_bound(const key_type& key) {
		iterator	first = this->begin();
		iterator	last = this->end();

		for (; first != last; first++)
			if (comp(key, (*first).first) == true)
				return first;
		return first;
	}

	const_iterator
	upper_bound(const key_type& key) const
	{ return const_iterator(this->upper_bound(key)); }

	ft::pair<iterator, iterator>
	equal_range(const key_type& key)
	{ return ft::make_pair(this->lower_bound(key), this->upper_bound(key)); }

	ft::pair<const_iterator, const_iterator>
	equal_range(const key_type& key) const
	{ return ft::make_pair(this->lower_bound(key), this->upper_bound(key)); }

private:

	allocator_type					alloc;
	Compare							comp;
	RBT<value_type, value_compare>	rbt;

};

template < class Key, class T, class Compare, class Alloc >
void
swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y)
{ x.swap(y); }

}//ft namespace

template <class Key, class T, class Compare, class Alloc>
bool
operator==(const ft::map<Key, T, Compare, Alloc>& lhs,
			const ft::map<Key, T, Compare, Alloc>& rhs) {
	if ( lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class Key, class T, class Compare, class Alloc>
bool
operator!=(const ft::map<Key, T, Compare, Alloc>& lhs,
			const ft::map<Key, T, Compare, Alloc>& rhs)
{ return !(lhs == rhs); }

template <class Key, class T, class Compare, class Alloc>
bool
operator<(const	ft::map<Key, T, Compare, Alloc>& lhs,
			const ft::map<Key, T, Compare, Alloc>& rhs)
{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

template <class Key, class T, class Compare, class Alloc>
bool
operator>(const	ft::map<Key, T, Compare, Alloc>& lhs,
			const ft::map<Key, T, Compare, Alloc>& rhs)
{ return rhs < lhs; }


template <class Key, class T, class Compare, class Alloc>
bool
operator<=(const ft::map<Key, T, Compare, Alloc>& lhs,
			const ft::map<Key, T, Compare, Alloc>& rhs)
{ return !(rhs < lhs); }

template <class Key, class T, class Compare, class Alloc>
bool
operator>=(const ft::map<Key, T, Compare, Alloc>& lhs,
			const ft::map<Key, T, Compare, Alloc>& rhs)
{ return !(lhs < rhs); };

#endif //MAP_HPP
