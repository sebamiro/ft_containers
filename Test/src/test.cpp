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

static void	stack_test(void)
{
	std::cout << std::endl;
	std::cout << "|============================================|" << std::endl;
	std::cout << "|===========         STACK        ===========|" << std::endl;
	std::cout << "|============================================|" << std::endl;
	std::cout << std::endl;

	s_constructorTest();
	s_pushPop();
	s_topTest();
	s_sizeEmptyTest();
	s_operatorTest();

}

int	main(void)
{
	vector_test();
	map_test();
	stack_test();
	return 0;
}
