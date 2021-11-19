/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atohhu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:34:54 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/19 09:06:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "ft_limits.h"
#include "internal.h"
#include "enum/e_ret.h"

int	test_ft_atohhu(int *const ret)
{
	printf("%20s:", __func__ + 5);
	result(0, ft_atohhu("") == 0);
	result(1, ft_atohhu("  ") == 0);
	result(2, ft_atohhu(" -") == 0);
	result(3, ft_atohhu(" + 2") == 0);
	result(4, ft_atohhu(" abc") == 0);
	result(5, ft_atohhu("  --45") == 0);
	result(6, ft_atohhu("++58  ") == 0);
	result(7, ft_atohhu("    -42-5") == 0);
	result(8, ft_atohhu("-000000000") == 0);
	result(9, ft_atohhu(" +00021      1") == 21);
	result(10, ft_atohhu("+128 -256") == 128);
	result(11, ft_atohhu("255vb42 ") == g_hhuint_max);
	result(12, ft_atohhu("00456") == 200);
	printf("\n");
	return (*ret = SUCCESS);
}
