/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atohhi_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:20:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:27:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	char const		*str;
	char const		*base;
	t_hhint const	expect;
};

static t_test const		g_test[] = {
{1, "42", "", 0},
{2, "21", "+0123456789", 0},
{3, "101010", "01-", 0},
{4, "fee", "poney vif", 0},
{5, "  -aa", "a", 0},
{6, "ABBA  ", "BAOBAB", 0},
{7, "ABBA  ", "BA", 9},
{8, "+|||||.......", "|.", CHAR_MAX},
{9, "  -2AbC", "0123456789ABCDEF", -42},
{10, " -lxxxxxxx xxlxll", "xl", CHAR_MIN},
{11, "++010101", "10", 0},
{12, " +010101", "10", 42},
{13, "-Jonathan", "ahnJto", -6},
{14, " XXX 4242", "XP", 0},
{0}
};

int	test_ft_atohhi_base(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		result(g_test[i].num,
			ft_atohhi_base(g_test[i].str, g_test[i].base) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
