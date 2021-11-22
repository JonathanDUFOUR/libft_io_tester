/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_hitoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:02:20 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/22 17:56:08 by jodufour         ###   ########.fr       */
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
	int const		num;
	t_hint const	nb;
	char const		*base;
	char const		*expect;
};

static t_test const		g_test[] = {
{1, 42, "A", NULL},
{2, -21, "012-", NULL},
{3, 12, "01+2", NULL},
{4, -6, "012 345679", NULL},
{5, 100, "01234567890", NULL},
{6, -900, "01", "-1110000100"},
{7, 10203, "poneyvif", "nefee"},
{8, SHRT_MAX, "0123456789abcdef", "7fff"},
{9, SHRT_MIN, "0123456789ABCDEF", "-8000"},
{10, 0, "fruit", "f"},
{0}
};

int	test_ft_hitoa_base(int *const ret)
{
	char const	*expect;
	char		*str;
	int			i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		expect = g_test[i].expect;
		str = ft_hitoa_base(g_test[i].nb, g_test[i].base);
		result(g_test[i].num,
			(!str && !expect) || (str && !strcmp(str, expect)));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
