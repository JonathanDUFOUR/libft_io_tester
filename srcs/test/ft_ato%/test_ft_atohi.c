/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atohi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:38:14 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:27:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	char const		*str;
	t_hint const	expect;
};

static t_test const		g_test[] = {
{1, "", 0},
{2, "  ", 0},
{3, " -", 0},
{4, " + 2", 0},
{5, " abc", 0},
{6, "  --45", 0},
{7, "++58  ", 0},
{8, "-0000000", 0},
{9, "    -42-5", -42},
{10, " +0001639      1", 1639},
{11, "32767+42koala  ", SHRT_MAX},
{12, " -32768", SHRT_MIN},
{13, "-32779 -256", SHRT_MAX - 10},
{14, "0065540", 4},
{0}
};

int	test_ft_atohi(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		result(g_test[i].num,
			ft_atohi(g_test[i].str) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
