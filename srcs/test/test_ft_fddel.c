/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_fddel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:50:18 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/27 14:39:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

int	test_ft_fddel(int *const ret)
{
	int	fd[2];
	int	cpy;

	printf("%20s:", __func__ + 5);
	if (pipe(fd) == -1)
		return (PIPE_ERR);
	cpy = fd[0];
	if (ft_fddel(&fd[0]) == -1)
		return (*ret = FT_FDDEL_ERR);
	result(1,
		fd[0] == -1 && close(cpy) == -1);
	cpy = fd[1];
	if (ft_fddel(&fd[1]) == -1)
		return (*ret = FT_FDDEL_ERR);
	result(2,
		fd[1] == -1 && close(cpy) == -1 && errno == EBADF);
	printf("\n");
	return (*ret = SUCCESS);
}
