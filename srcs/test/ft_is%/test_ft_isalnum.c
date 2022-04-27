/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:08:49 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:28:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

int	test_ft_isalnum(int *const ret)
{
	int	c;

	printf("%20s:", __func__ + 5);
	c = CHAR_MIN;
	while (c < CHAR_MAX && !!ft_isalnum(c) == !!isalnum(c))
		++c;
	result(1, !!ft_isalnum(c) == !!isalnum(c));
	if (!!ft_isalnum(c) != !!isalnum(c))
		printf(" (%i)", c);
	printf("\n");
	return (*ret = SUCCESS);
}
