/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atohi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:38:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 10:08:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	char const		*str;
	t_hint const	expect;
};

static t_test const		g_test[] = {
{0, "", 0},
{1, "  ", 0},
{2, " -", 0},
{3, " + 2", 0},
{4, " abc", 0},
{5, "  --45", 0},
{6, "++58  ", 0},
{7, "-0000000", 0},
{8, "    -42-5", -42},
{9, " +0001639      1", 1639},
{10, "32767+42koala  ", SHRT_MAX},
{11, " -32768", SHRT_MIN},
{12, "-32779 -256", SHRT_MAX - 10},
{13, "0065540", 4},
{0}
};

int	test_ft_atohi(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].str)
	{
		result(g_test[i].num,
			ft_atohi(g_test[i].str) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
