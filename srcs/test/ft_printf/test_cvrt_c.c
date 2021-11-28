/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cvrt_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:06:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/27 23:22:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enum/e_ret.h"

int	test_cvrt_c(int const *fd, int *const ret)
{
	(void)fd;
	return (*ret = SUCCESS);
}
