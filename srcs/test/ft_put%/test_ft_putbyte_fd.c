/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putbyte_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:32:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/25 22:39:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	uint8_t const	byte;
	char const		*expect;
};

static t_test const		g_test[] = {
{1, 0b00000000, "00000000"},
{2, 0b11111111, "11111111"},
{3, 0b10101010, "10101010"},
{4, 0b00000010, "00000010"},
{5, 0b00000001, "00000001"},
{6, 0b10000000, "10000000"},
{7, 0b10000001, "10000001"},
{8, 0b11111110, "11111110"},
{9, 0b01111111, "01111111"},
{0}
};

int	test_ft_putbyte_fd(int *const ret)
{
	char	buff[9];
	int		fd[2];
	int		i;

	if (pipe(fd) == -1)
		return (*ret = PIPE_ERR);
	printf("%20s:", __func__ + 5);
	buff[8] = 0;
	i = 0;
	while (g_test[i].num)
	{
		if (ft_putbyte_fd(g_test[i].byte, fd[1]) == -1)
			return (*ret = FT_PUTBYTE_FD_ERR);
		if (read(fd[0], buff, 8) == -1)
			return (*ret = READ_ERR);
		result(g_test[i].num,
			!strcmp(buff, g_test[i].expect));
		++i;
	}
	printf("\n");
	if (close(fd[0]) == -1 || close(fd[1]) == -1)
		return (*ret = CLOSE_ERR);
	return (*ret = SUCCESS);
}
