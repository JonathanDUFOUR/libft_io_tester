/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_ftoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 09:24:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/01 10:29:50 by jodufour         ###   ########.fr       */
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
	float const		nb;
	t_uint const	prec;
	char const		*expect;
};

static t_test const		g_test[] = {
{1, 0.0f, 0, "0"},
{2, 1.0f, 1, "1.0"},
{3, -321.123f, 2, "-321.12"},
{4, 97.42f, 3, "97.419"},
{5, 0.0f / 0.0f, 0, "nan"},
{6, 1.0f / 0.0f, 21, "inf"},
{7, -1.0f / 0.0f, 42, "-inf"},
{8, 4056.1384f, 6, "4056.138427"},
{0}
};

int	test_ft_ftoa(int *const ret)
{
	char	*str;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_ftoa(g_test[i].nb, g_test[i].prec);
		result(g_test[i].num,
			str && !strcmp(str, g_test[i].expect));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
