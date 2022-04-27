/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_llutoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:24:50 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:26:03 by jodufour         ###   ########.fr       */
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
	t_lluint const	nb;
	char const		*expect;
};

static t_test const		g_test[] = {
{1, 0, "0"},
{2, 1, "1"},
{3, 42, "42"},
{4, 10000000000000000000LLU, "10000000000000000000"},
{5, 8461, "8461"},
{6, ULONG_MAX, "18446744073709551615"},
{7, -120, "18446744073709551496"},
{0}
};

int	test_ft_llutoa(int *const ret)
{
	char	*str;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_llutoa(g_test[i].nb);
		result(g_test[i].num,
			str && !strcmp(str, g_test[i].expect));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
