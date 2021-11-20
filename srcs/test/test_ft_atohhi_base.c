/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atohhi_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:20:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/20 10:33:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "internal.h"
#include "enum/e_ret.h"

int	test_ft_atohhi_base(int *const ret)
{
	printf("%20s:", __func__ + 5);
	result(0, ft_atohhi_base("42", "") == 0);
	result(1, ft_atohhi_base("21", "+0123456789") == 0);
	result(2, ft_atohhi_base("101010", "01-") == 0);
	result(3, ft_atohhi_base("fee", "poney vif") == 0);
	result(4, ft_atohhi_base("  -aa", "a") == 0);
	result(5, ft_atohhi_base("ABBA  ", "BAOBAB") == 0);
	result(6, ft_atohhi_base("ABBA  ", "BA") == 9);
	result(7, ft_atohhi_base("+|||||.......", "|.") == 127);
	result(8, ft_atohhi_base("  -2AbC", "0123456789ABCDEF") == -42);
	printf("\n");
	return (*ret = SUCCESS);
}
