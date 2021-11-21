/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atolu_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:23:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 10:30:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	char const		*str;
	char const		*base;
	t_luint const	expect;
};

static t_test const		g_test[] = {
{0, "42", "", 0},
{1, "21", "+0123456789", 0},
{2, "101010", "01-", 0},
{3, "fee", "poney vif", 0},
{4, "  -aa", "a", 0},
{5, "ABBA  ", "BAOBAB", 0},
{6, "ABBA  ", "BA", 9},
{7, "+..^|||||||||||||||", ".@#$%&}^(]_{*[?|", ULONG_MAX / 2},
{8, "  -2AbC", "0123456789ABCDEF", 0},
{9, "   ..||||||||||||||||", ".@#$%&}^(]_{*[?|", ULONG_MAX},
{10, "++010101", "10", 0},
{11, " +010101", "10", 42},
{12, "+Jonathan", "ahnJto", 1089542},
{13, " XXX 4242", "XP", 0},
{0}
};

int	test_ft_atolu_base(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].str)
	{
		result(g_test[i].num,
			ft_atolu_base(g_test[i].str, g_test[i].base) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
