/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:02:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/22 22:21:22 by jodufour         ###   ########.fr       */
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
{1, "hello"},
{2, "darksasuke"},
{3, "UPPERCASElowercase0123456789"},
{4, " "},
{5, "UPPERCASE"},
{6, "lowercase"},
{7, ""},
{0}
};


int	test_ft_toupper(int *const ret)
{
	int	i;
	int	j;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		j = 0;
		while (g_test[i].str[j])
		{
			if (!!ft_toupper(g_test[i].str[j]) != !!toupper(g_test[i].str[j]))
				break ;
			j++;
		}
		result(g_test[i].num,
			!!ft_toupper(g_test[i].str[j]) == !!toupper(g_test[i].str[j]));
		i++;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
