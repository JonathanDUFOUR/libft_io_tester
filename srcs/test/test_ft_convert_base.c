/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_convert_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:48:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/23 21:12:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	char const	*str;
	char const	*from;
	char const	*to;
	char const	*expect;
};

static t_test const		g_test[] = {
{1, "", "", "", NULL},
{2, "lala", "l", "dejavu", NULL},
{3, "value", "dejavu", "X", NULL},
{4, "baguette", "vin rouge", "fromage", NULL},
{5, "crusher", "shcr", "tsar bomBA", NULL},
{6, "delta", "gamma", "phi", NULL},
{7, "beta", "epsilon", "alpha", NULL},
{8, "-x-x-x", "x-", "01", NULL},
{9, "101010", "01", "o+", NULL},
{10, "    +Matthieu", "aMeutih", "9876543210", "097304"},
{11, "01111111111111111111111111111111", "10", "0123456789abcdef", "-80000000"},
{12, "\t \r-ppppopnnnAvif", "poneyvif", "01", "-1000010010010"},
{13, " \v\f+.!..!..!!!.!!..!", "!.", "0123456789ABCDEF", "B626"},
{14, "Jonathan", "koalA", "fruit", "f"},
{0}
};

int	test_ft_convert_base(int *const ret)
{
	int			i;
	char		*str;
	char const	*expect;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_convert_base(g_test[i].str, g_test[i].from, g_test[i].to);
		expect = g_test[i].expect;
		result(g_test[i].num,
			(!str && !expect) || (str && expect && !strcmp(str, expect)));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
