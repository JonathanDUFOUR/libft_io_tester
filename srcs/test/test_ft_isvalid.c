/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isvalid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:14:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/23 18:53:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	char const	*base;
	bool const	expect;
};

static t_test const		g_test[] = {
{1, "", false},
{2, "a", false},
{3, "aba", false},
{4, "abc ", false},
{5, "abcd+", false},
{6, "-efghi", false},
{7, "\t0123456789", false},
{8, "0123456789ABCDEF", true},
{9, "poneyvif", true},
{10, "!@#$%^&*", true},
{11, "01", true},
{0}
};

int	test_ft_isvalid(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		result(g_test[i].num,
			ft_isvalid(g_test[i].base) == g_test[i].expect);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
