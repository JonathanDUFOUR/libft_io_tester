/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:27:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/19 09:38:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_colors.h"
#include "err_msg_lookup.h"

int	err_msg(int const err)
{
	int	i;

	i = 0;
	while (g_err_msg[i].msg && err != g_err_msg[i].err)
		++i;
	dprintf(2, RED "Error: %s\n" RESET, g_err_msg[i].msg);
	return (err);
}
