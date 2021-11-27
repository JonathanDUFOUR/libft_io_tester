/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:58:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/27 14:07:14 by jodufour         ###   ########.fr       */
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
	char const	*str;
};

static t_test const		g_test[] = {
{1, ""},
{2, "koala"},
{3, "g"},
{4, "42 est une ecole grandiose !"},
{5, "\t\n\n\t"},
{6, "D0n't w0rry, b3 h4ppy"},
{7, "hKuNa MaTaTa!@#$%^&*()"},
{8, "\x12\x99\xaa"},
{9, "fcuf873t9R%*QYDOHCH*(W@(*bvjb66++"},
{0}
};

static int	test_one(int const i, int const *fd, int *const ret)
{
	char	*buff;
	size_t	len;
	ssize_t	rd;

	len = strlen(g_test[i].str);
	if (ft_putstr_fd(g_test[i].str, fd[1]) == -1)
		return (*ret = FT_PUTSTR_FD_ERR);
	buff = malloc((len + 1) * sizeof(char));
	if (!buff)
		return (*ret = MALLOC_ERR);
	rd = read(fd[0], buff, len);
	if (rd == -1)
	{
		free(buff);
		return (*ret = READ_ERR);
	}
	buff[rd] = 0;
	result(g_test[i].num,
		!strcmp(buff, g_test[i].str));
	free(buff);
	return (*ret = SUCCESS);
}

int	test_ft_putstr_fd(int *const ret)
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
