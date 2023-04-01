/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:52:18 by smiro             #+#    #+#             */
/*   Updated: 2023/04/01 14:52:19 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define  SET_HPP

#include "utility.hpp"
#include "RedBlackTree/RBT.hpp"

namespace ft
{

template <class Key, class Compare = ft::less<Key>,
			class Allocator = std::allocator<Key> >
class set
{

public:

	typedef Key												key_type;
	typedef key_type										value_type;
	typedef Compare											key_compare;
	typedef key_compare										value_compare;
	typedef Allocator										allocator_type;
	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference		const_refernece;
	typedef typename allocator_type::size_type				size_type;
	typedef typename allocator_type::difference_type		difference_type;
	typedef typename allocator_type::pointer				pointer;
	typedef typename allocator_type::const_pointer			const_pointer;

	typedef typename ft::RBT<value_type>::iterator			iterator;
	typedef typename ft::RBT<value_type>::const_iterator	const_iterator;
	typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	explicit set(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
	: alloc(alloc), comp(comp), rbt() {}

	template<class InputIterator>
	set(InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral_type<InputIterator>::value, InputIterator>::type* = 0)
	: alloc(alloc), comp(comp), rbt()
	{ this->insert(first, last); }

	set(const set& cpy)
	: alloc(cpy.alloc), comp(cpy.comp), rbt()
	{ this->insert(cpy.begin(), cpy.end()); }

	~set(void)
	{ this->clear(); }

	set&
	operator=(const set& src) {
		if (this ==&src)
			return (*this);

		this->clear();
		this->insert(src.begin(), src.end());
		return *this;
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
	erase(iterator position)
	{	this->erase((*position)); }

	size_type
	erase(const value_type& val) {
		if (this->find(val) == this->end())
			return 0;
		rbt.removeByKey(val);
		return 1;
	}

	void
	erase(iterator first, iterator last) {
		for (; first != last;)
			this->erase(first++);
	}

	void
	clear(void)
	{ this->erase(this->begin(), this->end()); }

	void
	swap(set& m) {
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
	find(const value_type& val)
	{ return iterator(rbt.searchByKey(val), rbt.base()); }

	size_type
	count(const value_type& val) const {
		iterator	first = this->begin();
		iterator	last = this->end();

		for (; first != last; first++)
			if (comp((*first), val) == false && comp(val, (*first)) == false)
				return 1;
		return 0;
	}

	iterator
	lower_bound(const value_type& val) const {
		iterator	first = this->begin();
		iterator	last = this->end();

		for (; first != last; first++)
			if (comp((*first), val) == false)
				return first;
		return first;
	}

	iterator
	upper_bound(const value_type& val) const {
		iterator	first = this->begin();
		iterator	last = this->end();

		for (; first != last; first++)
			if (comp(val, (*first)) == true)
				return first;
		return first;
	}

	ft::pair<iterator, iterator>
	equal_range(const value_type& val) const
	{ return ft::make_pair(this->lower_bound(val), this->upper_bound(val)); }

private:

	allocator_type					alloc;
	Compare							comp;
	RBT<value_type, key_compare>	rbt;

};

template < class Key, class Compare, class Alloc >
void
swap(set<Key, Compare, Alloc>& x, set<Key, Compare, Alloc>& y)
{ x.swap(y); }

}

template <class Key, class Compare, class Alloc>
bool
operator==(const ft::set<Key, Compare, Alloc>& lhs,
			const ft::set<Key, Compare, Alloc>& rhs) {
	if ( lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class Key, class Compare, class Alloc>
bool
operator!=(const ft::set<Key, Compare, Alloc>& lhs,
			const ft::set<Key, Compare, Alloc>& rhs)
{ return !(lhs == rhs); }

template <class Key, class Compare, class Alloc>
bool
operator<(const	ft::set<Key, Compare, Alloc>& lhs,
			const ft::set<Key, Compare, Alloc>& rhs)
{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

template <class Key, class Compare, class Alloc>
bool
operator>(const	ft::set<Key, Compare, Alloc>& lhs,
			const ft::set<Key, Compare, Alloc>& rhs)
{ return rhs < lhs; }


template <class Key, class Compare, class Alloc>
bool
operator<=(const ft::set<Key, Compare, Alloc>& lhs,
			const ft::set<Key, Compare, Alloc>& rhs)
{ return !(rhs < lhs); }

template <class Key, class Compare, class Alloc>
bool
operator>=(const ft::set<Key, Compare, Alloc>& lhs,
			const ft::set<Key, Compare, Alloc>& rhs)
{ return !(lhs < rhs); };

#endif //SET_HPP
