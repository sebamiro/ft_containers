/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:51:38 by smiro             #+#    #+#             */
/*   Updated: 2023/02/20 14:51:41 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{
	
	template < bool is_integral, typename T >
	struct is_integral_res
	{
		typedef T type;
		static const bool value = is_integral;
	};
	
	template < typename > struct is_integral_type : public is_integral_res<false, bool> {};
	template <> struct is_integral_type<bool> : public is_integral_res<true, bool> {};
	template <> struct is_integral_type<char> : public is_integral_res<true, char> {};
	template <> struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};
	template <> struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};
	template <> struct is_integral_type<char16_t> : public is_integral_res<true, char16_t> {};
	template <> struct is_integral_type<char32_t> : public is_integral_res<true, char32_t> {};
	template <> struct is_integral_type<wchar_t> : public is_integral_res<true, wchar_t> {};
	template <> struct is_integral_type<short int> : public is_integral_res<true, short int> {};
	template <> struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};
	template <> struct is_integral_type<int> : public is_integral_res<true, int> {};
	template <> struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};
	template <> struct is_integral_type<long int> : public is_integral_res<true, long int> {};
	template <> struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
	template <> struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};
	template <> struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};
	
	
	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

}

#endif
