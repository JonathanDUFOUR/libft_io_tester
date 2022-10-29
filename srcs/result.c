/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 04:22:33 by jodufour          #+#    #+#             */
/*   Updated: 2022/10/06 18:41:25 by jodufour         ###   ########.fr       */
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
