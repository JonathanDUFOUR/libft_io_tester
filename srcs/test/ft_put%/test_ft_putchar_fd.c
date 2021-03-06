/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:34:02 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:30:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

int	test_ft_putchar_fd(int *const ret)
{
	char	c;
	char	buff[1];
	int		fd[2];

	printf("%20s:", __func__ + 5);
	if (pipe(fd) == -1)
		return (*ret = PIPE_ERR);
	c = CHAR_MIN;
	if (ft_putchar_fd(c, fd[1]) == -1)
		return (*ret = FT_PUTCHAR_FD_ERR);
	if (read(fd[0], buff, 1) == -1)
		return (*ret = READ_ERR);
	while (c < CHAR_MAX && c == *buff)
	{
		++c;
		if (ft_putchar_fd(c, fd[1]) == -1)
			return (*ret = FT_PUTCHAR_FD_ERR);
		if (read(fd[0], buff, 1) == -1)
			return (*ret = READ_ERR);
	}
	result(1, *buff == c);
	printf("\n");
	if (close(fd[0]) == -1 || close(fd[1]) == -1)
		return (*ret = CLOSE_ERR);
	return (*ret = SUCCESS);
}
