/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:41:53 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/19 05:55:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "internal.h"
#include "enum/e_ret.h"

int	test_ft_atoi_base(int *const ret)
{
	printf("%20s:", __func__ + 5);
	result(0, ft_atoi_base(NULL, NULL) == 0);
	printf("\n");
	return (*ret = SUCCESS);
}
