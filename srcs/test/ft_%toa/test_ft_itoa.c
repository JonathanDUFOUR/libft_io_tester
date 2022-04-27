/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:15:32 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:25:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	int const	nb;
	char const	*expect;
};

static t_test const		g_test[] = {
{1, 0, "0"},
{2, 1, "1"},
{3, -1, "-1"},
{4, 102208561, "102208561"},
{5, -3001132, "-3001132"},
{6, INT_MAX, "2147483647"},
{7, INT_MIN, "-2147483648"},
{8, UINT_MAX, "-1"},
{0}
};

int	test_ft_itoa(int *const ret)
{
	char	*str;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_itoa(g_test[i].nb);
		result(g_test[i].num,
			str && !strcmp(str, g_test[i].expect));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
