/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:01:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/23 02:47:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

int	test_ft_tolower(int *const ret)
{
	int	c;

	printf("%20s:", __func__ + 5);
	c = CHAR_MIN;
	while (c < CHAR_MAX && ft_tolower(c) == tolower(c))
		++c;
	result(1, ft_tolower(c) == tolower(c));
	if (ft_tolower(c) != tolower(c))
		printf(" (%i)", c);
	printf("\n");
	return (*ret = SUCCESS);
}
