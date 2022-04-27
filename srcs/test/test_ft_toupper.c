/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:02:19 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:32:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

int	test_ft_toupper(int *const ret)
{
	int	c;

	printf("%20s:", __func__ + 5);
	c = CHAR_MIN;
	while (c < CHAR_MAX && ft_toupper(c) == toupper(c))
		++c;
	result(1, ft_toupper(c) == toupper(c));
	if (ft_toupper(c) != toupper(c))
		printf(" (%i)", c);
	printf("\n");
	return (*ret = SUCCESS);
}
