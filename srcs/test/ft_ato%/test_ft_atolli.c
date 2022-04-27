/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atolli.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:44:38 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:27:16 by jodufour         ###   ########.fr       */
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
	t_lint const	expect;
};

static t_test const		g_test[] = {
{1, "", 0},
{2, "  ", 0},
{3, " -", 0},
{4, " + 2", 0},
{5, " abc", 0},
{6, "  --45", 0},
{7, "++58  ", 0},
{8, "-0000000", 0},
{9, "    -42-5", -42},
{10, " +0001639      1", 1639},
{11, "9223372036854775807+42koala  ", LONG_MAX},
{12, " -9223372036854775808", LONG_MIN},
{13, "-9223372036854775829 -256", LONG_MAX - 20},
{14, "0018446744073709551616", 0},
{0}
};

int	test_ft_atolli(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		result(g_test[i].num,
			ft_atolli(g_test[i].str) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
