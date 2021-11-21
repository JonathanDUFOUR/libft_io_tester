/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcano <bcano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:10:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 18:55:51 by bcano            ###   ########.fr       */
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
{0, -66},
{1, 128},
{2, 90},
{3, 2147483757},
{4, 120},
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
			ft_isascii(g_test[i].test) == isascii(g_test[i].test));
		i++;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
