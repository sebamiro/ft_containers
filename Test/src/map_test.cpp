/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:11:56 by smiro             #+#    #+#             */
/*   Updated: 2023/03/05 20:11:57 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.hpp"
#include "Map.hpp"
#include <map>

void	m_constructorTest(void)
{
	std::cout << "{[>===========CONSTRUCTOR===========<]}" << std::endl;
	g_start = timer();
	map<int, int>	map1;
	map<int, int> map2;
	map2.insert(make_pair(1, 1));
	map2.insert(make_pair(2, 2));
	map2.insert(make_pair(3, 3));
	map2.insert(make_pair(4, 4));
	map2.insert(make_pair(5, 5));
	map<int, int> map3(map2.begin(), map2.end());
	map<int, int> map4(map3);
	std::cout << "Empty: " << map1.size() << " Begin: " << (*map1.begin()).first << " End: " << (*--map1.end()).first << std::endl;
	std::cout << "Range: " << map3.size() << " Begin: " << (*map3.begin()).first << " End: " << (*--map3.end()).first << std::endl;
	std::cout << "Copy: " << map4.size() << " Begin: " << (*map4.begin()).first << " End: " << (*--map4.end()).first << std::endl;
	map1 = map4;
	std::cout << "Assign: " << map1.size() << " Begin: " << (*map1.begin()).first << " End: " << (*map1.end()).first << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	compareTests(void)
{
	std::cout << "{[>===========COMPARE REDEFINITION===========<]}" << std::endl;
	g_start = timer();
	map<int, int>	m1;
	m1.insert(make_pair(16, 3));
	m1.insert(make_pair(8, 3));
	m1.insert(make_pair(23, 3));
	m1.insert(make_pair(7, 3));
	m1.insert(make_pair(19, 3));
	m1.insert(make_pair(29, 3));
	m1.insert(make_pair(41, 3));
	m1.insert(make_pair(4, 3));
	m1.insert(make_pair(11, 3));
	std::cout << "Default: ";
	for (std::map<int, int>::iterator it = m1.begin(); it != m1.end(); it++) { std::cout << (*it).first << " "; };
 	std::cout << std::endl;
  map<int, int, std::multiplies<int> >	m2;
	m2.insert(make_pair(16, 3));
	m2.insert(make_pair(8, 3));
	m2.insert(make_pair(23, 3));
	m2.insert(make_pair(7, 3));
	m2.insert(make_pair(19, 3));
	m2.insert(make_pair(29, 3));
	m2.insert(make_pair(41, 3));
	m2.insert(make_pair(4, 3));
	m2.insert(make_pair(11, 3));
	std::cout << "Multiples: ";
	for (std::map<int, int>::iterator it = m2.begin(); it != m2.end(); it++) { std::cout << (*it).first << " "; };
  std::cout << std::endl;
  map<int, int, std::bit_xor<int> >	m3;
	m3.insert(make_pair(16, 3));
	m3.insert(make_pair(8, 3));
	m3.insert(make_pair(23, 3));
	m3.insert(make_pair(7, 3));
	m3.insert(make_pair(19, 3));
	m3.insert(make_pair(29, 3));
	m3.insert(make_pair(41, 3));
	m3.insert(make_pair(4, 3));
	m3.insert(make_pair(11, 3));
	std::cout << "Bit Xor: ";
	for (std::map<int, int>::iterator it = m3.begin(); it != m3.end(); it++) { std::cout << (*it).first << " "; };
  std::cout << std::endl;
  g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	m_insertTest(void)
{
	std::cout << "{[>===========INSERT===========<]}" << std::endl;
	map<int, int>	m1;
	g_start = timer();
	for (int i = 0; i < 500000; i++)
		m1.insert(make_pair(i, 42));
	g_end = timer();
	std::cout << "Insert single element: size: " << m1.size() << std::endl;
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	map<int, int>	m2;
	g_start = timer();
	for (int i = 0; i < 500000; i++)
		m2.insert(m2.end(), make_pair(i, 42));
	g_end = timer();
	std::cout << "Insert with hint: size: " << m1.size() << std::endl;
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	map<int, int>	m3;
	g_start = timer();
	m3.insert(m2.begin(), m2.end());
	g_end = timer();
	std::cout << "Insert Range: size: " << m1.size() << std::endl;
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	m_atOperatorTest(void)
{
	std::cout << "{[>===========OPERATOR[]===========<]}" << std::endl;
	map<int, int>	m;
	for (int i = 0; i < 11; i++)
		m.insert(make_pair(i, 42 * i));
	g_start = timer();
	for (int i = 0; i < 11; i++)
		std::cout << "[" << i << "]: " << m[i] << " ";
	std::cout << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========AT===========<]}" << std::endl;
	g_start = timer();
	for (int i = 0; i < 11; i++)
		std::cout << "At " << i << ": " << m.at(i) << " ";
	std::cout << std::endl;
	std::cout << "At 4000: ";
	try { std::cout << m.at(4000);}
	catch (...) { std::cout << "exception thrown"; }
	std::cout << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	m_sizeTest(void)
{
	std::cout << "{[>===========SIZE===========<]}" << std::endl;
	map<int, int>	m;
	for (int i = 0; i < 500000; i++)
		m.insert(make_pair(i, 42));
	g_start = timer();
	std::cout << "Size: " << m.size() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========MAX SIZE===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Max size: " << m.max_size() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========EMPTY===========<]}" << std::endl;
	map<int, int> m2;
	g_start = timer();
	std::cout << "Yes: " << m2.empty() << " | No: " << m.empty() <<  std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========CLEAR===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Initial size: " << m.size() << std::endl;
	m.clear();
	std::cout << "Cleared size: " << m.size() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	m_eraseTest(void)
{
	std::cout << "{[>===========ERASE===========<]}" << std::endl;
	map<int, int>	m;
	for (int i = 0; i < 500000; i++)
		m.insert(make_pair(i, 42));
	g_start = timer();
	std::cout << "Initial size: " << m.size() << " End: " << (*--m.end()).first  << " - " << (*--m.end()).second << std::endl;
	m.erase(499999);
	std::cout << "Erase by key: size: " << m.size() << " End: " << (*--m.end()).first  << " - " << (*--m.end()).second << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	g_start = timer();
	m.erase(m.begin());
	std::cout << "Erase by position: size: " << m.size() << " Begin: " << (*m.begin()).first  << " - " << (*m.begin()).second << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	g_start = timer();
	m.erase(++m.begin(), --m.end());
	std::cout << "Erase by range: size: " << m.size() << " Begin: " << (*m.begin()).first  << " - " << (*m.begin()).second << " End: " << (*--m.end()).first  << " - " << (*--m.end()).second << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	m_swapTest(void)
{
	std::cout << "{[>===========SWAP===========<]}" << std::endl;
	map<int, int>	m;
	for (int i = 0; i < 1500000; i++)
		m.insert(make_pair(i, 42));
	map<int, int>	m2;
	for (int i = 0; i < 2500000; i++)
		m2.insert(make_pair(i, 84));
	std::cout << "Initial |1| values: " << " Begin: " << (*m.begin()).first  << " - " << (*m.begin()).second << " End: " << (*--m.end()).first  << " - " << (*--m.end()).second << " | size: " << m.size() << std::endl;
	std::cout << "Initial |2| values: " << " Begin: " << (*m2.begin()).first  << " - " << (*m2.begin()).second << " End: " << (*--m2.end()).first  << " - " << (*--m2.end()).second << " | size: " << m2.size() << std::endl;
	g_start = timer();
	m.swap(m2);
	std::cout << "Swap Method |1| values: " << " Begin: " << (*m.begin()).first  << " - " << (*m.begin()).second << " End: " << (*--m.end()).first  << " - " << (*--m.end()).second << " | size: " << m.size() << std::endl;
	std::cout << "Swap Method |2| values: " << " Begin: " << (*m2.begin()).first  << " - " << (*m2.begin()).second << " End: " << (*--m2.end()).first  << " - " << (*--m2.end()).second << " | size: " << m2.size() << std::endl;
	swap(m2, m);
	std::cout << "Swap External Function |1| values: " << " Begin: " << (*m.begin()).first  << " - " << (*m.begin()).second << " End: " << (*--m.end()).first  << " - " << (*--m.end()).second << " | size: " << m.size() << std::endl;
	std::cout << "Swap External Function |2| values: " << " Begin: " << (*m2.begin()).first  << " - " << (*m2.begin()).second << " End: " << (*--m2.end()).first  << " - " << (*--m2.end()).second << " | size: " << m2.size() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	m_countFindTest(void)
{
	std::cout << "{[>===========COUTN===========<]}" << std::endl;
	map<int, int>	m;
	for (int i = 0; i < 1500000; i++)
		m.insert(make_pair(i, 42));
	g_start = timer();
	std::cout << "Count |0|: " << m.count(0) << std::endl;
	std::cout << "Count |42|: " << m.count(42) << std::endl;
	std::cout << "Count |-2|: " << m.count(-2) << std::endl;
	std::cout << "Count |8521412|: " << m.count(8521412) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========FIND===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Find |0|: " << (*m.find(0)).first << " - " <<(*m.find(0)).second << std::endl;
	std::cout << "Find |42|: " << (*m.find(42)).first << " - " <<(*m.find(42)).second << std::endl;
	std::cout << "Find |-2|: " << (*m.find(-2)).first << " -"  << std::endl;
	std::cout << "Find |8521412|: " << (*m.find(8521412)).first << " -"<< std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	m_lowerUpperEqualTest(void)
{
	std::cout << "{[>===========LOWER BOUND===========<]}" << std::endl;
	map<int, int>	m;
	for (int i = 0; i < 1500000; i++)
		m.insert(make_pair(i, 42));
	g_start = timer();
	std::cout << "Values: " << " Begin: " << (*m.begin()).first  << " - " << (*m.begin()).second << " End: " << (*--m.end()).first  << " - " << (*--m.end()).second << " | size: " << m.size() << std::endl;
	std::cout << "Lower bound 42: " << (*m.lower_bound(42)).first << " - " << (*m.lower_bound(42)).second << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========UPPER BOUND===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Values: " << " Begin: " << (*m.begin()).first  << " - " << (*m.begin()).second << " End: " << (*--m.end()).first  << " - " << (*--m.end()).second << " | size: " << m.size() << std::endl;
	std::cout << "Upper bound 42: " << (*m.upper_bound(42)).first << " - " << (*m.upper_bound(42)).second << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========EQUAL RANGE===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Values: " << " Begin: " << (*m.begin()).first  << " - " << (*m.begin()).second << " End: " << (*--m.end()).first  << " - " << (*--m.end()).second << " | size: " << m.size() << std::endl;
	std::cout << "Equal Range 42: " << (*m.equal_range(42).first).first << " - " << (*m.equal_range(42).first).second << " | " << (*m.equal_range(42).second).first << " - " << (*m.equal_range(42).second).second<< std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	m_beginEndTest(void)
{
	std::cout << "{[>===========BEGIN===========<]}" << std::endl;
	map<int, int>	m;
	for (int i = 0; i < 15000; i++)
		m.insert(make_pair(i, 42));
	g_start = timer();
	std::cout << "First: " << (*m.begin()).first << " - " << (*m.begin()).second << std::endl;
	std::cout << "Second: " << (*++m.begin()).first << " - " << (*++m.begin()).second << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;

	std::cout << "{[>===========END===========<]}" << std::endl;
	g_start = timer();
	std::cout << "END - 1: " << (*--m.end()).first << " - " << (*--m.end()).second << std::endl;
	std::cout << "END - 2: " << (*--(--m.end())).first << " - " << (*--(--m.end())).second << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	m_rbeginEndTest(void)
{
	std::cout << "{[>===========RBEGIN===========<]}" << std::endl;
	map<int, int>	m;
	for (int i = 0; i < 15000; i++)
		m.insert(make_pair(i, 42));
	g_start = timer();
	std::cout << "First: " << (*m.rbegin()).first << " - " << (*m.rbegin()).second << std::endl;
	std::cout << "Second: " << (*++m.rbegin()).first << " - " << (*++m.rbegin()).second << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;

	std::cout << "{[>===========REND===========<]}" << std::endl;
	g_start = timer();
	std::cout << "END - 1: " << (*--m.rend()).first << " - " << (*--m.rend()).second << std::endl;
	std::cout << "END - 2: " << (*--(--m.rend())).first << " - " << (*--(--m.rend())).second << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	m_keyCompareTest(void)
{
	std::cout << "{[>===========KEY COMP===========<]}" << std::endl;
	map<int, int>	m;
	map<int, int>::key_compare comp = m.key_comp();
	g_start = timer();
	std::cout << "Compare: 1-2 = " << comp(1, 2) << " | 42-42 = " << comp(42, 42) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;

	std::cout << "{[>===========VALUE COMP===========<]}" << std::endl;
	map<int, int>::value_compare comp2 = m.value_comp();
	g_start = timer();
	std::cout << "Compare: 1-2 = " << comp2(make_pair(1, 1), make_pair(2, 2)) << " | 42-42 = " << comp2(make_pair(42, 42), make_pair(42, 42)) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	m_operatorTest(void)
{
	std::cout << "{[>===========OPERATORS===========<]}" << std::endl;
	map<int, int>	m;
	for (int i = 0; i < 42; i++)
		m.insert(make_pair(i, 42));
	map<int, int>	m2(m.begin(), m.end());
	map<int, int>	m3;
	for (int i = 0; i < 84; i++)
		m3.insert(make_pair(i, 84));
	map<int, int>	m4(m3.begin(), m3.end());
	g_start = timer();
	std::cout << "OPERATOR ==: |Yes: " << (m == m2) << "| |No: " << (m2 == m4) << "|" << std::endl;
	std::cout << "OPERATOR !=: |Yes: " << (m != m4) << "| |No: " << (m3 != m4) << "|" << std::endl;
	std::cout << "OPERATOR <: |Yes: " << (m < m3) << "| |No: " << (m2 < m) << "|" << std::endl;
	std::cout << "OPERATOR <=: |Yes: " << (m <= m2) << "| |No: " << (m3 <= m) << "|" << std::endl;
	std::cout << "OPERATOR >: |Yes: " << (m4 > m2) << "| |No: " << (m > m2) << "|" << std::endl;
	std::cout << "OPERATOR >=: |Yes: " << (m4 >= m2) << "| |No: " << (m >= m4) << "|" << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}
