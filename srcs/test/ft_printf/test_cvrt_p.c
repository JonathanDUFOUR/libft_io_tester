/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cvrt_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:08:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/27 23:08:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enum/e_ret.h"

int	test_cvrt_p(int const *fd, int *const ret)
{
	(void)fd;
	return (*ret = SUCCESS);
}
