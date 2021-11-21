/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:16:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 18:24:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	int const	nb;
	char const	*base;
	char const	*expect;
};

static t_test const		g_test[] = {
{0, 42, "A", NULL},
{1, -21, "012-", NULL},
{2, 12, "01+2", NULL},
{3, -6, "012 345679", NULL},
{4, 100, "01234567890", NULL},
{5, -4996, "01", "-1001110000100"},
{6, 102030405, "poneyvif", "ipvoviopv"},
{7, INT_MAX, "0123456789abcdef", "7fffffff"},
{8, INT_MIN, "0123456789ABCDEF", "-80000000"},
{9, 0, "fruit", "f"},
{0}
};

int	test_ft_itoa_base(int *const ret)
{
	char const	*expect;
	char		*str;
	int			i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].base)
	{
		expect = g_test[i].expect;
		str = ft_itoa_base(g_test[i].nb, g_test[i].base);
		result(g_test[i].num,
			(!str && !expect) || (str && !strcmp(str, expect)));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
