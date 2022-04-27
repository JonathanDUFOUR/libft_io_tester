/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putbytes_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:33:03 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:30:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	char const		*addr;
	size_t const	size;
	char const		*expect;
};

static t_test const		g_test[] = {
{1, "", 0, ""},
{2, "\x00\x01\x02", 0, ""},
{3, "\x00\x01\x02", 3, "00000000 00000001 00000010"},
{4, "\x2a\xfe\xd2\x03", 4, "00101010 11111110 11010010 00000011"},
{5, "\xb5\x00\x10", 2, "10110101 00000000"},
{6, "\x10\x12\xaa\x0f\xf0", 5, "00010000 00010010 10101010 00001111 11110000"},
{7, "\xd8\xcc\x3e", 1, "11011000"},
{8, "\x15\x32", 2, "00010101 00110010"},
{9, "\x11\x22\x33\x44\x55\x66\x77", 7,
	"00010001 00100010 00110011 01000100 01010101 01100110 01110111"},
{0}
};

static int	test_one(int const i, int const *fd, int *const ret)
{
	char	*buff;
	size_t	len;

	len = strlen(g_test[i].expect);
	buff = malloc((len + 1) * sizeof(char));
	if (!buff)
		return (*ret = MALLOC_ERR);
	if (ft_putbytes_fd((void *)g_test[i].addr, g_test[i].size, fd[1]) == -1)
		return (*ret = FT_PUTBYTES_FD_ERR);
	buff[len] = 0;
	if (read(fd[0], buff, len) == -1)
	{
		free(buff);
		return (*ret = READ_ERR);
	}
	result(g_test[i].num, !strcmp(buff, g_test[i].expect));
	free(buff);
	return (*ret = SUCCESS);
}

int	test_ft_putbytes_fd(int *const ret)
{
	int	fd[2];
	int	i;

	if (pipe(fd) == -1)
		return (*ret = PIPE_ERR);
	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		if (test_one(i, fd, ret))
			return (*ret);
		++i;
	}
	printf("\n");
	if (close(fd[0]) == -1 || close(fd[1]) == -1)
		return (*ret = CLOSE_ERR);
	return (*ret = SUCCESS);
}
