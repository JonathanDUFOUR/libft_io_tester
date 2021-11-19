/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atohu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:40:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/19 09:16:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "ft_limits.h"
#include "internal.h"
#include "enum/e_ret.h"

int	test_ft_atohu(int *const ret)
{
	printf("%20s:", __func__ + 5);
	result(0, ft_atohu("") == 0);
	result(1, ft_atohu("  ") == 0);
	result(2, ft_atohu(" -") == 0);
	result(3, ft_atohu(" + 2") == 0);
	result(4, ft_atohu(" abc") == 0);
	result(5, ft_atohu("  --45") == 0);
	result(6, ft_atohu("++58  ") == 0);
	result(7, ft_atohu("    -42-5") == 0);
	result(8, ft_atohu("000000+foobar") == 0);
	result(9, ft_atohu(" +00040421      1") == 40421);
	result(10, ft_atohu("-32779 -256") == 0);
	result(11, ft_atohu("     65535koala42") == g_huint_max);
	result(12, ft_atohu("0065540") == 4);
	printf("\n");
	return (*ret = SUCCESS);
}
