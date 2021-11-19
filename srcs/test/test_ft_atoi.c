/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:59:53 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/19 09:12:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "ft_limits.h"
#include "internal.h"
#include "enum/e_ret.h"

int	test_ft_atoi(int *const ret)
{
	printf("%20s:", __func__ + 5);
	result(0, ft_atoi("") == 0);
	result(1, ft_atoi("  ") == 0);
	result(2, ft_atoi(" -") == 0);
	result(3, ft_atoi(" + 2") == 0);
	result(4, ft_atoi(" abc") == 0);
	result(5, ft_atoi("  --45") == 0);
	result(6, ft_atoi("++58  ") == 0);
	result(7, ft_atoi("-0000000") == 0);
	result(8, ft_atoi("    -42-5") == -42);
	result(9, ft_atoi(" +0001639      1") == 1639);
	result(10, ft_atoi("2147483647+42koala  ") == g_int_max);
	result(11, ft_atoi(" -2147483648") == g_int_min);
	result(12, ft_atoi("-2147483669 -256") == g_int_max - 20);
	result(13, ft_atoi("004294967296") == 0);
	printf("\n");
	return (*ret = SUCCESS);
}
