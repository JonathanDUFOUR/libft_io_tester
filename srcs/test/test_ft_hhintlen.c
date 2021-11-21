/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_hhintlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:52:30 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 21:25:27 by jodufour         ###   ########.fr       */
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
	t_hhint const	nb;
	t_uint const	expect;
};

static t_test const		g_test[] = {
{0, 0, 1},
{1, 42, 2},
{2, -55, 3},
{3, CHAR_MAX, 3},
{4, CHAR_MIN, 4},
{5, UCHAR_MAX, 2},
{6, 100, 3},
{7, -109, 4},
{0}
};

int	test_ft_hhintlen(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].expect)
	{
		result(g_test[i].num,
			ft_hhintlen(g_test[i].nb) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
