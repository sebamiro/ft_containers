/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:11:56 by smiro             #+#    #+#             */
/*   Updated: 2023/03/05 20:11:57 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.hpp"
#include "Set.hpp"
#include <set>

void	s_constructorTest(void)
{
	std::cout << "{[>===========CONSTRUCTOR===========<]}" << std::endl;
	g_start = timer();
	set<int>	set1;
	set<int>	set2;
	set2.insert(1);
	set2.insert(2);
	set2.insert(3);
	set2.insert(4);
	set2.insert(5);
	set<int> set3(set2.begin(), set2.end());
	set<int> set4(set3);
	std::cout << "Empty: " << set1.size() << " Begin: " << (*set1.begin()) << " End: " << (*--set1.end()) << std::endl;
	std::cout << "Range: " << set3.size() << " Begin: " << (*set3.begin()) << " End: " << (*--set3.end()) << std::endl;
	std::cout << "Copy: " << set4.size() << " Begin: " << (*set4.begin()) << " End: " << (*--set4.end()) << std::endl;
	set1 = set4;
	std::cout << "Assign: " << set1.size() << " Begin: " << (*set1.begin()) << " End: " << (*set1.end()) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	s_compareTests(void)
{
	std::cout << "{[>===========COMPARE REDEFINITION===========<]}" << std::endl;
	g_start = timer();
	set<int>	s1;
	s1.insert(16);
	s1.insert(8);
	s1.insert(23);
	s1.insert(7);
	s1.insert(19);
	s1.insert(29);
	s1.insert(41);
	s1.insert(4);
	s1.insert(11);
	std::cout << "Default: ";
	for (std::set<int>::iterator it = s1.begin(); it != s1.end(); it++) { std::cout << (*it) << " "; };
 	std::cout << std::endl;
  set<int, std::multiplies<int> >	s2;
	s2.insert(16);
	s2.insert(8);
	s2.insert(23);
	s2.insert(7);
	s2.insert(19);
	s2.insert(29);
	s2.insert(41);
	s2.insert(4);
	s2.insert(11);
	std::cout << "Multiples: ";
	for (std::set<int>::iterator it = s2.begin(); it != s2.end(); it++) { std::cout << (*it) << " "; };
  std::cout << std::endl;
  set<int, std::bit_xor<int> >	s3;
	s3.insert(16);
	s3.insert(8);
	s3.insert(23);
	s3.insert(7);
	s3.insert(19);
	s3.insert(29);
	s3.insert(41);
	s3.insert(4);
	s3.insert(11);
	std::cout << "Bit Xor: ";
	for (std::set<int>::iterator it = s3.begin(); it != s3.end(); it++) { std::cout << (*it) << " "; };
  std::cout << std::endl;
  g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	s_insertTest(void)
{
	std::cout << "{[>===========INSERT===========<]}" << std::endl;
	set<int>	s1;
	g_start = timer();
	for (int i = 0; i < 500000; i++)
		s1.insert(i);
	g_end = timer();
	std::cout << "Insert single element: size: " << s1.size() << std::endl;
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	set<int>	s2;
	g_start = timer();
	for (int i = 0; i < 500000; i++)
		s2.insert(s2.end(), i);
	g_end = timer();
	std::cout << "Insert with hint: size: " << s1.size() << std::endl;
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	set<int>	s3;
	g_start = timer();
	s3.insert(s2.begin(), s2.end());
	g_end = timer();
	std::cout << "Insert Range: size: " << s1.size() << std::endl;
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	s_sizeTest(void)
{
	std::cout << "{[>===========SIZE===========<]}" << std::endl;
	set<int>	s;
	for (int i = 0; i < 500000; i++)
		s.insert(i);
	g_start = timer();
	std::cout << "Size: " << s.size() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========MAX SIZE===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Max size: " << s.max_size() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========EMPTY===========<]}" << std::endl;
	set<int> s2;
	g_start = timer();
	std::cout << "Yes: " << s2.empty() << " | No: " << s.empty() <<  std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========CLEAR===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Initial size: " << s.size() << std::endl;
	s.clear();
	std::cout << "Cleared size: " << s.size() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	s_eraseTest(void)
{
	std::cout << "{[>===========ERASE===========<]}" << std::endl;
	set<int>	s;
	for (int i = 0; i < 500000; i++)
		s.insert(i);
	g_start = timer();
	std::cout << "Initial size: " << s.size() << " End: " << (*--s.end())  << " - " << (*--s.end()) << std::endl;
	s.erase(499999);
	std::cout << "Erase by key: size: " << s.size() << " End: " << (*--s.end())  << " - " << (*--s.end()) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	g_start = timer();
	s.erase(s.begin());
	std::cout << "Erase by position: size: " << s.size() << " Begin: " << (*s.begin())  << " - " << (*s.begin()) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	g_start = timer();
	s.erase(++s.begin(), --s.end());
	std::cout << "Erase by range: size: " << s.size() << " Begin: " << (*s.begin())  << " - " << (*s.begin()) << " End: " << (*--s.end())  << " - " << (*--s.end()) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	s_swapTest(void)
{
	std::cout << "{[>===========SWAP===========<]}" << std::endl;
	set<int>	s;
	for (int i = 0; i < 1500000; i++)
		s.insert(i);
	set<int>	s2;
	for (int i = 0; i < 2500000; i++)
		s2.insert(i);
	std::cout << "Initial |1| values: " << " Begin: " << (*s.begin())  << " - " << (*s.begin()) << " End: " << (*--s.end())  << " - " << (*--s.end()) << " | size: " << s.size() << std::endl;
	std::cout << "Initial |2| values: " << " Begin: " << (*s2.begin())  << " - " << (*s2.begin()) << " End: " << (*--s2.end())  << " - " << (*--s2.end()) << " | size: " << s2.size() << std::endl;
	g_start = timer();
	s.swap(s2);
	std::cout << "Swap Method |1| values: " << " Begin: " << (*s.begin())  << " - " << (*s.begin()) << " End: " << (*--s.end())  << " - " << (*--s.end()) << " | size: " << s.size() << std::endl;
	std::cout << "Swap Method |2| values: " << " Begin: " << (*s2.begin())  << " - " << (*s2.begin()) << " End: " << (*--s2.end())  << " - " << (*--s2.end()) << " | size: " << s2.size() << std::endl;
	swap(s2, s);
	std::cout << "Swap External Function |1| values: " << " Begin: " << (*s.begin())  << " - " << (*s.begin()) << " End: " << (*--s.end())  << " - " << (*--s.end()) << " | size: " << s.size() << std::endl;
	std::cout << "Swap External Function |2| values: " << " Begin: " << (*s2.begin())  << " - " << (*s2.begin()) << " End: " << (*--s2.end())  << " - " << (*--s2.end()) << " | size: " << s2.size() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	s_countFindTest(void)
{
	std::cout << "{[>===========COUTN===========<]}" << std::endl;
	set<int>	s;
	for (int i = 0; i < 1500000; i++)
		s.insert(i);
	g_start = timer();
	std::cout << "Count |0|: " << s.count(0) << std::endl;
	std::cout << "Count |42|: " << s.count(42) << std::endl;
	std::cout << "Count |-2|: " << s.count(-2) << std::endl;
	std::cout << "Count |8521412|: " << s.count(8521412) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========FIND===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Find |0|: " << (*s.find(0)) << " - " <<(*s.find(0)) << std::endl;
	std::cout << "Find |42|: " << (*s.find(42)) << " - " <<(*s.find(42)) << std::endl;
	std::cout << "Find |-2|: " << (*s.find(-2)) << " - " <<(*s.find(-2)) << std::endl;
	std::cout << "Find |8521412|: " << (*s.find(8521412)) << " - " <<(*s.find(8521412)) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	s_lowerUpperEqualTest(void)
{
	std::cout << "{[>===========LOWER BOUND===========<]}" << std::endl;
	set<int>	s;
	for (int i = 0; i < 1500000; i++)
		s.insert(i);
	g_start = timer();
	std::cout << "Values: " << " Begin: " << (*s.begin())  << " - " << (*s.begin()) << " End: " << (*--s.end())  << " - " << (*--s.end()) << " | size: " << s.size() << std::endl;
	std::cout << "Lower bound 42: " << (*s.lower_bound(42)) << " - " << (*s.lower_bound(42)) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========UPPER BOUND===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Values: " << " Begin: " << (*s.begin())  << " - " << (*s.begin()) << " End: " << (*--s.end())  << " - " << (*--s.end()) << " | size: " << s.size() << std::endl;
	std::cout << "Upper bound 42: " << (*s.upper_bound(42)) << " - " << (*s.upper_bound(42)) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========EQUAL RANGE===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Values: " << " Begin: " << (*s.begin())  << " - " << (*s.begin()) << " End: " << (*--s.end())  << " - " << (*--s.end()) << " | size: " << s.size() << std::endl;
	std::cout << "Equal Range 42: " << (*s.equal_range(42).first) << " | " << (*s.equal_range(42).second)<< std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	s_beginEndTest(void)
{
	std::cout << "{[>===========BEGIN===========<]}" << std::endl;
	set<int>	s;
	for (int i = 0; i < 15000; i++)
		s.insert(i);
	g_start = timer();
	std::cout << "First: " << (*s.begin()) << " - " << (*s.begin()) << std::endl;
	std::cout << "Second: " << (*++s.begin()) << " - " << (*++s.begin()) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;

	std::cout << "{[>===========END===========<]}" << std::endl;
	g_start = timer();
	std::cout << "END - 1: " << (*--s.end()) << " - " << (*--s.end()) << std::endl;
	std::cout << "END - 2: " << (*--(--s.end())) << " - " << (*--(--s.end())) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	s_rbeginEndTest(void)
{
	std::cout << "{[>===========RBEGIN===========<]}" << std::endl;
	set<int>	s;
	for (int i = 0; i < 15000; i++)
		s.insert(i);
	g_start = timer();
	std::cout << "First: " << (*s.rbegin()) << " - " << (*s.rbegin()) << std::endl;
	std::cout << "Second: " << (*++s.rbegin()) << " - " << (*++s.rbegin()) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;

	std::cout << "{[>===========REND===========<]}" << std::endl;
	g_start = timer();
	std::cout << "END - 1: " << (*--s.rend()) << " - " << (*--s.rend()) << std::endl;
	std::cout << "END - 2: " << (*--(--s.rend())) << " - " << (*--(--s.rend())) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	s_keyCompareTest(void)
{
	std::cout << "{[>===========KEY COMP===========<]}" << std::endl;
	set<int>	s;
	set<int>::key_compare comp = s.key_comp();
	g_start = timer();
	std::cout << "Compare: 1-2 = " << comp(1, 2) << " | 42-42 = " << comp(42, 42) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;

	std::cout << "{[>===========VALUE COMP===========<]}" << std::endl;
	set<int>::value_compare comp2 = s.value_comp();
	g_start = timer();
	std::cout << "Compare: 1-2 = " << comp2(1, 2) << " | 42-42 = " << comp2(42, 42) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	s_operatorTest(void)
{
	std::cout << "{[>===========OPERATORS===========<]}" << std::endl;
	set<int>	s;
	for (int i = 0; i < 42; i++)
		s.insert(i);
	set<int>	s2(s.begin(), s.end());
	set<int>	s3;
	for (int i = 0; i < 84; i++)
		s3.insert(i);
	set<int>	s4(s3.begin(), s3.end());
	g_start = timer();
	std::cout << "OPERATOR ==: |Yes: " << (s == s2) << "| |No: " << (s2 == s4) << "|" << std::endl;
	std::cout << "OPERATOR !=: |Yes: " << (s != s4) << "| |No: " << (s3 != s4) << "|" << std::endl;
	std::cout << "OPERATOR <: |Yes: " << (s < s3) << "| |No: " << (s2 < s) << "|" << std::endl;
	std::cout << "OPERATOR <=: |Yes: " << (s <= s2) << "| |No: " << (s3 <= s) << "|" << std::endl;
	std::cout << "OPERATOR >: |Yes: " << (s4 > s2) << "| |No: " << (s > s2) << "|" << std::endl;
	std::cout << "OPERATOR >=: |Yes: " << (s4 >= s2) << "| |No: " << (s >= s4) << "|" << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}
