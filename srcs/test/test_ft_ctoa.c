/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_ctoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:49:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 11:07:56 by jodufour         ###   ########.fr       */
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
	char const	c;
	char const	*expect;
};

static t_test const		g_test[] = {
{0, 0, ""},
{1, ' ', " "},
{2, 'A', "A"},
{3, '\e', "\e"},
{4, '\t', "\t"},
{5, 'f', "f"},
{6, 't', "t"},
{0}
};

int	test_ft_ctoa(int *const ret)
{
	char	*str;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].expect)
	{
		str = ft_ctoa(g_test[i].c);
		result(g_test[i].num,
			str && !strcmp(str, g_test[i].expect));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
