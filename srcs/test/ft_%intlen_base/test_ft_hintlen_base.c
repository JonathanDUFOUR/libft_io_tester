/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_hintlen_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:00:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/23 01:17:36 by jodufour         ###   ########.fr       */
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
	t_hint const	nb;
	t_uint const	len;
	t_uint const	expect;
};

static t_test const		g_test[] = {
{1, 42, 0, 0},
{2, 21, 1, 0},
{3, 0, 2, 1},
{4, 8192, 10, 4},
{5, -531, 5, 5},
{6, SHRT_MIN, 16, 5},
{7, SHRT_MAX, 2, 15},
{8, (t_hint)USHRT_MAX, 12, 2},
{0}
};

int	test_ft_hintlen_base(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		result(g_test[i].num,
			ft_hintlen_base(g_test[i].nb, g_test[i].len) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
