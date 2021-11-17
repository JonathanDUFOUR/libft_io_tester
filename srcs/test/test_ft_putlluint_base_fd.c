/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putlluint_base_fd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:53:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/17 03:47:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "internal.h"
#include "enum/e_ret.h"

int	test_ft_putlluint_base_fd(int *const ret)
{
	printf("%20s:", __func__ + 5);
	printf("\n");
	return (*ret = SUCCESS);
}
