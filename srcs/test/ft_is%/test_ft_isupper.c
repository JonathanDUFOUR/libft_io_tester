/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:13:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/23 00:23:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

int	test_ft_isupper(int *const ret)
{
	int	c;

	printf("%20s:", __func__ + 5);
	c = CHAR_MIN;
	while (c < CHAR_MAX && !!ft_isupper(c) == !!isupper(c))
		++c;
	result(1, !!ft_isupper(c) == !!isupper(c));
	if (!!ft_isupper(c) != !!isupper(c))
		printf(" (%i)", c);
	printf("\n");
	return (*ret = SUCCESS);
}
