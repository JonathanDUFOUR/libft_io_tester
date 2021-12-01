/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cvrt_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:08:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/29 12:39:07 by jodufour         ###   ########.fr       */
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
	void const	*p0;
	void const	*p1;
	void const	*p2;
};

static t_test const		g_test[] = {
{1, (void const *)0x0, (void const *)0x151515, (void const *)0x32aa},
{2, (void const *)0xffeeddcc, (void const *)0x1, (void const *)0x123456789},
{3, (void const *)0xabcde, (void const *)&printf, (void const *)&write},
{4, (void const *)ULONG_MAX, (void const *)LONG_MIN, (void const *)LONG_MAX},
{5, (void const *)&dup, (void const *)&dup2, (void const *)&close},
{6, (void const *)&g_test, (void const *)&atoi, (void const *)&read},
{7, (void const *)&pipe, (void const *)&strcat, (void const *)&memchr},
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
	r[0] = printf("First addr: %p| Second addr: %p| Third addr: %p",
			g_test[i].p0, g_test[i].p1, g_test[i].p2);
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
	r[1] = ft_printf("First addr: %p| Second addr: %p| Third addr: %p",
			g_test[i].p0, g_test[i].p1, g_test[i].p2);
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

int	test_cvrt_p(int const *fd, int *const ret)
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
