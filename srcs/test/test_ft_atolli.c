/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atolli.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:44:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 10:15:35 by jodufour         ###   ########.fr       */
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
	t_lint const	expect;
};

static t_test const		g_test[] = {
{0, "", 0},
{1, "  ", 0},
{2, " -", 0},
{3, " + 2", 0},
{4, " abc", 0},
{5, "  --45", 0},
{6, "++58  ", 0},
{7, "-0000000", 0},
{8, "    -42-5", -42},
{9, " +0001639      1", 1639},
{10, "9223372036854775807+42koala  ", LONG_MAX},
{11, " -9223372036854775808", LONG_MIN},
{12, "-9223372036854775829 -256", LONG_MAX - 20},
{13, "0018446744073709551616", 0},
{0}
};

int	test_ft_atolli(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].str)
	{
		result(g_test[i].num,
			ft_atolli(g_test[i].str) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
