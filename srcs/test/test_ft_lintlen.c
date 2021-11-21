/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lintlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:17:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 21:34:47 by jodufour         ###   ########.fr       */
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
	t_lint const	nb;
	t_uint const	expect;
};

static t_test const		g_test[] = {
{0, 0, 1},
{1, 42, 2},
{2, -55, 3},
{3, LONG_MAX, 19},
{4, LONG_MIN, 20},
{5, ULONG_MAX, 2},
{6, 10000, 5},
{7, -109, 4},
{0}
};

int	test_ft_lintlen(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].expect)
	{
		result(g_test[i].num,
			ft_lintlen(g_test[i].nb) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
