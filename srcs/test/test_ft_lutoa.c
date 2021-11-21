/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lutoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:27:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 12:08:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	t_luint const	nb;
	char const		*expect;
};

static t_test const		g_test[] = {
{0, 0, "0"},
{1, 1, "1"},
{2, 42, "42"},
{3, 10000000000000000000LU, "10000000000000000000"},
{4, 8461, "8461"},
{5, ULONG_MAX, "18446744073709551615"},
{6, -120, "18446744073709551496"},
{0}
};

int	test_ft_lutoa(int *const ret)
{
	char	*str;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].expect)
	{
		str = ft_lutoa(g_test[i].nb);
		result(g_test[i].num,
			str && !strcmp(str, g_test[i].expect));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
