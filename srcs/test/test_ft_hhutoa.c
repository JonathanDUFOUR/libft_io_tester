/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_hhutoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:58:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 11:16:10 by jodufour         ###   ########.fr       */
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
	t_hhuint const	nb;
	char const		*expect;
};

static t_test const		g_test[] = {
{0, 0, "0"},
{1, 1, "1"},
{2, 42, "42"},
{3, 97, "97"},
{4, 150, "150"},
{5, UCHAR_MAX, "255"},
{6, -120, "136"},
{0}
};

int	test_ft_hhutoa(int *const ret)
{
	char	*str;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].expect)
	{
		str = ft_hhutoa(g_test[i].nb);
		result(g_test[i].num,
			str && !strcmp(str, g_test[i].expect));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
