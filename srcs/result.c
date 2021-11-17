/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:50:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/17 02:50:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "colors.h"

void	result(int const num, int const res)
{
	if (res)
		printf(GREEN " %d.OK" RESET, num);
	else
		printf(RED " %d.KO" RESET, num);
}
