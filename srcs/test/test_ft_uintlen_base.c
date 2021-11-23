/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_uintlen_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:03:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/23 02:15:07 by jodufour         ###   ########.fr       */
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
	t_uint const	nb;
	t_uint const	len;
	t_uint const	expect;
};

static t_test const		g_test[] = {
{1, 42, 0, 0},
{2, 21, 1, 0},
{3, 0, 2, 1},
{4, 9, 10, 1},
{6, 81235497, 5, 12},
{5, 371571132, 16, 8},
{7, INT_MAX, 2, 31},
{8, UINT_MAX, 12, 9},
{0}
};

int	test_ft_uintlen_base(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		result(g_test[i].num,
			ft_uintlen_base(g_test[i].nb, g_test[i].len) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}

