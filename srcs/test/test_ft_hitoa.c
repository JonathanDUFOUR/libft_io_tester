/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_hitoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:01:18 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 11:29:10 by jodufour         ###   ########.fr       */
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
	t_hint const	nb;
	char const		*expect;
};

static t_test const		g_test[] = {
{0, 0, "0"},
{1, 1, "1"},
{2, -1, "-1"},
{3, 561, "561"},
{4, -1132, "-1132"},
{5, SHRT_MAX, "32767"},
{6, SHRT_MIN, "-32768"},
{7, (t_hint)32794, "-32742"},
{0}
};

int	test_ft_hitoa(int *const ret)
{
	char	*str;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].expect)
	{
		str = ft_hitoa(g_test[i].nb);
		result(g_test[i].num,
			str && !strcmp(str, g_test[i].expect));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
