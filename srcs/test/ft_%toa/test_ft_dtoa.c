/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_dtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 10:57:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/01 11:07:54 by jodufour         ###   ########.fr       */
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
	double const	nb;
	t_uint const	prec;
	char const		*expect;
};

static t_test const		g_test[] = {
{1, 0.0, 0, "0"},
{2, 1.0, 1, "1.0"},
{3, -321.123, 2, "-321.12"},
{4, 97.42, 3, "97.420"},
{5, 0.0 / 0.0, 0, "nan"},
{6, 1.0 / 0.0, 21, "inf"},
{7, -1.0 / 0.0, 42, "-inf"},
{8, 4056.1384, 6, "4056.138399"},
{0}
};

int	test_ft_dtoa(int *const ret)
{
	char	*str;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_dtoa(g_test[i].nb, g_test[i].prec);
		result(g_test[i].num,
			str && !strcmp(str, g_test[i].expect));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
