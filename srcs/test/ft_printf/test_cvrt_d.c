/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cvrt_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:08:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/27 23:07:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enum/e_ret.h"

int	test_cvrt_d(int const *fd, int *const ret)
{
	(void)fd;
	return (*ret = SUCCESS);
}
