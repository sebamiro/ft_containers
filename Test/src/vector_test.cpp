/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:41:12 by smiro             #+#    #+#             */
/*   Updated: 2023/03/05 15:41:16 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.hpp"

void	v_constructorTest(void)
{
	std::cout << "{[>===========CONSTRUCTOR===========<]}" << std::endl;
	g_start = timer();
	vector<int>	vec;
	vector<int> vec2(10000, 42);
	vector<int> vec3(vec2.begin(), vec2.end());
	vector<int> vec4(vec3);
	std::cout << "Empty: " << vec.size() << " " << vec.capacity() << std::endl;
	std::cout << "Fill: " << vec2.size() << " " << vec2.capacity() << std::endl;
	std::cout << "Range: " << vec3.size() << " " << vec3.capacity() << std::endl;
	std::cout << "Copy: " << vec4.size() << " " << vec4.capacity() << std::endl;
	vec = vec4;
	std::cout << "Assign: " << vec.size() << " " << vec.capacity() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	v_beginEndTest(void)
{
	std::cout << "{[>===========BEGIN===========<]}" << std::endl;
	vector<int>	vec(100, 42);
	g_start = timer();
	std::cout << "First: " << (*vec.begin()) << std::endl;
	std::cout << "Second: " << (*++vec.begin()) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;

	std::cout << "{[>===========END===========<]}" << std::endl;
	g_start = timer();
	std::cout << "END - 1: " << (*--vec.end()) << std::endl;
	std::cout << "END - 2: " << (*(vec.end() - 2)) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	v_rbeginEndTest(void)
{
	std::cout << "{[>===========RBEGIN===========<]}" << std::endl;
	vector<int>	vec(100, 42);
	g_start = timer();
	std::cout << "First: " << (*vec.rbegin()) << std::endl;
	std::cout << "Second: " << (*++vec.rbegin()) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;

	std::cout << "{[>===========REND===========<]}" << std::endl;
	g_start = timer();
	std::cout << "END - 1: " << (*--vec.rend()) << std::endl;
	std::cout << "END - 2: " << (*(vec.rend() - 2)) << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	v_sizeTest(void)
{
	std::cout << "{[>===========SIZE===========<]}" << std::endl;
	vector<int>	vec(42, 42);
	g_start = timer();
	std::cout << "Size: " << vec.size() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========MAX SIZE===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Max size: " << vec.max_size() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========CAPACITY===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========EMPTY===========<]}" << std::endl;
	vector<int> vec2;
	g_start = timer();
	std::cout << "Yes: " << vec2.empty() << " | No: " << vec.empty() <<  std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	v_resizeTest(void)
{
	std::cout << "{[>===========RESIZE===========<]}" << std::endl;
	vector<int>	vec(42, 42);
	g_start = timer();
	std::cout << "Initial size: " << vec.size() << " | Initial capacity: " << vec.capacity() << std::endl;
	vec.resize(200000000);
	std::cout << "Resized (200000000) size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	vec.resize(4);
	std::cout << "Resized (4) size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	v_reserveTest(void)
{
	std::cout << "{[>===========RESERVE===========<]}" << std::endl;
	vector<int>	vec(42, 42);
	g_start = timer();
	std::cout << "Initial size: " << vec.size() << " | Initial capacity: " << vec.capacity() << std::endl;
	vec.reserve(200000000);
	std::cout << "Reserved (200000000) size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	vec.reserve(4);
	std::cout << "Reserved (4) size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	v_atOperatorTest(void)
{
	std::cout << "{[>===========OPERATOR[]===========<]}" << std::endl;
	vector<int>	vec;
	for (int i = 0; i < 11; i++)
		vec.push_back(i * 42);
	g_start = timer();
	for (int i = 0; i < 11; i++)
		std::cout << "[" << i << "]: " << vec[i] << " ";
	std::cout << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========AT===========<]}" << std::endl;
	g_start = timer();
	for (int i = 0; i < 11; i++)
		std::cout << "At " << i << ": " << vec.at(i) << " ";
	std::cout << std::endl;
	std::cout << "At 4000: ";
	try { std::cout << vec.at(4000);}
	catch (...) { std::cout << "exception thrown"; }
	std::cout << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	v_forntBackTest(void)
{
	std::cout << "{[>===========FRONT===========<]}" << std::endl;
	vector<int>	vec;
	for (int i = 0; i < 11; i++)
		vec.push_back(i * 42);
	g_start = timer();
	std::cout << "First: " << vec.front() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========BACK===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Last: " << vec.back() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}


void	v_assignTest(void)
{
	std::cout << "{[>===========ASSIGN===========<]}" << std::endl;
	vector<int>	vec(42, 42);
	std::cout << "Initial size: " << vec.size() << " | Initial capacity: " << vec.capacity() << std::endl;
	std::cout << "First: " << vec.front() << " | Last: " << vec.back() << std::endl;
	g_start = timer();
	vec.assign(10, 9);
	g_end = timer();
	std::cout << "Assign Fill (10, 9)" << std::endl;
	std::cout << "Size: " << vec.size() << " | Capacity: " << vec.capacity() << std::endl;
	std::cout << "First: " << vec.front() << " | Last: " << vec.back() << std::endl;
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	vector<int>	vec2;
	for (int i = 1; i < 100000; i++)
		vec2.push_back(i * 42);
	g_start = timer();
	vec.assign(vec2.begin(), vec2.end());
	g_end = timer();
	std::cout << "Assign RANGE" << std::endl;
	std::cout << "Size: " << vec.size() << " | Capacity: " << vec.capacity() << std::endl;
	std::cout << "First: " << vec.front() << " | Last: " << vec.back() << std::endl;
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	v_pushPopTest(void)
{
	std::cout << "{[>===========PUSH BACK===========<]}" << std::endl;
	vector<int>	vec;
	std::cout << "Pushing 10" << std::endl;
	g_start = timer();
 	for (int i = 0; i < 11; i++)
	{
		vec.push_back(i * 42);
		std::cout << " Back: " << vec.back();
	}
	std::cout << std::endl;
	std::cout << "Pushing 1000000" << std::endl;
	vector<int>	vec2;
	for (int i = 1; i < 100000; i++)
		vec2.push_back(i * 42);
	g_end = timer();
	std::cout << "Size: " << vec2.size() << " | Capacity: " << vec2.capacity() << std::endl;
	std::cout << "First: " << vec2.front() << " | Last: " << vec2.back() << std::endl;
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;

	std::cout << "{[>===========POP BACK===========<]}" << std::endl;
	std::cout << "Poping 10" << std::endl;
	g_start = timer();
 	for (int i = 0; i < 11; i++)
	{
		vec.pop_back();
		std::cout << "Back: " << vec.back();
	}
	std::cout << std::endl;
	std::cout << "Poping 1000000" << std::endl;
	std::cout << "Initial size: " << vec2.size() << " | Initial capacity: " << vec2.capacity() << std::endl;
	for (int i = 1; i < 100000; i++)
		vec2.pop_back();
	g_end = timer();
	std::cout << "Size: " << vec2.size() << " | Capacity: " << vec2.capacity() << std::endl;
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	v_insertTest(void)
{
	std::cout << "{[>===========INSERT===========<]}" << std::endl;
	vector<int>	vec;
	vec.insert(vec.begin(), 42);
	g_start = timer();
	std::cout << "Insert single at front: " << vec.front() << " | size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	vec.insert(vec.begin(), 1000, 84);
	std::cout << "Insert fill at front: " << vec.front() << " | back: " << vec.back() << " | size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	vec.insert(vec.begin() + vec.size() / 2, 0);
	std::cout << "Insert single at middle: " << vec.front() << " | back: " << vec.back() << " | size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	vector<int>	vec2;
	vec2.insert(vec2.begin(), vec.begin(), vec.end());
	std::cout << "Insert range at front: " << vec2.front() << " | back: " << vec2.back() << " | size: " << vec2.size() << " | capacity: " << vec2.capacity() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	v_eraseTest(void)
{
	std::cout << "{[>===========ERASE===========<]}" << std::endl;
	vector<int>	vec;
	vec.insert(vec.begin(), 42);
	g_start = timer();
	std::cout << "Initial size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	vec.erase(vec.begin());
	std::cout << "Erase single size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	vec.insert(vec.begin(), 1000, 84);
	std::cout << "Initial size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	vec.erase(vec.begin(), vec.end());
	std::cout << "Erease range size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}

void	v_swapTest(void)
{
	std::cout << "{[>===========SWAP===========<]}" << std::endl;
	vector<int>	vec;
	vec.insert(vec.begin(), 100000000, 42);
	vector<int>	vec2;
	vec2.insert(vec2.begin(), 200000000, 84);
	std::cout << "Initial |1| values: " << vec.front() << " | size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	std::cout << "Initial |2| values: " << vec2.front() << " | size: " << vec2.size() << " | capacity: " << vec2.capacity() << std::endl;
	g_start = timer();
	vec.swap(vec2);
	std::cout << "Swap Method |1| values: " << vec.front() << " | size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	std::cout << "Swap Method |2| values: " << vec2.front() << " | size: " << vec2.size() << " | capacity: " << vec2.capacity() << std::endl;
	swap(vec2, vec);
	std::cout << "Swap external |1| values: " << vec.front() << " | size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	std::cout << "Swap external |2| values: " << vec2.front() << " | size: " << vec2.size() << " | capacity: " << vec2.capacity() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
	std::cout << "{[>===========CLEAR===========<]}" << std::endl;
	g_start = timer();
	std::cout << "Initial size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	vec.clear();
	std::cout << "Cleared size: " << vec.size() << " | capacity: " << vec.capacity() << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}



void	v_operatorTest(void)
{
	std::cout << "{[>===========OPERATORS===========<]}" << std::endl;
	vector<int>	vec(42, 42);
	vector<int>	vec2(42, 42);
	vector<int>	vec3(84, 84);
	vector<int>	vec4(84, 84);
	g_start = timer();
	std::cout << "OPERATOR ==: |Yes: " << (vec == vec2) << "| |No: " << (vec2 == vec4) << "|" << std::endl;
	std::cout << "OPERATOR !=: |Yes: " << (vec != vec4) << "| |No: " << (vec3 != vec4) << "|" << std::endl;
	std::cout << "OPERATOR <: |Yes: " << (vec < vec3) << "| |No: " << (vec2 < vec) << "|" << std::endl;
	std::cout << "OPERATOR <=: |Yes: " << (vec <= vec2) << "| |No: " << (vec3 <= vec) << "|" << std::endl;
	std::cout << "OPERATOR >: |Yes: " << (vec4 > vec2) << "| |No: " << (vec > vec2) << "|" << std::endl;
	std::cout << "OPERATOR >=: |Yes: " << (vec4 >= vec2) << "| |No: " << (vec >= vec4) << "|" << std::endl;
	g_end = timer();
	std::cout << "Time: " << 	g_end - g_start << " [MS]" << std::endl;
}
