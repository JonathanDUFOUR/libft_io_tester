/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcano <bcano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:11:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 19:17:58 by bcano            ###   ########.fr       */
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
	unsigned const	test;
};

static t_test const		g_test[] = {
{0, 47},
{1, 48},
{2, 49},
{3, 50},
{4, 51},
{5, 52},
{6, 53},
{7, 54},
{8, 55},
{9, 56},
{10, 57},
{11, 58},
{12, -50},
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
			!!ft_isdigit(g_test[i].test) == !!isdigit(g_test[i].test));
		i++;
	}
	printf("\n");
	return (*ret = SUCCESS);
}

