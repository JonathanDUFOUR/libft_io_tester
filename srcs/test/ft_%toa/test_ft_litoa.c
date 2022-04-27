/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_litoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:18:20 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:25:43 by jodufour         ###   ########.fr       */
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
	int const		num;
	t_lint const	nb;
	char const		*expect;
};

static t_test const		g_test[] = {
{1, 0, "0"},
{2, 1, "1"},
{3, -1, "-1"},
{4, 10220856142, "10220856142"},
{5, -300113297955, "-300113297955"},
{6, LONG_MAX, "9223372036854775807"},
{7, LONG_MIN, "-9223372036854775808"},
{8, ULONG_MAX, "-1"},
{0}
};

int	test_ft_litoa(int *const ret)
{
	char	*str;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_litoa(g_test[i].nb);
		result(g_test[i].num,
			str && !strcmp(str, g_test[i].expect));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
