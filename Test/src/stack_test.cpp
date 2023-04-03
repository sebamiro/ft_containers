/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:03:00 by smiro             #+#    #+#             */
/*   Updated: 2023/03/06 17:03:02 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.hpp"
#include "Stack.hpp"
#include <stack>
#include <vector>
#include "Vector.hpp"

void	st_constructorTest(void)
{
	std::cout << "{[>===========CONSTRUCTOR===========<]}" << std::endl;
	std::deque<int> mydeque (3,100);
	std::vector<int> myvector (2,200);
	g_start = timer();
	stack<int, vector<int> >	stack1;
	stack<int, std::deque<int> > stack2;
	stack<int, std::deque<int> > stack3(mydeque);
	stack<int, std::vector<int > > stack4(myvector);
	std::cout << "Empty vector: size: " << stack1.size() << std::endl;
	std::cout << "Empty deque: size: " << stack2.size() << std::endl;
	std::cout << "Construct deque: size: " << stack3.size() << std::endl;
	std::cout << "Construct vector: size: " << stack4.size() << std::endl;
	stack1 = stack4;
	std::cout << "Assign: size: " << stack1.size() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	st_pushPop(void)
{
	std::cout << "{[>===========PUSH===========<]}" << std::endl;
	stack<int, vector<int> > s;
	cout << "Empty: size: " << s.size() << std::endl;
	g_start = timer();
	for (int i = 0; i < 10; i++)
		s.push(i);
	cout << "10: size: " << s.size() << std::endl;
	for (int i = 0; i < 110000000; i++)
		s.push(i);
	cout << "110000010: size: " << s.size() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========POP===========<]}" << std::endl;
	cout << "Initial size: " << s.size() << std::endl;
	g_start = timer();
	for (int i = 0; i < 10; i++)
		s.pop();
	cout << "10 poped: size: " << s.size() << std::endl;
	for (int i = 0; i < 110000000; i++)
		s.pop();
	cout << "110000000 poped: size: " << s.size() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	st_topTest(void)
{
	std::cout << "{[>===========TOP===========<]}" << std::endl;
	g_start = timer();
	stack<int, vector<int> > s;
	for (int i = 0; i < 10; i++)
	{
		s.push(i * 42);
		std::cout << "TOP: " << s.top() << " ";
	}
	std::cout << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	st_sizeEmptyTest(void)
{
	std::cout << "{[>===========SIZE===========<]}" << std::endl;
	stack<int> s;
	vector<int> v(100000, 42);
	stack<int, vector<int> > s2(v);
	g_start = timer();
	std::cout << "Size empty: " << s.size()	<< std::endl;
	std::cout << "Size 100000: " << s2.size()	<< std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========EMPTY===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Empty: yes: " << s.empty() << " | no: " << s2.empty() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	st_operatorTest(void)
{
	std::cout << "{[>===========OPERATORS===========<]}" << std::endl;
	stack<int>	s;
	s.push(42);
	stack<int>	s2(s);
	stack<int>	s3;
	s3.push(84);
	stack<int>	s4(s3);
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
