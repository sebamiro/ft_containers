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

#include "utility.hpp"

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
				:	alloc(alloc), start(nullptr), _end(nullptr), end_capacity(nullptr) {};
			
			explicit	vector(size_type n, const value_type val = value_type(), const allocator_type & alloc = allocator_type())
				: alloc(alloc), start(nullptr), _end(nullptr), end_capacity(nullptr) {
					start = this->alloc.allocate(n);
					end_capacity = start + n;
					_end = start;
					while (n--)
						this->alloc.construct(_end++, val);
				}
			
			template < class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral_type<InputIterator>::value, InputIterator>::type* = 0)
				: alloc(alloc) {
					
					difference_type n	= last - first;
					start = this->alloc.allocate(n);
					end_capacity = start + n;
					_end = start;
					while (n--)
						this->alloc.construct(_end++, *first++);
				}
				
			vector(const vector & cpy)
				: alloc(cpy.alloc), start(nullptr), _end(nullptr), end_capacity(nullptr) {
					this->insert(this->begin(), cpy.begin(), cpy.end());
				}
				
			~vector(void) {
				this->clear();
				alloc.deallocate(start, this->capacity());
			}
			
			vector & operator=(const vector & src) {
				
				if (*this == src)
					return (*this);
				this->clear();
				this->insert(this->begin(), src.begin(), src.end());
				this->end_capacity = this->start + src.capacity();
				return *this;
			};
			
			template < class InputIterator>
			void assign (InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral_type<InputIterator>::value, InputIterator>::type* = 0)
			{
				this->clear();
				size_type len = last - first;
				if (size_type(end_capacity - start) >= len)
				{
					for (; &(*first) != &(*last); first++, _end++)
						alloc.construct(_end, *first);
				}
				else
				{
					pointer	new_start = pointer();
					pointer	new_end = pointer();
					pointer	new_end_capacity = pointer();
					
					new_start = alloc.allocate(len);
					new_end = new_start;
					new_end_capacity = new_start + len;
					
					for (; &(*first) != &(*last); first++)
						alloc.construct(new_end++, *first);
						
					alloc.deallocate(start, this->capacity());
					
					start = new_start;
					_end = new_end;
					end_capacity = new_end_capacity;
				}
			}
			
			void assign(size_type n, const value_type & val) {
				
				this->clear();
				if (n == 0)
					return ;
				if (size_type(end_capacity - start) >= n)
				{
					while (n--)
						alloc.construct(_end, val);
				}
				else
				{
					alloc.deallocate(start, this->capacity());
					start = alloc.allocate(n);
					end_capacity = start + n;
					_end = start;
					while (n--)
						alloc.construct(_end++, val);
				}
			};
			
			allocator_type	get_allocator(void) const
					{ return this->alloc; };
			
			iterator	begin(void)
					{ return iterator(start); };
			
			const_iterator	begin(void) const
					{ return start; };
			
			iterator	end(void) { 
				if (this->empty())
					return this->begin();
				return _end;
			};
			
			const_iterator	end(void) const {
				
				if (this->empty())
					return this->begin();
				return _end;
			};
			
			reverse_iterator 	rbegin(void) 
					{ return reverse_iterator(this->end()); };
			
			const_reverse_iterator 	rbegin(void) const
					{ return const_reverse_iterator(this->end()); };
					
			reverse_iterator 	rend(void) 
					{ return reverse_iterator(this->begin()); };
					
			const_reverse_iterator 	rend(void) const
					{ return const_reverse_iterator(this->begin()); };
					
			size_type size(void) const
					{ return static_cast<size_type>(this->_end - this->start); };
					
			size_type capacity(void) const
					{ return static_cast<size_type>(this->end_capacity - this->start); };
					
			bool	empty(void) const
					{ return this->start == this->_end; };
				
			size_type	max_size(void) const
					{ return allocator_type().max_size(); };
			
			void	reserve(size_type	n) {
				
				if (n > this->max_size())
					throw (std::length_error("vector::reserve"));
				else if (n > this->capacity())
				{
					pointer					prev_start = start;
					pointer					prev_end = _end;
					size_type				prev_capacity = this->capacity();
					size_type				prev_size = this->size();
					
					start = alloc.allocate(n);
					end_capacity = start + n;
					_end = start;
					while (prev_start != prev_end)
					{
						alloc.construct(_end, *prev_start);
						_end++;
						prev_start++;
					}
					alloc.deallocate(prev_start - prev_size, prev_capacity);
				}
			}		
					
			reference	operator[](size_type n)
					{ return *(start + n); };
			
			const_reference	operator[](size_type n) const
					{ return *(start + n); };
			
			reference	at(size_type n) {
				if (n >= this->size())
					throw (std::length_error("vector::at: " + std::to_string(n) + " Out of bounds"));
				return (*this)[n];
			};
			
			const_reference	at(size_type n) const {
				if (n >= this->size())
					throw (std::length_error("vector::at: " + std::to_string(n) + " Out of bounds"));
				return (*this)[n];
			};
			
			reference	front(void)
				{ return *start; };
			
			const_reference	front(void) const
				{ return *start; };
				
			reference	back(void)
				{ return *(_end - 1); };
				
			const_reference	back(void) const
				{ return *(_end - 1); };
				
			void	push_back(const value_type & val) {
				if (_end == end_capacity)
					this->reserve(this->size() > 0 ? (size_type)(this->capacity() * 2) : 1);
				alloc.construct(_end, val);
				_end++;
			}
			
			void	pop_back(void) {
				alloc.destroy(&this->back());
				_end--;
			}
			
			void	insert(iterator position, size_type n, const value_type & val) {
				
				size_type	len = &(*position) - start;
				
				if (size_type(end_capacity - _end) >= n)
				{
					for (size_type i = 0; i < this->size() - len; i++)
						alloc.construct(_end - i + (n - 1), *(_end - i - 1));
					_end += n;
					while (n)
					{
						alloc.construct(&(*position) + n - 1, val);
						n--;
					}
					return ;
				}

				pointer	new_start = pointer();
				pointer	new_end = pointer();
				pointer	new_end_capacity = pointer();
				
				size_type new_capacity = this->size() > 0 ? (size_type)(this->capacity() * 2) : 1;
				new_capacity = new_capacity < this->size() + n ? this->size() + n : new_capacity;
				
				new_start = alloc.allocate(new_capacity);
				new_end_capacity = new_start + new_capacity;
				new_end = new_start + this->size() + n;
				
				for (size_type i = 0; i < len; i++)
					alloc.construct(new_start + i, *(start + i));
				for (size_type j = 0; j < n; j++)
					alloc.construct(new_start + j + len, val);
				for (size_type k = 0; k < this->size() - len; k++)
					alloc.construct(new_end - k - 1, *(_end - k - 1));
					
				for (size_type l = 0; l < this->size(); l++)
					alloc.destroy(start + l);
				alloc.deallocate(start, this->capacity());
				
				this->start = new_start;
				this->_end = new_end;
				this->end_capacity = new_end_capacity;
			};
			
			template < class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral_type<InputIterator>::value, InputIterator>::type* = 0) {
						
	
						
						size_type	len = last - first;
						size_type pos_index = &(*position) - start;
						
						if (!validate_iterator_values(first, last, len))
									throw std::exception();
									
						if (size_type(end_capacity - _end) >= len)
						{
							for (size_type i = 0; i < this->size() - pos_index; i++)
								alloc.construct(_end - i + (len - 1), *(_end - i - 1));
							_end += len;
							for (; &(*first) != &(*last); first++, position++)
								alloc.construct(&(*position), *first);
							return ;
						}
						
						pointer	new_start = pointer();
						pointer	new_end = pointer();
						pointer	new_end_capacity = pointer();
						
						size_type new_capacity = this->size() > 0 ? (size_type)(this->capacity() * 2) : 1;
						new_capacity = new_capacity < this->size() + len ? this->size() + len : new_capacity;
						new_start = alloc.allocate(new_capacity);
						new_end_capacity = new_start + new_capacity;
						new_end = new_start + this->size() + len;
					
						for (size_type i = 0; i < pos_index; i++)
							alloc.construct(new_start + i, *(this->start + i));
						
						for (size_type j = 0; &(*first) != &(*last); j++, first++)
							alloc.construct(new_start + pos_index + j, *first);				
						for (size_type k = 0; k < this->size() - pos_index; k++)
							alloc.construct(new_end - k - 1, *(_end - k - 1));
						
						for (size_type l = 0; l < this->size(); l++)
							alloc.destroy(this->start + l);
						alloc.deallocate(this->start, this->capacity());
						
						this->start = new_start;
						this->_end = new_end;
						this->end_capacity = new_end_capacity;
					};
					
				iterator	insert(iterator position, const value_type & val) {
					
					size_type	len = &(*position) - start;
					this->insert(position, 1, val);
					return iterator(start + len);
				};
			
			iterator	erase(iterator first, iterator last) {
				
				pointer	cp_first = &(*first);
				
				for (; &(*first) != &(*last); first++)
					alloc.destroy(&(*first));
				for (size_type i = 0; i < _end - &(*last); i++)
				{
					alloc.construct(cp_first + i, *(&(*last) + i));
					alloc.destroy(&(*last) + i);
				}
				_end -= (&(*last)) - cp_first;
				return (iterator(cp_first));
			};
			
			iterator	erase(iterator position){
				
				pointer	cp_pos = &(*position) + 1;
				alloc.destroy(&(*position));
				for (; cp_pos != _end; cp_pos++)
				{
					alloc.construct(cp_pos - 1, *cp_pos);
					alloc.destroy(cp_pos);
				}
				_end -= 1;
				return (position);
		 	};
			
			void	clear(void){
				
				size_type	size_reminder = this->size();
				for (size_type i = 0; i < size_reminder; i++)
				{
					_end--;
					alloc.destroy(_end);
				}
			}
			
			void	resize(size_type n, value_type val = value_type()) {
				if (n > this->max_size())
					throw (std::length_error("vector::resize"));
				else if (n < this->size())
				{
					while (this->size() > n)
					{
						_end--;
						alloc.destroy(_end);
					}
				}
				else
					this->insert(this->end(), n - this->size(), val);
			};
			
			void	swap(vector & x) {

				if (*this == x)
					return ;
					
				pointer save_start = x.start;
				pointer save_end = x._end;
				pointer save_end_capacity = x.end_capacity;
				allocator_type save_alloc = x.alloc;
	
				x.start = this->start;
				x._end = this->_end;
				x.end_capacity = this->end_capacity;
				x.alloc = this->alloc;
	
				this->start = save_start;
				this->_end = save_end;
				this->end_capacity = save_end_capacity;
				this->alloc = save_alloc;
			}
			
		private:
			
		
		template<class InputIt>
			typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type
			validate_iterator_values(InputIt first, InputIt last, size_t range)
			{
				pointer reserved_buffer;
				reserved_buffer = alloc.allocate(range);
				bool result = true;
				size_type i = 0;

				for (;first != last; ++first, ++i)
				{
					try { reserved_buffer[i] = *first; }
					catch (...) { result = false; break; }
				}
				alloc.deallocate(reserved_buffer, range);
				return result;
			}
		
		
			allocator_type	alloc;
			pointer					start;
			pointer					_end;
			pointer					end_capacity;
			
	};
	
	template <class T, class Allocator >
	bool	operator==(const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs)
	{ 
		if (lhs.size() != rhs.size())
			return false;
			
		typename ft::vector<T>::const_iterator	first1 = lhs.begin();
		typename ft::vector<T>::const_iterator	first2 = rhs.begin();
		while (first1 != lhs.end())
		{
			if (first2 == rhs.end() || *first1 != *first2)
				return false;
			first1++; first2++;
		}
		return true;
	};
	
	template <class T, class Allocator >
	bool	operator!=(const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs)
	{ return !(lhs == rhs); };
	
	template <class T, class Allocator >
	bool	operator<(const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs)
	{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); };
	
	template <class T, class Allocator >
	bool	operator<=(const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs)
	{ return !(rhs < lhs); };
	
	template <class T, class Allocator >
	bool	operator>(const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs)
	{ return rhs < lhs; };
	
	template <class T, class Allocator >
	bool	operator>=(const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs)
	{ return !(lhs<rhs); };
	
	
	template < class T, class Allocator>
	void	swap(vector<T, Allocator> & x, vector<T, Allocator> & y)
			{ x.swap(y); };
	
}

#endif
