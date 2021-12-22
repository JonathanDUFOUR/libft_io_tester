/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_literal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:24:17 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/22 21:20:12 by jodufour         ###   ########.fr       */
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
	int const	num;
	char const	*format;
};

static t_test const		g_test[] = {
{1, ""},
{2, "Hello World"},
{3, "abcdef 0123456789 !@#$^&*()_+"},
{4, "42"},
{5, " koala "},
{6, "lalipop !!"},
{7, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. \
Sed at hendrerit odio. Pellentesque habitant morbi tristique senectus et \
netus et malesuada fames ac turpis egestas. Etiam elit nibh, mollis eu justo \
non, fringilla fringilla massa. Fusce fermentum elementum viverra. In hac \
habitasse platea dictumst. Quisque vehicula hendrerit quam, a imperdiet dui \
dignissim id. Praesent tempor arcu sed mauris volutpat placerat. Morbi quis \
velit euismod, auctor dui at, eleifend nisi.\n\n Duis ac nisl mi. Proin mollis \
nulla eu ligula vestibulum fringilla. Vivamus eget risus magna. Donec vitae \
sapien mattis, ullamcorper nisl non, suscipit felis. Integer nibh dolor, \
cursus quis iaculis id, aliquet quis libero. Nunc ac mi ultrices, volutpat \
lacus eget, aliquet ex. Maecenas condimentum volutpat mauris, lobortis \
efficitur neque scelerisque eu. Nullam sed tempor felis, non volutpat justo. \
Sed lobortis leo felis, vitae porttitor mi ornare in. Sed volutpat dui ut nisl \
porta, vitae dignissim mauris sagittis. Morbi in aliquam eros vel. "},
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

int	test_literal(int const *fd, int *const ret)
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
