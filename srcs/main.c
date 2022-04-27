/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:26:32 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:33:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "tester.h"
#include "lookup_test.h"
#include "e_ret.h"

static int	every_tests(int *const ret)
{
	int	i;

	i = 0;
	while (g_test[i].fct)
	{
		if (g_test[i].fct(ret))
			return (*ret);
		++i;
	}
	return (*ret = SUCCESS);
}

static int	specific_tests(char const **av, int *const ret)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (g_test[j].fct)
		{
			if (!strcmp(av[i], g_test[j].name) && g_test[j].fct(ret))
				return (*ret);
			++j;
		}
		++i;
	}
	return (*ret = SUCCESS);
}

int	main(int const ac, char const **av)
{
	int	ret;

	if (ac == 1)
	{
		if (every_tests(&ret))
			return (err_msg(ret));
	}
	else
	{
		if (specific_tests(av, &ret))
			return (err_msg(ret));
	}
	return (SUCCESS);
}
