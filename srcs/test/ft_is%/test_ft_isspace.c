/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:13:02 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:28:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

int	test_ft_isspace(int *const ret)
{
	int	c;

	printf("%20s:", __func__ + 5);
	c = CHAR_MIN;
	while (c < CHAR_MAX && !!ft_isspace(c) == !!isspace(c))
		++c;
	result(1, !!ft_isspace(c) == !!isspace(c));
	if (!!ft_isspace(c) != !!isspace(c))
		printf(" (%i)", c);
	printf("\n");
	return (*ret = SUCCESS);
}
