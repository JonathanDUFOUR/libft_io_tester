/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atohi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:38:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/19 09:07:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "ft_limits.h"
#include "internal.h"
#include "enum/e_ret.h"

int	test_ft_atohi(int *const ret)
{
	printf("%20s:", __func__ + 5);
	result(0, ft_atohi("") == 0);
	result(1, ft_atohi("  ") == 0);
	result(2, ft_atohi(" -") == 0);
	result(3, ft_atohi(" + 2") == 0);
	result(4, ft_atohi(" abc") == 0);
	result(5, ft_atohi("  --45") == 0);
	result(6, ft_atohi("++58  ") == 0);
	result(7, ft_atohi("-0000000") == 0);
	result(8, ft_atohi("    -42-5") == -42);
	result(9, ft_atohi(" +0001639      1") == 1639);
	result(10, ft_atohi("32767+42koala  ") == g_hint_max);
	result(11, ft_atohi(" -32768") == g_hint_min);
	result(12, ft_atohi("-32779 -256") == g_hint_max - 10);
	result(13, ft_atohi("0065540") == 4);
	printf("\n");
	return (*ret = SUCCESS);
}
