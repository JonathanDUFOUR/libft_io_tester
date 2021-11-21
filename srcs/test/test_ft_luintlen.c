/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_luintlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:26:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 21:38:17 by jodufour         ###   ########.fr       */
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
	t_luint const	nb;
	t_uint const	expect;
};

static t_test const		g_test[] = {
{0, 0, 1},
{1, 42, 2},
{2, 9, 1},
{3, ULONG_MAX, 20},
{4, 28, 2},
{5, 255, 3},
{6, 100, 3},
{7, 1, 1},
{0}
};

int	test_ft_luintlen(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].expect)
	{
		result(g_test[i].num,
			ft_luintlen(g_test[i].nb) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
