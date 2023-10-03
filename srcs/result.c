/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 04:22:33 by jodufour          #+#    #+#             */
/*   Updated: 2023/10/03 04:21:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_colors.h"

void	result(int const num, int const res)
{
	if (res)
		printf(GREEN_FG " %d.OK" RESET, num);
	else
		printf(RED_FG " %d.KO" RESET, num);
}
