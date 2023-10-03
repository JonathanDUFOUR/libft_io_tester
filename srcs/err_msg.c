/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:27:02 by jodufour          #+#    #+#             */
/*   Updated: 2023/10/03 06:32:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_colors.h"
#include "lookup_err_msg.h"

int	err_msg(int const err)
{
	int	i;

	i = 0;
	while (g_err_msg[i].msg && err != g_err_msg[i].err)
		++i;
	dprintf(2, RED_FG "Error: %s\n" RESET, g_err_msg[i].msg);
	return (err);
}
