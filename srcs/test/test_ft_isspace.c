/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcano <bcano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:13:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 19:32:03 by bcano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct	s_test
{
	int const	num;
	unsigned long const	test;
};

static t_test const		g_test[] = {
{0, 6},
{1, 7},
{2, 8},
{3, 9},
{4, 10},
{5, 11},
{6, 12},
{7, 13},
{8, 14},
{9, 255},
{0}
};

int	test_ft_isspace(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].test)
	{
		result(g_test[i].num,
			!!ft_isspace(g_test[i].test) == !!isspace(g_test[i].test));
		i++;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
