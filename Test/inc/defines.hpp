/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:08:20 by smiro             #+#    #+#             */
/*   Updated: 2023/03/05 15:08:22 by smiro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_HPP
# define DEFINES_HPP

#include "../../Vector.hpp"
#include "../../Map.hpp"
#include "../../Stack.hpp"
#include "../../utility.hpp"
#include <vector>
#include <map>
#include <stack>
#include <iostream>
#include <sys/time.h>
#include <utility>

#ifdef FT
	using namespace ft;
#else
	using namespace std;
#endif

volatile static time_t g_start;
volatile static time_t g_end;


time_t timer();
//VECTOR
void	v_constructorTest(void);
void	v_beginEndTest(void);
void	v_rbeginEndTest(void);
void	v_sizeTest(void);
void	v_resizeTest(void);
void	v_reserveTest(void);
void	v_atOperatorTest(void);
void	v_forntBackTest(void);
void	v_assignTest(void);
void	v_pushPopTest(void);
void	v_insertTest(void);
void	v_eraseTest(void);
void	v_swapTest(void);
void	v_operatorTest(void);

//MAP
void	m_constructorTest(void);
void	compareTests(void);
void	m_beginEndTest(void);
void	m_rbeginEndTest(void);
void	m_insertTest(void);
void	m_atOperatorTest(void);
void	m_sizeTest(void);
void	m_eraseTest(void);
void	m_swapTest(void);
void	m_countFindTest(void);
void	m_lowerUpperEqualTest(void);
void	m_keyCompareTest(void);
void	m_operatorTest(void);

//STACK
void	s_constructorTest(void);
void	s_pushPop(void);
void	s_topTest(void);
void	s_sizeEmptyTest(void);
void	s_operatorTest(void);


#endif
