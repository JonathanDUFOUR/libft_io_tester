/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atou.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:47:13 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:27:27 by jodufour         ###   ########.fr       */
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
	t_uint const	expect;
};

static t_test const		g_test[] = {
{1, "", 0},
{2, "  ", 0},
{3, " -", 0},
{4, " + 2", 0},
{5, " abc", 0},
{6, "  --45", 0},
{7, "++58  ", 0},
{8, "    -42-5", 0},
{9, "000000+foobar", 0},
{10, " +00040421595      1", 40421595},
{11, "-32779 -256", 0},
{12, "     4294967295koala42", UINT_MAX},
{13, "004294967300", 4},
{0}
};

int	test_ft_atou(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		result(g_test[i].num,
			ft_atou(g_test[i].str) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
