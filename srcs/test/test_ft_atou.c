/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atou.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:47:13 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/17 03:35:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "internal.h"
#include "enum/e_ret.h"

int	test_ft_atou(int *const ret)
{
	printf("%20s:", __func__ + 5);
	printf("\n");
	return (*ret = SUCCESS);
}
