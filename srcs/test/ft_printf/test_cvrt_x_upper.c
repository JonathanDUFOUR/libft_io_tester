/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cvrt_x_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:09:06 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:29:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "t_int.h"
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	t_uint const	num;
	t_uint const	nb0;
	t_uint const	nb1;
	t_uint const	nb2;
};

static t_test const		g_test[] = {
{1, 0, 1, 2},
{2, 42, -42, 21},
{3, 123456, -4545, -0},
{4, 999, -999, 4},
{5, 100, -1000, 10},
{6, INT_MIN, INT_MAX, UINT_MAX},
{7, 987654321, 3164972850, 101010},
{0},
};

static int	call0(int const i, int const *fd, int *r, int *const ret)
{
	int	save;

	save = dup(STDOUT_FILENO);
	if (save == -1)
		return (*ret = DUP_ERR);
	if (close(STDOUT_FILENO) == -1)
		return (*ret = CLOSE_ERR);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (*ret = DUP2_ERR);
	r[0] = printf("First HEXA: %X| Second HEXA: %X| Third HEXA: %X",
			g_test[i].nb0, g_test[i].nb1, g_test[i].nb2);
	if (fflush(stdout))
		return (*ret = FFLUSH_ERR);
	if (dup2(save, STDOUT_FILENO) == -1)
		return (*ret = DUP2_ERR);
	if (close(save) == -1)
		return (*ret = CLOSE_ERR);
	return (*ret = SUCCESS);
}

static int	call1(int const i, int const *fd, int *r, int *const ret)
{
	int	save;

	save = dup(STDOUT_FILENO);
	if (save == -1)
		return (*ret = DUP_ERR);
	if (close(STDOUT_FILENO) == -1)
		return (*ret = CLOSE_ERR);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (*ret = DUP2_ERR);
	r[1] = ft_printf("First HEXA: %X| Second HEXA: %X| Third HEXA: %X",
			g_test[i].nb0, g_test[i].nb1, g_test[i].nb2);
	if (dup2(save, STDOUT_FILENO) == -1)
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
	if (fflush(stdout))
		return (*ret = FFLUSH_ERR);
	free(str[0]);
	free(str[1]);
	return (*ret = SUCCESS);
}

int	test_cvrt_x_upper(int const *fd, int *const ret)
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
