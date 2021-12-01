/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cvrt_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:06:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/29 12:27:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	char const	c0;
	char const	c1;
	char const	c2;
};

static t_test const		g_test[] = {
{1, 6, 2, 6},
{2, 32, 48, 45},
{3, 42, 111, 99},
{4, 87, 102, 126},
{5, 0, 21, 55},
{6, 28, 77, 60},
{7, CHAR_MIN, -1, CHAR_MAX},
{0}
};

static int	call0(int const i, int const *fd, int *r, int *const ret)
{
	int	save;

	save = dup(1);
	if (save == -1)
		return (*ret = DUP_ERR);
	if (dup2(fd[1], 1) == -1)
		return (*ret = DUP2_ERR);
	r[0] = printf("First char: %c| Second char: %c| Third char: %c",
			g_test[i].c0, g_test[i].c1, g_test[i].c2);
	fflush(stdout);
	if (dup2(save, 1) == -1)
		return (*ret = DUP2_ERR);
	if (close(save) == -1)
		return (*ret = CLOSE_ERR);
	return (*ret = SUCCESS);
}

static int	call1(int const i, int const *fd, int *r, int *const ret)
{
	int	save;

	save = dup(1);
	if (save == -1)
		return (*ret = DUP_ERR);
	if (dup2(fd[1], 1) == -1)
		return (*ret = DUP2_ERR);
	r[1] = ft_printf("First char: %c| Second char: %c| Third char: %c",
			g_test[i].c0, g_test[i].c1, g_test[i].c2);
	if (dup2(save, 1) == -1)
		return (*ret = DUP2_ERR);
	if (close(save) == -1)
		return (*ret = CLOSE_ERR);
	return (*ret = SUCCESS);
}

static int	test_one(int const i, int const *fd, int *const ret)
{
	char	*str[2];
	int		r[2];

	str[0] = NULL;
	str[1] = NULL;
	if (call0(i, fd, r, ret))
		return (*ret);
	if (get_str(&str[0], fd, ret))
		return (*ret);
	if (call1(i, fd, r, ret))
		return (*ret);
	if (get_str(&str[1], fd, ret))
		return (*ret);
	result(g_test[i].num,
		r[0] == r[1] && ((!str[0] && !str[1]) || !strcmp(str[0], str[1])));
	fflush(stdout);
	free(str[0]);
	free(str[1]);
	return (*ret = SUCCESS);
}

int	test_cvrt_c(int const *fd, int *const ret)
{
	int	i;

	i = 0;
	while (g_test[i].num)
	{
		if (test_one(i, fd, ret))
			return (*ret);
		++i;
	}
	return (*ret = SUCCESS);
}
