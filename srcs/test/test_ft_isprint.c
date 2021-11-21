/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcano <bcano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:12:30 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 19:28:36 by bcano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct	s_test
{
	int const	num;
	char const	*str;
};

static t_test const		g_test[] = {
{0, "hellØ"},
{1, "darksasuke"},
{2, "UPPERCASElowercase0123456789"},
{3, " "},
{4, "l'accent circonflexe se porte sur toutes les voyelles, sauf le y (â, ê, î, ô, û)"},
{4, "~"},
{0}
};


int	test_ft_isprint(int *const ret)
{
	int	i;
	int	l;
	int	res;
	int	expect;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].str)
	{
		res = 0;
		expect = 0;
		l = 0;
		while (g_test[i].str[l])
		{
			res = !!ft_isprint(g_test[i].str[l]);
			expect = !!isprint(g_test[i].str[l]);
			if (res != expect)
			{
				printf("%d, %d", res, expect);
				break ;
			}
			l++;
		}
		result(g_test[i].num, res == expect);
		i++;
	}
	printf("\n");
	return (*ret = SUCCESS);
}