/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:06:17 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:32:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

int	test_get_next_line(int *const ret)
{
	printf("%20s:", __func__ + 5);
	printf("\n");
	return (*ret = SUCCESS);
}
