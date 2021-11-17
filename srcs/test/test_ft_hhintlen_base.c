/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_hhintlen_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:53:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/17 03:35:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "internal.h"
#include "enum/e_ret.h"

int	test_ft_hhintlen_base(int *const ret)
{
	printf("%20s:", __func__ + 5);
	printf("\n");
	return (*ret = SUCCESS);
}
