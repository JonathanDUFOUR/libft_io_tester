/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putllint_base_fd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:51:57 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:32:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	t_llint const	nb;
	char const		*base;
	char const		*expect;
};

static t_test const		g_test[] = {
{1, 0, "", NULL},
{2, 1, "ft ", NULL},
{3, -1, "0-", NULL},
{4, -103, "1+", NULL},
{5, 89, "f\t", NULL},
{6, -69, "ABBA", NULL},
{7, 192837465564738291, "01",
	"1010101101000110001010011100111010010111110111001011110011"},
{8, -918273645546372819, "o_O", "-Ooo_oo__OOOOOoo__o__O_ooooO_o_OOoOo_oo"},
{9, LONG_MAX, "poneyvif", "fffffffffffffffffffff"},
{10, LONG_MIN, "0123456789abcdef", "-8000000000000000"},
{11, ULONG_MAX, "@#$", "-#"},
{12, 0, "fruit", "f"},
{0}
};

static int	test_valid(int const i, int const *fd, int *const ret)
{
	char	*buff;
	size_t	len;
	ssize_t	rd;

	len = strlen(g_test[i].expect);
	buff = malloc((len + 1) * sizeof(char));
	if (!buff)
		return (*ret = MALLOC_ERR);
	if (ft_putllint_base_fd(g_test[i].nb, g_test[i].base, fd[1]) == -1)
		return (*ret = FT_PUTLLINT_BASE_FD_ERR);
	rd = read(fd[0], buff, len);
	if (rd == -1)
	{
		free(buff);
		return (*ret = READ_ERR);
	}
	buff[rd] = 0;
	result(g_test[i].num,
		!strcmp(buff, g_test[i].expect));
	free(buff);
	return (*ret = SUCCESS);
}

static int	test_invalid(int const i, int const *fd, int *const ret)
{
	char	buff[4096];
	int		ft_ret;
	ssize_t	rd;

	if (write(fd[1], "", 1) == -1)
		return (WRITE_ERR);
	ft_ret = ft_putllint_base_fd(g_test[i].nb, g_test[i].base, fd[1]);
	rd = read(fd[0], buff, 4096);
	if (rd == -1)
		return (*ret = READ_ERR);
	result(g_test[i].num,
		ft_ret == -1 && rd == 1);
	return (*ret = SUCCESS);
}

int	test_ft_putllint_base_fd(int *const ret)
{
	int	fd[2];
	int	i;

	if (pipe(fd) == -1)
		return (*ret = PIPE_ERR);
	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		if ((g_test[i].expect && test_valid(i, fd, ret))
			|| (!g_test[i].expect && test_invalid(i, fd, ret)))
			return (*ret);
		++i;
	}
	printf("\n");
	if (close(fd[0]) == -1 || close(fd[1]) == -1)
		return (*ret = CLOSE_ERR);
	return (*ret = SUCCESS);
}
