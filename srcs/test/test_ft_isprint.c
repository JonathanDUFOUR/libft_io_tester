/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:12:30 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/24 08:21:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

int	test_ft_isprint(int *const ret)
{
	int	c;

	printf("%20s:", __func__ + 5);
	c = CHAR_MIN;
	while (c < CHAR_MAX && !!ft_isprint(c) == !!isprint(c))
		++c;
	result(1, !!ft_isprint(c) == !!isprint(c));
	if (!!ft_isprint(c) != !!isprint(c))
		printf(" (%i)", c);
	printf("\n");
	return (*ret = SUCCESS);
}
