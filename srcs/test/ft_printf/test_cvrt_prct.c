/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cvrt_prct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:08:53 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:16:05 by jodufour         ###   ########.fr       */
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
	int const	num;
	char const	*format;
};

static t_test const		g_test[] = {
{1, ""},
{2, "%%"},
{3, "%% "},
{4, " %%"},
{5, " %% "},
{6, "%%%%%%"},
{7, "%%%"},
{0}
};

static int	call0(int const i, int const *fd, int *const r, int *const ret)
{
	int	save;

	save = dup(STDOUT_FILENO);
	if (save == -1)
		return (*ret = DUP_ERR);
	if (close(STDOUT_FILENO) == -1)
		return (*ret = CLOSE_ERR);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (*ret = DUP2_ERR);
	r[0] = printf(g_test[i].format);
	if (fflush(stdout))
		return (*ret = FFLUSH_ERR);
	if (write(STDOUT_FILENO, "\n", 1) == -1)
		return (*ret = WRITE_ERR);
	if (dup2(save, STDOUT_FILENO) == -1)
		return (*ret = DUP2_ERR);
	if (close(save) == -1)
		return (*ret = CLOSE_ERR);
	return (*ret = SUCCESS);
}

static int	call1(int const i, int const *fd, int *const r, int *const ret)
{
	int	save;

	save = dup(STDOUT_FILENO);
	if (save == -1)
		return (*ret = DUP_ERR);
	if (close(STDOUT_FILENO) == -1)
		return (*ret = CLOSE_ERR);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (*ret = DUP2_ERR);
	r[1] = ft_printf(g_test[i].format);
	if (write(STDOUT_FILENO, "\n", 1) == -1)
		return (*ret = WRITE_ERR);
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

int	test_cvrt_prct(int const *fd, int *const ret)
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
