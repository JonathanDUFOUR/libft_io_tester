/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_indexof.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:06:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/23 19:14:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	char const		c;
	char const		*str;
	ssize_t const	expect;
};

static t_test const		g_test[] = {
{1, 0, "", 0},
{2, 0, "Hello", 5},
{3, 'H', "World", -1},
{4, 'a', "Koala", 2},
{5, 'A', "KoalA", 4},
{6, '.', "forever young ! I want to be forever young...", 42},
{7, -1, "-1", -1},
{0}
};

int	test_ft_indexof(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		result(g_test[i].num,
			ft_indexof(g_test[i].c, g_test[i].str) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
