/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:28:37 by smiro             #+#    #+#             */
/*   Updated: 2023/03/05 15:28:38 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.hpp"

static void	vector_test(void)
{
	std::cout << std::endl;
	std::cout << "|============================================|" << std::endl;
	std::cout << "|===========        VECTOR        ===========|" << std::endl;
	std::cout << "|============================================|" << std::endl;
	std::cout << std::endl;

	v_constructorTest();
	v_beginEndTest();
	v_rbeginEndTest();
	v_sizeTest();
	v_resizeTest();
	v_reserveTest();
	v_atOperatorTest();
	v_forntBackTest();
	v_assignTest();
	v_pushPopTest();
	v_insertTest();
	v_eraseTest();
	v_swapTest();
	v_operatorTest();
}

static void	map_test(void)
{
	std::cout << std::endl;
	std::cout << "|============================================|" << std::endl;
	std::cout << "|===========          MAP         ===========|" << std::endl;
	std::cout << "|============================================|" << std::endl;
	std::cout << std::endl;

	m_constructorTest();
	compareTests();
	m_beginEndTest();
	m_rbeginEndTest();
	m_insertTest();
	m_atOperatorTest();
	m_sizeTest();
	m_eraseTest();
	m_swapTest();
	m_countFindTest();
	m_lowerUpperEqualTest();
	m_keyCompareTest();
	m_operatorTest();
}

static void	set_test(void)
{
	std::cout << std::endl;
	std::cout << "|============================================|" << std::endl;
	std::cout << "|===========          SET         ===========|" << std::endl;
	std::cout << "|============================================|" << std::endl;
	std::cout << std::endl;

	s_constructorTest();
	s_compareTests();
	s_beginEndTest();
	s_rbeginEndTest();
	s_insertTest();
	s_sizeTest();
	s_eraseTest();
	s_swapTest();
	s_countFindTest();
	s_lowerUpperEqualTest();
	s_keyCompareTest();
	s_operatorTest();
}


static void	stack_test(void)
{
	std::cout << std::endl;
	std::cout << "|============================================|" << std::endl;
	std::cout << "|===========         STACK        ===========|" << std::endl;
	std::cout << "|============================================|" << std::endl;
	std::cout << std::endl;

	st_constructorTest();
	st_pushPop();
	st_topTest();
	st_sizeEmptyTest();
	st_operatorTest();

}

int	main(void)
{
	set_test();
	return 0;
	vector_test();
	map_test();
	stack_test();
}
