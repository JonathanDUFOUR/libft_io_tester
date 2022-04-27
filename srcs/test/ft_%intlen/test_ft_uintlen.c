/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_uintlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:02:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:22:08 by jodufour         ###   ########.fr       */
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
	t_uint const	nb;
	t_uint const	expect;
};

static t_test const		g_test[] = {
{1, 0, 1},
{2, 42, 2},
{3, 9, 1},
{4, UINT_MAX, 10},
{5, 28, 2},
{6, 255, 3},
{7, 100, 3},
{8, 1, 1},
{0}
};

int	test_ft_uintlen(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		result(g_test[i].num,
			ft_uintlen(g_test[i].nb) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
