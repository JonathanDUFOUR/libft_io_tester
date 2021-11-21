/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcano <bcano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:09:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 23:22:42 by bcano            ###   ########.fr       */
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
{0, "hello"},
{1, "Darksasuke99"},
{2, "UPPERCASElowercase"},
{3, " "},
{4, "Hello world!"},
{5, ""},
{0}
};


int	test_ft_isalpha(int *const ret)
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
			res = !!ft_isalpha(g_test[i].str[l]);
			expect = !!isalpha(g_test[i].str[l]);
			if (res != expect)
				break ;
			l++;
		}
		result(g_test[i].num, res == expect);
		i++;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
