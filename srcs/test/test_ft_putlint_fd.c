/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putlint_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:51:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/26 01:12:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	t_lint const	nb;
	char const		*expect;
};

static t_test const		g_test[] = {
{1, 0, "0"},
{2, 42, "42"},
{3, -119922883377446655, "-119922883377446655"},
{4, 991188227733664455, "991188227733664455"},
{5, -89, "-89"},
{6, 69, "69"},
{7, LONG_MAX, "9223372036854775807"},
{8, LONG_MIN, "-9223372036854775808"},
{9, ULONG_MAX, "-1"},
{0}
};

static int	test_one(int const i, int const *fd, int *const ret)
{
	char	*buff;
	size_t	len;
	ssize_t	rd;

	len = strlen(g_test[i].expect);
	buff = malloc((len + 1) * sizeof(char));
	if (!buff)
		return (*ret = MALLOC_ERR);
	if (ft_putlint_fd(g_test[i].nb, fd[1]) == -1)
		return (*ret = FT_PUTLINT_FD_ERR);
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

int	test_ft_putlint_fd(int *const ret)
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
