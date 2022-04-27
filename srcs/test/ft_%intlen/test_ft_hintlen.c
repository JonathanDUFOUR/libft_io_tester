/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_hintlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:59:48 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:21:31 by jodufour         ###   ########.fr       */
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
	t_hint const	nb;
	t_uint const	expect;
};

static t_test const		g_test[] = {
{1, 0, 1},
{2, 42, 2},
{3, -55, 3},
{4, SHRT_MAX, 5},
{5, SHRT_MIN, 6},
{6, (t_hint)USHRT_MAX, 2},
{7, 100, 3},
{8, -109, 4},
{0}
};

int	test_ft_hintlen(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		result(g_test[i].num,
			ft_hintlen(g_test[i].nb) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
