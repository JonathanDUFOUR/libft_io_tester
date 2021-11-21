/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcano <bcano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:10:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 18:02:09 by bcano            ###   ########.fr       */
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
{0, -66, 0},
{1, 128, 0},
{2, 90, 1},
{3, 2147483757, 0},
{4, 120, 1},
{0}
};


int	test_ft_isascii(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].test)
	{
		result(g_test[i].num,
			ft_isascii(g_test[i].test) == g_test[i].expect);
		i++;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
