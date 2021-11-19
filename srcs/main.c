/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:26:32 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/19 09:11:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_limits.h"
#include "test_lookup.h"
#include "enum/e_ret.h"

int	main(int const ac, char const **av)
{
	int	ret;
	int	i;
	int	j;

	if (ac == 1)
	{
		j = 0;
		while (g_test[j].fct && !g_test[j].fct(&ret))
			++j;
	}
	else
	{
		i = 1;
		while (av[i])
		{
			j = 0;
			while (g_test[j].fct)
			{
				if (!strcmp(av[i], g_test[j].name) && g_test[j].fct(&ret))
					;
				++j;
			}
			++i;
		}
	}
	return (SUCCESS);
}
