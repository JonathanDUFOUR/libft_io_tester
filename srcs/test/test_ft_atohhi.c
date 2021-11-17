/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atohhi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:34:31 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/17 04:01:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "internal.h"
#include "enum/e_ret.h"

int	test_ft_atohhi(int *const ret)
{
	printf("%20s:", __func__ + 5);
	result(0, ft_atohhi("") == 0);
	result(1, ft_atohhi("  ") == 0);
	result(2, ft_atohhi(" -") == 0);
	result(3, ft_atohhi(" + 2") == 0);
	result(4, ft_atohhi(" abc") == 0);
	result(5, ft_atohhi("  --45") == 0);
	result(6, ft_atohhi("++58  ") == 0);
	result(7, ft_atohhi("    -42-5") == -42);
	result(8, ft_atohhi(" +00021      1") == 21);
	result(9, ft_atohhi("+128 -256") == -128);
	result(10, ft_atohhi("00456") == -56);
	printf("\n");
	return (*ret = SUCCESS);
}
