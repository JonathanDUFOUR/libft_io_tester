/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putfloat_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:33:00 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 14:55:40 by jodufour         ###   ########.fr       */
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
	float const		nb;
	t_uint const	prec;
	char const		*expect;
};

static t_test const		g_test[] = {
{1, 0.0f, 0, "0"},
{2, 1.0f, 1, "1.0"},
{3, -321.123f, 2, "-321.12"},
{4, 97.42f, 3, "97.419"},
{5, 0.0f / 0.0f, 0, "nan"},
{6, 1.0f / 0.0f, 21, "inf"},
{7, -1.0f / 0.0f, 42, "-inf"},
{8, 4056.1384f, 6, "4056.138427"},
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
	if (ft_putfloat_fd(g_test[i].nb, g_test[i].prec, fd[1]) == -1)
		return (*ret = FT_PUTFLOAT_FD_ERR);
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

int	test_ft_putfloat_fd(int *const ret)
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
