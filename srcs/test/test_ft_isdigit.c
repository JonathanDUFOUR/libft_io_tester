/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcano <bcano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:11:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 18:02:49 by bcano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct	s_test
{
	int const	num;
	unsigned const	test;
	int const	expect;
};

static t_test const		g_test[] = {
{0, 47, 0},
{1, 48, 1},
{2, 49, 1},
{3, 50, 1},
{4, 51, 1},
{5, 52, 1},
{6, 53, 1},
{7, 54, 1},
{8, 55, 1},
{9, 56, 1},
{10, 57, 1},
{11, 58, 0},
{12, -50, 0},
{0}
};

int		test_ft_isdigit(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].test)
	{
		result(g_test[i].num,
			ft_isdigit(g_test[i].test) == g_test[i].expect);
		i++;
	}
	printf("\n");
	return (*ret = SUCCESS);
}

