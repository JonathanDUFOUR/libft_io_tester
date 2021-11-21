/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atohu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:40:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 10:10:16 by jodufour         ###   ########.fr       */
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
	t_huint const	expect;
};

static t_test const		g_test[] = {
{0, "", 0},
{1, "  ", 0},
{2, " -", 0},
{3, " + 2", 0},
{4, " abc", 0},
{5, "  --45", 0},
{6, "++58  ", 0},
{7, "    -42-5", 0},
{8, "000000+foobar", 0},
{9, " +00040421      1", 40421},
{10, "-32779 -256", 0},
{11, "     65535koala42", USHRT_MAX},
{12, "0065540", 4},
{0}
};

int	test_ft_atohu(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].str)
	{
		result(g_test[i].num,
			ft_atohu(g_test[i].str) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
