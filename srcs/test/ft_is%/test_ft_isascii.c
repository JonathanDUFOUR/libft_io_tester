/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:10:23 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:28:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

int	test_ft_isascii(int *const ret)
{
	int	c;

	printf("%20s:", __func__ + 5);
	c = CHAR_MIN;
	while (c < CHAR_MAX && !!ft_isascii(c) == !!isascii(c))
		++c;
	result(1, !!ft_isascii(c) == !!isascii(c));
	if (!!ft_isascii(c) != !!isascii(c))
		printf(" (%i)", c);
	printf("\n");
	return (*ret = SUCCESS);
}
